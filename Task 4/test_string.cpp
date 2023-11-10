#include <cstring>
#include <iostream>
#include "my_string.h"
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
/* Testing constructor with cstring */
TEST(MyStringTest, ConstructorWithString) {
    const char* data = "Hello World";
    my_string str(data);

    EXPECT_EQ(str.get_count(), 1);
    str.print();
}
// Test copy constructor
TEST(MyStringTest, CopyConstructorTest) {
    my_string original("Hello World");
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
// Test getChar method
TEST(MyStringTest, GetCharTest) {
    my_string str("Hello");
    char firstChar = str.getChar(0);
    EXPECT_EQ(firstChar, 'H');
}
// Test print() fucntion
TEST(MyStringTest, printTest){
    my_string str;
    // Caputure clo
    std::stringstream buffer;
    std::streambuf* old_stdout = std::cout.rdbuf(buffer.rdbuf());
    // Call print
    str.print();
    // reset output
    std::cout.rdbuf(old_stdout);
    // Get output
    std::string output = buffer.str();
    EXPECT_EQ(output, "(Empty String)\n");
}
// Testing count for block scope
TEST(MyStringTest, ChainOperations) {
    const char* data = "Hello World";
    my_string str1(data);

    {
        my_string str2(str1);
        EXPECT_EQ(str1.get_count(), 2);
        EXPECT_EQ(str2.get_count(), 2);

        {
            my_string str3 = str2;
            EXPECT_EQ(str1.get_count(), 3);
            EXPECT_EQ(str2.get_count(), 3);
            EXPECT_EQ(str3.get_count(), 3);
        }

        EXPECT_EQ(str1.get_count(), 2);
        EXPECT_EQ(str2.get_count(), 2);
    }

    EXPECT_EQ(str1.get_count(), 1);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
