#include "pch.h"
#include "../msstdlib/msstdlib.h"
#include <stdio.h>
#include <stdlib.h>

TEST(MSStandardLib_itoa, DecimalZero) {
	char buffer[2];
	msstdlib::ItoaResult result = msstdlib::itoa(0, buffer, sizeof(buffer));

	EXPECT_EQ(result, msstdlib::ItoaResult::Success);
	EXPECT_EQ(std::string(buffer), "0");
}

TEST(MSStandardLib_itoa, DecimalSignedZero) {
	char buffer[2];
	msstdlib::ItoaResult result = msstdlib::itoa(-0, buffer, sizeof(buffer));

	EXPECT_EQ(result, msstdlib::ItoaResult::Success);
	EXPECT_EQ(std::string(buffer), "0");
}
TEST(MSStandardLib_itoa, DecimalUnsigned) {
	char buffer[4];
	int result = msstdlib::itoa(123, buffer, sizeof(buffer));

	EXPECT_EQ(result, msstdlib::ItoaResult::Success);
	EXPECT_EQ(std::string(buffer), "123");
}

TEST(MSStandardLib_itoa, DecimalSigned) {
	char buffer[5];
	int result = msstdlib::itoa(-123, buffer, sizeof(buffer));

	EXPECT_EQ(result, msstdlib::ItoaResult::Success);
	EXPECT_EQ(std::string(buffer), "-123");
}

TEST(MSStandardLib_itoa, BinarySigned) {
	char buffer[9];
	int result = msstdlib::itoa(-123, buffer, sizeof(buffer), msstdlib::ItoaBase::Binary);

	EXPECT_EQ(result, msstdlib::ItoaResult::Success);
	EXPECT_EQ(std::string(buffer), "-1111011");
}

TEST(MSStandardLib_itoa, BinaryUnsigned) {
	char buffer[8];
	int result = msstdlib::itoa(123, buffer, sizeof(buffer), msstdlib::ItoaBase::Binary);

	EXPECT_EQ(result, msstdlib::ItoaResult::Success);
	EXPECT_EQ(std::string(buffer), "1111011");
}

TEST(MSStandardLib_itoa, HexidecimalSigned) {
	char buffer[4];
	int result = msstdlib::itoa(-123, buffer, sizeof(buffer), msstdlib::ItoaBase::Hexidecimal);

	EXPECT_EQ(result, msstdlib::ItoaResult::Success);
	EXPECT_EQ(std::string(buffer), "-7B");
}

TEST(MSStandardLib_itoa, HexidecimalUnsigned) {
	char buffer[3];
	int result = msstdlib::itoa(123, buffer, sizeof(buffer), msstdlib::ItoaBase::Hexidecimal);

	EXPECT_EQ(result, msstdlib::ItoaResult::Success);
	EXPECT_EQ(std::string(buffer), "7B");
}

TEST(MSStandardLib_itoa, OctalSigned) {
	char buffer[5];
	int result = msstdlib::itoa(-123, buffer, sizeof(buffer), msstdlib::ItoaBase::Octal);

	EXPECT_EQ(result, msstdlib::ItoaResult::Success);
	EXPECT_EQ(std::string(buffer), "-173");
}

TEST(MSStandardLib_itoa, OctalUnsigned) {
	char buffer[4];
	int result = msstdlib::itoa(123, buffer, sizeof(buffer), msstdlib::ItoaBase::Octal);

	EXPECT_EQ(result, msstdlib::ItoaResult::Success);
	EXPECT_EQ(std::string(buffer), "173");
}

TEST(MSStandardLib_itoa, InvalidSizeError) {
	char buffer[1];
	int result = msstdlib::itoa(123, buffer, sizeof(buffer));

	EXPECT_EQ(result, msstdlib::ItoaResult::InvalidSize);
}