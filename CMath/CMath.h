#pragma once

#include "Trigonometry.h"

#define Min(type) type Min(type a, type b) { return (a > b) ? b : a; }
#define Max(type) type Max(type a, type b) { return (a > b) ? a : b; }

namespace CMath {

	Min(int)
	Min(float)
	Min(double)

	Max(int)
	Max(float)
	Max(double)

}