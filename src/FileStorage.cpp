#include <iostream>

#include "FileStorage.h"

int FileStorage::open()
{
    _file.open(_fileName.c_str(), std::ios::in | std::ios::out | std::ios::app);
    return 1;
}

void FileStorage::close()
{
    _file.close();
}

bool FileStorage::read(std::string &a, std::string &b)
{
    if (_file >>a >>b)
    {
        return true;
    }
    return false;
}

void FileStorage::write(std::string a, std::string b)
{
    _file << a << " " << b << std::endl;
}

void FileStorage::flush()
{
    _file.seekg(0, std::ios::beg);
}

bool FileStorage::isOpen()
{
    return _file.is_open();
}
