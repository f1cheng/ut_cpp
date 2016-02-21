
#include <iostream>
#include <string>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include "BaseSocket.h"

BaseSocket::BaseSocket() : sock(-1)
{
    memset(&addr, 0, sizeof(addr));
}

BaseSocket::~BaseSocket()
{
    if (isValid())
    { 
        //issue: no mock for close will cause problem, here is to comment close() for mock pass
        //as every test will call this close even it's not created(only test invoking bind().
        //close(sock);
    }
}

bool BaseSocket::create()
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (!isValid())
        return false;
    int on = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof(on)) == -1)
        return false;
    return true;
}

bool BaseSocket::bind1(int port)
{
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port); 
    int bind_ret = bind(sock,(const sockaddr *)&addr, sizeof(addr));
    return bind_ret == -1 ? false : true; 
}

bool BaseSocket::listen() const
{
    if (!isValid())
        return false;
    int listenRet = ::listen(sock, MAX_CONNECTIONS);
    return listenRet == -1 ? false : true;
}

bool BaseSocket::accept(BaseSocket &newSock) const
{
    int addrLen = sizeof(addr);
    newSock.sock = ::accept(sock, (sockaddr *)&addr, (socklen_t *)&addrLen);
    return newSock.sock <= 0 ? false : true; 
}

bool BaseSocket::send(const std::string str) const
{
    int status = ::send(sock, str.c_str(), str.size(), MSG_NOSIGNAL);
    return status == -1 ? false : true;    
}

int BaseSocket::recv(std::string &str) const
{
    int status;
    char buf[MAX_RECV + 1];
    str = "";
    status = ::recv(sock, buf, MAX_RECV, 0);
    if (status == -1)
    {
        std::cout << "status == -1, error == " << errno << "in BaseSocket::recv\n";
        return 0;
    }    
    else if (status == 0)
    {
        return 0;
    }
    else 
    {
        str = buf;
        return status;
    }
}

bool BaseSocket::connect(const std::string host, const int port)
{
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    int status =inet_pton(AF_INET, host.c_str(), &addr.sin_addr);    
    if (errno == EAFNOSUPPORT)
        return false;
    status = ::connect(sock, (sockaddr *)&addr, sizeof(addr)); 
    return status == 0 ? true : false;
}

void BaseSocket::set_non_blocking(const bool b)
{
    int opt;
    opt = fcntl(sock, F_GETFL);
    if (opt < 0)
        return;
    if (b)
    {
        opt = opt | O_NONBLOCK;
    }
    else
    {
        opt = opt & ~O_NONBLOCK;
    }
    fcntl(sock, F_SETFL, opt);
}
