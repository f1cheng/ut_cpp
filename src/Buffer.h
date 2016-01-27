#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <map>

#include "FileStorage.h"

class Buffer
{
public:
    Buffer()
    {
        _store = NULL;
    }
    
    void add(std::string key, std::string value);
    std::string getValue(std::string key);
    void dumpData();
    void loadData();
    void registerStorage(Storage *storage);
    
private:
    Storage *_store;
    std::map<std::string, std::string> _table;

};

#endif
