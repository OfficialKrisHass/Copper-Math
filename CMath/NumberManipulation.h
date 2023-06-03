#pragma once

#include "Vectors.h"

#define MinImpl(type) inline type Min(type a, type b) { return (a > b) ? b : a; }
#define MaxImpl(type) inline type Max(type a, type b) { return (a > b) ? a : b; }

namespace CMATH_NAMESPACE {

	MinImpl(int32_t)
	MinImpl(float)
	MinImpl(double)

	MaxImpl(int32_t)
	MaxImpl(float)
	MaxImpl(double)

	//Rounding
	inline int32_t RoundNearest(float num) { return (int32_t) roundf(num); }
	inline int32_t RoundNearest(double num) { return (int32_t) round(num); }

	inline int32_t RoundSmallest(float num) { return (int32_t) num; }
	inline int32_t RoundSmallest(double num) { return (int32_t) num; }

	//Clamping
	inline int32_t Clamp(int32_t value, int32_t min, int32_t max) { return Min(Max(value, min), max); }
	inline float Clamp(float value, float min, float max) { return Min(Max(value, min), max); }
	inline double Clamp(double value, double min, double max) { return Min(Max(value, min), max); }

	//Vector versions
	template<typename T> vec<2, int32_t> RoundNearest(const vec<2, T>& v) { return vec<2, int32_t>(RoundNearest(v.x), RoundNearest(v.y)); }
	template<typename T> vec<3, int32_t> RoundNearest(const vec<3, T>& v) { return vec<3, int32_t>(RoundNearest(v.x), RoundNearest(v.y), RoundNearest(v.z)); }
	template<typename T> vec<4, int32_t> RoundNearest(const vec<4, T>& v) { return vec<4, int32_t>(RoundNearest(v.x), RoundNearest(v.y), RoundNearest(v.z), RoundNearest(v.y)); }

	template<typename T> vec<2, int32_t> RoundSmallest(const vec<2, T>& v) { return vec<2, int32_t>((int32_t) v.x, (int32_t) v.y); }
	template<typename T> vec<3, int32_t> RoundSmallest(const vec<3, T>& v) { return vec<3, int32_t>((int32_t) v.x, (int32_t) v.y, (int32_t) v.z); }
	template<typename T> vec<4, int32_t> RoundSmallest(const vec<4, T>& v) { return vec<4, int32_t>((int32_t) v.x, (int32_t) v.y, (int32_t) v.z, (int32_t) v.w); }

}