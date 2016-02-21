#include <iostream>
#include "ServerSocket.h"


ServerSocket::ServerSocket(int port)
{
    if (!create())
    {
        std::cout << "create socket fail" << std::endl;
        return;
    }
    
    if (!bind1(port))
    {
        std::cout << "could not bind to  port" << std::endl;
        return;
    }
    if (!listen())
    {
        std::cout << "could not listen to socket" << std::endl;
        return;
    }
}

ServerSocket::~ServerSocket()
{
   
}

const ServerSocket& ServerSocket::operator << (const std::string str) const
{
    if (!send(str))
    {
        std::cout << "could write to socket" << std::endl;
        //throw Exception("x");
    }
    return *this;
}

const ServerSocket& ServerSocket::operator >> (std::string &str) const
{
    if (!recv(str))
    {
        std::cout << "could not read from socket" << std::endl;
    }
    return *this;
}

void ServerSocket::accept(ServerSocket &serSock)
{
    if (!BaseSocket::accept(serSock))
    {
        std::cout << "could not accept socket" << std::endl;
    }
}

