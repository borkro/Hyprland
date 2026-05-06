#include <debug/crash/SignalSafe.hpp>

#include <gtest/gtest.h>

TEST(Crash, signalsafeWriteNum) {
    SignalSafe::CMaxLengthCString<2> s1;
    s1.writeNum(0);
    EXPECT_STREQ(s1.getStr(), "0");
    
    SignalSafe::CMaxLengthCString<2> s2;
    s2.writeNum(5);
    EXPECT_STREQ(s2.getStr(), "5");

    SignalSafe::CMaxLengthCString<4> s3;
    s3.writeNum(100);
    EXPECT_STREQ(s3.getStr(), "100");

    SignalSafe::CMaxLengthCString<12> s4, s5;
    s4.write("Hello World", 11);
    s5.write('H');
    s5.write('e');
    s5.write('l');
    s5.write('l');
    s5.write('o');
    s5.write(' ');
    s5.write('W');
    s5.write('o');
    s5.write('r');
    s5.write('l');
    s5.write('d');
    EXPECT_STREQ(s4.getStr(), s5.getStr());
    EXPECT_STREQ(s4.getStr(), "Hello World");
}
