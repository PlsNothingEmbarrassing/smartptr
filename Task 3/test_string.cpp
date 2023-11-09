#include <cstring>
#include <iostream>
#include "my_string.hpp"
#include <gtest/gtest.h>

// Test constructor
TEST(MyStringTest, ConstructorTest) {
    my_string str("Hello World");    
    EXPECT_EQ(str.getChar(0), 'H');
    EXPECT_EQ(str.get_count(), 1);
}
// Test default constructor for count = 0
TEST(MyStringTest, DefConstructorTest) {
    my_string str;    
    EXPECT_EQ(str.getChar(0), '\0');
    EXPECT_EQ(str.get_count(), 0);
}

// Test copy constructor
TEST(MyStringTest, CopyConstructorTest) {
    my_string original("Hello, World");
    my_string copy(original);
    EXPECT_EQ(copy.getChar(0), 'H');
    EXPECT_EQ(copy.get_count(), 2);
}

// Test assignment operator
TEST(MyStringTest, AssignmentOperatorTest) {
    my_string str1("Hello");
    my_string str2("World");
    str2 = str1;
    EXPECT_EQ(str2.getChar(0), 'H');
    EXPECT_EQ(str2.get_count(), 2);
}

// Test setChar method
TEST(MyStringTest, SetCharTest) {
    my_string str("Hello");
    str.setChar(1, 'i');
    EXPECT_EQ(str.getChar(1), 'i');
}
