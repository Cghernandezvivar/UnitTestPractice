/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

//*The TEST macro defines a standalone test case without relying on a test fixture.
////*PasswordTest is the name of the test suite, grouping related tests.
////*single_letter_password is the name of this specific test case.

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, Mixed_Case_SingleUpperAndLower)
{
	Password my_password;
	bool has_mixed_upper = my_password.has_mixed_case("Z");
	ASSERT_FALSE(has_mixed_upper) << "String 'Z' should not be mixed case.";

	bool has_mixed_lower = my_password.has_mixed_case("z");
	ASSERT_FALSE(has_mixed_lower) << "String 'z' should not be mixed case.";

	bool has_mixed_valid = my_password.has_mixed_case("Zz");
	ASSERT_TRUE(has_mixed_valid) << "String 'Zz' should be mixed case.";
}

TEST(PasswordTest, Multiple_Same_Characters)
{
	Password my_password; // instance of the Password class.
	int actual = my_password.count_leading_characters("AAAAxyz"); // call the method with the string "AAAAxyz".
	ASSERT_EQ(4, actual); // declare that the output is as expected ( 4 leading 'A' characters).
}
TEST(PasswordTest, No_Repetition)
{
	        Password my_password;
	        int actual = my_password.count_leading_characters("ABCD");
		ASSERT_EQ(1, actual);
}
TEST(PasswordTest, Special_Characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("###!!");
	ASSERT_EQ(3, actual);
}
TEST(PasswordTest, All_Upper_Case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("UPPERCASE");
	ASSERT_FALSE(actual);
}
TEST(PasswordTest, All_Lower_Case)
{
	Password my_password;
        bool actual = my_password.has_mixed_case("lowercase");					        	ASSERT_FALSE(actual);
}
TEST(PasswordTest, Valid_Mixed_Case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Password123");
	ASSERT_TRUE(actual);
}
TEST(PasswordTest, Empty_String)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}
TEST(PasswordTest, Single_Character_Lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("a");
	ASSERT_FALSE(actual);
}
TEST(PasswordTest, Single_Character_Upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Z");
	ASSERT_FALSE(actual);
}
TEST(PasswordTest, Number_Special_Characters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("12345!@#$%");
	ASSERT_FALSE(actual);
}
