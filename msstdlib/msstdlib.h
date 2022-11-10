#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

namespace msstdlib {
	char* itoa(int input, char* result, const unsigned int& size, const unsigned int& base = 10);
}