#include "msstdlib.h"
#include <cmath>
#include <cstring>

namespace msstdlib {
	// Storage size of buffer for a valid integer string
	// + 2 to include signed integers and null termination.
	#define ITOA_BUFFER_SIZE (sizeof(int) * CHAR_BIT + 2)

	// Save on previous addition operation and create lookup table
	// for values instead.
	#define ITOA_CHAR_LOOKUP "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

	/*
	 * Converts integer value to a null-terminated string.
	 *
	 * @input value to be converted to a ASCII.
	 * @buffer to store the resulting conversion.
	 * @size of buffer to storing string.
	 * @base supported number system enum to use when converting. Defaults to Decimal.
	 * @return result code for operation.
	*/
	msstdlib::ItoaResult itoa(
		const int& input,
		char* buffer,
		const size_t& size,
		const msstdlib::ItoaBase& base
	)
	{
		// Internal buffer to do work
		// and guard against size of provided buffer.
		char b[ITOA_BUFFER_SIZE];

		// Get pointer to end of buffer.
		char* pBuffer = &b[sizeof(b) - 1];

		// Ensure using positive integer
		int posInput = input < 0 ? posInput = -input : input;

		// Always end with null terminated string.
		*pBuffer = '\0';

 		do {
			// Set converted ascii character for integer
			// using lookup table.
 			*(--pBuffer) = ITOA_CHAR_LOOKUP[posInput % base];

			// Remove last number.
			posInput = posInput / base;
 		} while (posInput);

		// If negative number
		// add '-' character
		if (input < 0)
		{
			*(--pBuffer) = '-';
		}

		// Get length of resulting used buffer.
		size_t usedSize = &b[sizeof(b)] - pBuffer;

		// Validate we have enough room
		// to store result.
 		if (usedSize > size) {
			return msstdlib::ItoaResult::InvalidSize;
 		}

		// Copy relevant data into resulting
		// buffer with size used.
		std::memcpy(buffer, pBuffer, usedSize);

		return msstdlib::ItoaResult::Success;
	}
}