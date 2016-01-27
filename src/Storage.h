
#ifndef _STORAGE_H_
#define _STORAGE_H_

#include <cstring>

class Storage
{

public:
    Storage(){}
    
    virtual int open() = 0;
    virtual void close() = 0;
    virtual bool read(std::string &key, std::string &value) = 0;
    virtual void write(std::string key, std::string value) = 0;
    virtual void flush() = 0;
    virtual bool isOpen() = 0;
    
};

#endif
