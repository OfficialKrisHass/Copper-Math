#include <iostream>

#include "CMath.h"

using namespace CMath;

int main() {

	Vector3 a = Vector3(38.5f, 25.7f, 29.83f);
	Vector3 b = Vector3(10.0f, 5.0f, 10.0f);

	Vector2 c;

	std::cout << a + b << std::endl;

	std::cin.get();
	return 0;

}