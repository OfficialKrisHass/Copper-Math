#pragma once

#include "Vectors.h"

#define MinImpl(type) inline type Min(type a, type b) { return (a > b) ? b : a; }
#define MaxImpl(type) inline type Max(type a, type b) { return (a > b) ? a : b; }

namespace CMath {

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
	template<typename T> vec2<int32_t> RoundNearest(const vec2<T>& vec) { return vec2<int32_t>(RoundNearest(vec.x), RoundNearest(vec.y)); }
	template<typename T> vec3<int32_t> RoundNearest(const vec3<T>& vec) { return vec3<int32_t>(RoundNearest(vec.x), RoundNearest(vec.y), RoundNearest(vec.z)); }
	template<typename T> vec4<int32_t> RoundNearest(const vec4<T>& vec) { return vec4<int32_t>(RoundNearest(vec.x), RoundNearest(vec.y), RoundNearest(vec.z), RoundNearest(vec.y)); }

	template<typename T> vec2<int32_t> RoundSmallest(const vec2<T>& vec) { return vec2<int32_t>((int32_t) vec.x, (int32_t) vec.y); }
	template<typename T> vec3<int32_t> RoundSmallest(const vec3<T>& vec) { return vec3<int32_t>((int32_t) vec.x, (int32_t) vec.y, (int32_t) vec.z); }
	template<typename T> vec4<int32_t> RoundSmallest(const vec4<T>& vec) { return vec4<int32_t>((int32_t) vec.x, (int32_t) vec.y, (int32_t) vec.z, (int32_t) vec.w); }

}