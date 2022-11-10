#include "pch.h"
#include "../msstdlib/msstdlib.h"

TEST(MSStandardLib_itoa, Zero) {
	char result[2];
	char* expected = msstdlib::itoa(0, result, 2);
	
	EXPECT_EQ(std::string(expected), "0");
}

TEST(MSStandardLib_itoa, SignedZero) {
	char result[2];
	char* expected = msstdlib::itoa(-0, result, sizeof(result));

	EXPECT_EQ(std::string(expected), "0");
}

TEST(MSStandardLib_itoa, Unsigned) {
	char result[4];
	char* expected = msstdlib::itoa(123, result, sizeof(result));

	EXPECT_EQ(std::string(expected), "123");
}

TEST(MSStandardLib_itoa, Signed) {
	char result[5];
	char* expected = msstdlib::itoa(-123, result, sizeof(result));

	EXPECT_EQ(std::string(expected), "-123");
}

TEST(MSStandardLib_itoa, InvalidBase) {
	char result[5];
	char* expected = msstdlib::itoa(0, result, sizeof(result), 37);

	EXPECT_EQ(expected, nullptr);
}

TEST(MSStandardLib_itoa, InvalidSizeBuffer) {
	char result[1];
	char* expected = msstdlib::itoa(12123, result, sizeof(result));

	EXPECT_EQ(expected, nullptr);
}

TEST(MSStandardLib_itoa, InvalidSizeBufferValue) {
	char result[4];
	char* expected = msstdlib::itoa(123, result, 1);

	EXPECT_EQ(expected, nullptr);
}