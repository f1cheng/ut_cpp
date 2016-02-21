
#ifndef _SERVERSOCKET_
#define _SERVERSOCKET_

#include "BaseSocket.h"

class ServerSocket : private BaseSocket
{
public:
    ServerSocket(int port);
    ServerSocket() {};
    virtual ~ServerSocket();
    const ServerSocket& operator << (const std::string) const;
    const ServerSocket& operator >> (std::string&) const;
    void accept(ServerSocket &);
    void parse_cmd(ServerSocket &);
private:
    int _servSocket;
};


#endif
