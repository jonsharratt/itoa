#include "msstdlib.h"
#include <cmath>
#include <cstring>

// Storage size of buffer for a valid integer string
// + 2 to include signed integers and null termination.
#define ITOA_BUFFER_SIZE (sizeof(int) * CHAR_BIT + 2)

namespace msstdlib {
	/*
	 * Converts default base 10 integer value to a null-terminated string.
	 *
	 * @input value to be converted to a string.
	 * @result buffer to store the resulting conversion.
	 * @size of buffer to store string.
	 * @base number system to use when converting.
	 * @return a pointer to the resulting null-terminated string (same as @buffer).
	*/
	char* itoa(
		int input,
		char* result,
		const unsigned int& size,
		const unsigned int& base
	)
	{
		// Validation for valid number system.
		// (base > 36 || size == 0)
		// 
		// TODO: Support additional number systems.
		//
		if (base != 10 || size == 0) {
			return nullptr;
		}

		// Internal buffer to do work
		// and guard against size of provided buffer.
		char buffer[ITOA_BUFFER_SIZE];

		// Get pointer to buffer.
		char* pBuffer = &buffer[sizeof(buffer) - 1];

		bool signedNum = false;

		if (input < 0) {
			signedNum = true;
			input = -input;
		}

		// Always end with null terminated string.
		*pBuffer = '\0';

 		do {
			// Dereference and set converted
			// ascii character for integer.
 			*(--pBuffer) = input % base + '0';

			// Remove last number.
			input = input / base;
 		} while (input);

		// Add sign if needed.
		if (signedNum) {
			*(--pBuffer) = '-';
		}

		// Get length of resulting used buffer.
		size_t length = &buffer[sizeof(buffer)] - pBuffer;

		// Validate we have enough room
		// to store result.
 		if (length > size) {
 			return nullptr;
 		}

		// Copy relevant data into resulting
		// buffer based on size used.
		std::memcpy(result, pBuffer, size);

		return result;
	}
}