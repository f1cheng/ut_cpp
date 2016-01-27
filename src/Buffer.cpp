
#include "Buffer.h"

void Buffer::add(std::string key, std::string value)
{
    _table[key] = value;
}

std::string Buffer::getValue(std::string key)
{
    std::string result = "";
    if (_table.count(key) > 0)
    {
        result = _table[key];
    }   
    return result; 
}

void Buffer::registerStorage(Storage *storage)
{
    _store = storage;
}

void Buffer::dumpData()
{
    _store->open();
    std::map<std::string, std::string>::iterator it;
    for (it = _table.begin(); it != _table.end(); ++it)
    {
        std::string key, value;
        key = it->first;
        value = it->second;
        _store->write(key, value);
    }
    _store->close();

}

void Buffer::loadData()
{
    _store->open();
    std::string key, value;
    while (_store->read(key, value))
    {
        _table[key] = value;
    }
    _store->close();    
}

