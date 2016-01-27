#ifndef _FILE_STORAGE_
#define _FILE_STORAGE_

#include <string>
#include <fstream>
#include <iostream>

#include "Storage.h"

class FileStorage : public Storage
{
public:
    FileStorage(std::string str): _fileName(str) {}
    ~FileStorage()
    {
        close();
    }
    int open();
    void close();
    bool read(std::string &a, std::string &b);
    void write(std::string a, std::string b);
    void flush();
    bool isOpen();
     
private:
    std::string _fileName;
    std::fstream _file;
};

#endif
