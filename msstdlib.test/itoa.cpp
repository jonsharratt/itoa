#include "pch.h"
#include "../msstdlib/msstdlib.h"

TEST(MSStandardLib_itoa, Zero) {
	char buffer[sizeof(int) * CHAR_BIT + 1];
	char* expected = msstdlib::itoa(0, buffer);

	EXPECT_EQ(std::string(expected), "0");
}

TEST(MSStandardLib_itoa, SignedZero) {
	char buffer[sizeof(int) * CHAR_BIT + 1];
	char* expected = msstdlib::itoa(-0, buffer);

	EXPECT_EQ(std::string(expected), "0");
}

TEST(MSStandardLib_itoa, Unsigned) {
	char buffer[sizeof(int) * CHAR_BIT + 1];
	char* expected = msstdlib::itoa(123, buffer);

	EXPECT_EQ(std::string(expected), "123");
}

TEST(MSStandardLib_itoa, Signed) {
	char buffer[sizeof(int) * CHAR_BIT + 1];
	char* expected = msstdlib::itoa(-123, buffer);

	EXPECT_EQ(std::string(expected), "-123");
}