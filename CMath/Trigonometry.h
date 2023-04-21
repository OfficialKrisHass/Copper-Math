#pragma once

#include <cmath>

#include "Vectors.h"

namespace CMath {

	//Static variables

	inline const double pi = 3.14159265358979323846;

	//Wrappers for the standard lib

	inline float Sin(float f) { return std::sin(f); }
	inline float Cos(float f) { return std::cos(f); }
	inline float Tan(float f) { return std::tan(f); }

	inline double Sin(double f) { return std::sin(f); }
	inline double Cos(double f) { return std::cos(f); }
	inline double Tan(double f) { return std::tan(f); }

	//Conversions

	inline float RadiansToDegrees(float radians) { return radians * 57.2957795f; }
	inline float DegreesToRadians(float degrees) { return degrees * 0.0174532925f; }

	inline double RadiansToDegrees(double radians) { return radians * 57.2957795; }
	inline double DegreesToRadians(double degrees) { return degrees * 0.0174532925; }

	////Vector Versions
	
	//Trigonometry

	template<typename T> inline vec2<T> Sin(const vec2<T>& v) { return vec2<T>(std::sin(v.x), std::sin(v.y)); }
	template<typename T> inline vec2<T> Cos(const vec2<T>& v) { return vec2<T>(std::cos(v.x), std::cos(v.y)); }
	template<typename T> inline vec2<T> Tan(const vec2<T>& v) { return vec2<T>(std::tan(v.x), std::tan(v.y)); }

	template<typename T> inline vec3<T> Sin(const vec3<T>& v) { return vec3<T>(std::sin(v.x), std::sin(v.y), std::sin(v.z)); }
	template<typename T> inline vec3<T> Cos(const vec3<T>& v) { return vec3<T>(std::cos(v.x), std::cos(v.y), std::cos(v.z)); }
	template<typename T> inline vec3<T> Tan(const vec3<T>& v) { return vec3<T>(std::tan(v.x), std::tan(v.y), std::tan(v.z)); }

	template<typename T> inline vec4<T> Sin(const vec4<T>& v) { return vec4<T>(std::sin(v.x), std::sin(v.y), std::sin(v.z), std::sin(v.z)); }
	template<typename T> inline vec4<T> Cos(const vec4<T>& v) { return vec4<T>(std::cos(v.x), std::cos(v.y), std::cos(v.z), std::cos(v.z)); }
	template<typename T> inline vec4<T> Tan(const vec4<T>& v) { return vec4<T>(std::tan(v.x), std::tan(v.y), std::tan(v.z), std::tan(v.z)); }

	//Conversions

	template<typename T> inline vec2<T> RadiansToDegrees(const vec2<T>& v) { return vec2<T>(v.x * T(57.2957795), v.y * T(57.2957795)); }
	template<typename T> inline vec2<T> DegreesToRadians(const vec2<T>& v) { return vec2<T>(v.x * T(0.0174532925), v.y * T(0.0174532925)); }

	template<typename T> inline vec3<T> RadiansToDegrees(const vec3<T>& v) { return vec3<T>(v.x * T(57.2957795), v.y * T(57.2957795), v.z * T(57.2957795)); }
	template<typename T> inline vec3<T> DegreesToRadians(const vec3<T>& v) { return vec3<T>(v.x * T(0.0174532925), v.y * T(0.0174532925), v.z * T(0.0174532925)); }

	template<typename T> inline vec4<T> RadiansToDegrees(const vec4<T>& v) { return vec4<T>(v.x * T(57.2957795), v.y * T(57.2957795), v.z * T(57.2957795), v.w * T(57.2957795)); }
	template<typename T> inline vec4<T> DegreesToRadians(const vec4<T>& v) { return vec4<T>(v.x * T(0.0174532925), v.y * T(0.0174532925), v.z * T(0.0174532925), v.w * T(0.0174532925)); }


}