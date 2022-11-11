#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

namespace msstdlib {

	enum ItoaResult {
		Success = 0,
		InvalidSize = -1,
	};

	enum ItoaBase {
		Binary = 2,
		Octal = 8,
		Decimal = 10,
		Hexidecimal = 16,
	};

	ItoaResult itoa(
		const int& input,
		char* result,
		const size_t& size,
		const ItoaBase& base = ItoaBase::Decimal
	);
}