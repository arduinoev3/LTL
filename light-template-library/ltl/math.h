#pragma once

#ifndef MATH_LTD
#define MATH_LTD

namespace ltd {
	typedef int32_t   i32;
	typedef uint32_t  u32;
	typedef int8_t    sign_t;
	const u32 SHIFT = 31;

	sign_t sign(i32 a) {
		return (a >> SHIFT) | ((u32)(-a) >> SHIFT);
	}

	u32 abs_math(i32 a) {
		const i32 b = a >> SHIFT;
		return (a + b) ^ b;
	}

	i32 min(i32 a, i32 b) {
		return a < b ? a : b;
	}
	i32 max(i32 a, i32 b) {
		return a > b ? a : b;
	}

	u32 min_unsigned(u32 a, u32 b) {
		return a > b ? b : a;
	}
	u32 max_unsigned(u32 a, u32 b) {
		return a < b ? b : a;
	}
}

#endif // MATH_LTD