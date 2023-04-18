#include <iostream>

#include "CMath.h"

using namespace CMath;

int main() {

	Vector4 a = Vector4(38.5f, 25.7f, 29.83f);
	Vector4 b = Vector4(10.0f, 5.0f, 10.0f);

	std::cout << a + b << std::endl;

	std::cin.get();
	return 0;

}