/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, just_lower){
	Password my_password;
	int actual = my_password.has_mixed_case("aaa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, just_upper){
	Password my_password;
	int actual = my_password.has_mixed_case("AAA");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, true_mixed){
	Password my_password;
	int actual = my_password.has_mixed_case("aAa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_new_order){
	Password my_password;
	int actual = my_password.has_mixed_case("AaA");
	ASSERT_EQ(true, actual);
}