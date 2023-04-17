#pragma once

#include <cmath>

namespace CMath {

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

}