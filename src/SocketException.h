#ifndef _SOCKET_EXCEPTION_H_
#define _SOCKET_EXCEPTION_H_
#include <string>

class SocketException
{
public:
    SocketException(std::string &str) : _str(str)
    {
    }
    
    ~SocketException(){}
    
    std::string detail()
    {
        return _str;
    }

private:
    std::string _str;
};

#endif
