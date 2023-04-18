#pragma once

#define MinImpl(type) inline type Min(type a, type b) { return (a > b) ? b : a; }
#define MaxImpl(type) inline type Max(type a, type b) { return (a > b) ? a : b; }

namespace CMath {

	MinImpl(int)
	MinImpl(float)
	MinImpl(double)

	MaxImpl(int)
	MaxImpl(float)
	MaxImpl(double)

	inline int32_t RoundNearest(float num) { return (int32_t) roundf(num); }
	inline int32_t RoundNearest(double num) { return (int32_t) round(num); }

	inline int32_t RoundSmallest(float num) { return (int32_t) num; }
	inline int32_t RoundSmallest(double num) { return (int32_t) num; }

}