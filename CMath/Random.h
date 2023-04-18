#pragma once

#include <stdint.h>

namespace CMath {

	inline void SetRandomSeed(uint32_t seed = 2'147'483'647) {

		if (seed == 2'147'483'647) seed = time(nullptr);
		srand(seed);

	}

	inline int RandomInt(int min = 0, int max = 10) { return min + (rand() % (max - min + 1)); }
	inline float RandomFloat(float min = 0.0f, float max = 1.0f) { return min + (float) rand() / ((float) RAND_MAX / max); }
	inline double RandomDouble(double min = 0.0f, double max = 1.0f) { return min + (double) rand() / (RAND_MAX / max); }

}