
#include "FileStorage.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(FileStorage_test, open_close)
{
    FileStorage fs("test_file.txt");
    bool ret = fs.open();
    EXPECT_EQ(true , ret); 
    fs.close();
    EXPECT_EQ(false, fs.isOpen());
     
}

TEST(FileStorage_test, write_read)
{
    FileStorage fs("test_file.txt");
    fs.open();
    std::string expectKey = "write_key";
    std::string expectValue = "write_Value";

    fs.write(expectKey, expectValue);
    bool isOpen = fs.isOpen();
    EXPECT_EQ(true, isOpen);
    //fs.open();
    fs.flush();
    std::string key, value;
    bool ret = fs.read(key, value);
    EXPECT_EQ(true, ret);
    EXPECT_EQ(expectKey, key);
    EXPECT_EQ(expectValue, value);
     
}
