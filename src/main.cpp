
#include "ServerSocket.h"
#include "SignalInterrupt.h"
#include "FileStorage.h"
#include "Buffer.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum op_code_t 
{
    SET,
    GET,
    SAVE,
    INVALID
};

op_code_t got_command(std::string const &str)
{
    if (str == "GET")
        return GET;
    if (str == "SET")
        return SET;
    if (str == "SAVE")
        return SAVE;
    return INVALID;
}

Buffer buffer;

#ifdef __UT__
int main_func(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    if (argc != 2)
    {
        std::cout << "Usage ./server dbFileName\n";
        return -1;
    }

    FileStorage db(static_cast<std::string>(argv[1]));
    buffer.registerStorage(&db);
    

    registerSig();

    std::cout << "Server starting on port 18000\n";
    ServerSocket server(18000);
    while (true)
    {
        ServerSocket serverSock;
        std::cout << "before accept\n";
        server.accept(serverSock);
        std::cout << "after accept\n";
        while (true)
        {
            std::string input;
            serverSock >> input;
            std::cout << "received: " << input << "\n";
            std::string key, value;
            std::string result;
            input.erase(input.size() - 2);
            std::vector<std::string> token;
            std::fill(token.begin(), token.end(), "");
            std::stringstream ss(input);
            std::string s;
            while (getline(ss, s, ' '))
            {
                token.push_back(s);
            }

            switch(got_command(token[0]))
            {
                case GET:
                    if (2 != token.size())
                        goto invalid;
                    key = token[1];
                    result = buffer.getValue(key);
                    serverSock <<"xx\n";
                    serverSock << result << "\n";
                    break;
                case SET:
                    if (3 != token.size())
                        goto invalid;
                    key = token[1];
                    value = token[2];
                    buffer.add(key, value);
                    serverSock << "+OK\n";
                    break;
                case SAVE:
                    if (token.size() != 1)
                        goto invalid;
                    buffer.dumpData();
                    serverSock << "+OK\n";
                    break;
invalid:
                default:
                    serverSock << "-INVALID\n";
                    break;
            }
             
        }
    } 

}


