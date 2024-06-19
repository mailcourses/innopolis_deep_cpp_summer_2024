#include <iostream>
#include "gtest/gtest.h"

#include "lib1.hpp"
#include "lib2.hpp"

class TestFoo : public ::testing::Test
{
protected:
    void SetUp()
    {
        std::cout << "SetUp" << std::endl;
    }
    void TearDown()
    {
        std::cout << "TearDown" << std::endl;
    }
    //fake::Fake foo;
    // MockObject
};

TEST_F(TestFoo, test_square)
{
    ASSERT_EQ(4, square(2));
    ASSERT_EQ(25, square(5));
}

TEST_F(TestFoo, test_pow)
{
    ASSERT_EQ(32, pow(2, 5));
    ASSERT_EQ(1, pow(2, 0));
    ASSERT_EQ(3, pow(3, 1));
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
