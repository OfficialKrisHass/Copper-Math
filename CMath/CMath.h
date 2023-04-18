#pragma once

#include "Trigonometry.h"

#include <stdint.h>

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

	inline void SetRandomSeed(uint32_t seed = 2'147'483'647) {

		if (seed == 2'147'483'647) seed = time(nullptr);
		srand(seed);

	}

	inline int RandomInt(int min = 0, int max = 10) { return min + (rand() % (max - min + 1)); }
	inline float RandomFloat(float min = 0.0f, float max = 1.0f) { return min + (float) rand() / ((float) RAND_MAX / max); }
	inline double RandomDouble(double min = 0.0f, double max = 1.0f) { return min + (double) rand() / (RAND_MAX / max); }

}