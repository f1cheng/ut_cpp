
#include "Buffer.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(Buffer_test, add_get)
{
    Buffer buff;
    std::string expectKey = "key1", expectValue = "val1";
    buff.add(expectKey, expectValue);
    EXPECT_STREQ(expectValue.c_str(), buff.getValue(expectKey).c_str());
}

TEST(Buffer_test, dump_and_load)
{
    FileStorage store("test2.txt");
    Buffer buff;
    buff.add("k1", "v1");
    buff.add("k2", "v2");
    buff.registerStorage(&store);
    buff.dumpData();
    buff.loadData();
    EXPECT_STREQ("v1", buff.getValue("k1").c_str());
    EXPECT_STREQ("v2", buff.getValue("k2").c_str()); 
}
