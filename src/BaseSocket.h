
#ifndef _BASE_SOCKET_
#define _BASE_SOCKET_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

const int MAX_HOSTNAME = 200;
const int MAX_CONNECTIONS = 5;
const int MAX_RECV = 500;

class BaseSocket
{
public:
    BaseSocket();
    virtual ~BaseSocket();
    bool create();
    bool bind1(int port);
    bool listen() const;
    bool accept(BaseSocket &sock) const;
    bool connect(const std::string host, const int port);
    bool send(const std::string) const;
    int recv(std::string &str) const;
    void set_non_blocking(const bool);
    bool isValid() const
    {
        return sock != -1;
    }
private:
    int sock;
    sockaddr_in addr;
};

#endif
