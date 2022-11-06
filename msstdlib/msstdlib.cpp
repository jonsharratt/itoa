#include "msstdlib.h"
#include <algorithm>

namespace msstdlib {
	namespace defaults
	{
		// unsigned const as always positive when
		// dealing with base number systems.
		//
		// 10 Decimal
		// 16 Hexadecimal
		// 8 Octal
		// 2 Binary
		const unsigned int BASE = 10;
	}

	/**
	 * Converts a base 10 integer value to a null-terminated string.
	 *
	 * @input value to be converted to a string
	 * @buffer array in memory where to store the resulting null-terminated string.
	 * @return a pointer to the resulting null-terminated string (same as @buffer).
	*/
	char* itoa(int input, char* buffer)
	{
		bool isSigned = false;
		int position = 0;

		// Handle zero else
		// as we process != 0
		// in our while loop.
		if (input == 0)
		{
			buffer[position++] = '0';
		}

		if (input < 0)
		{
			// Dealing with a signed
			// negative number.
			isSigned = true;

			// Ensure we convert to positive
			// for next operation.
			input = -input;
		}

		// Move through right to left
		// of the integer provided.
		while (input != 0)
		{
			// In a base of 10
			// being in decimal number system.
			int remainder = input % msstdlib::defaults::BASE;

			// Adding to '0' (48) to convert to ASCII
			// character representation as numbers start from 48.
			buffer[position++] = remainder + '0';

			// Dividing by base
			// to remaining number.
			input = input / msstdlib::defaults::BASE;
		}

		// If we are signed
		// ensure we have "-" char (45). 
		if (isSigned)
		{
			buffer[position++] = '-';
		}

		// null terminate the string built.
		buffer[position] = '\0';

		// Reverse as we were processing right to left
		// re-use the string length from already incremented
		// index value.
		for (size_t index = 0; index < position / 2; index++)
		{
			std::swap(buffer[index], buffer[position - index - 1]);
		}

		return buffer;
	}
}