#include <iostream>

#include "CMath.h"

using namespace CMath;

int main() {


	uint32_t nMin = 0;
	uint32_t nMax = 0;
	uint32_t nWrong = 0;
	uint32_t timeStart = (uint32_t) time(nullptr);
	for (int i = 0; i < 1'000'000'000; i++) {

		int random = RandomInt(0, 100);
		if (random == 100) nMax++;
		if (random == 0) nMin++;
		if (random > 100 || random < 0) nWrong++;

	}
	uint32_t timeElapsed = (uint32_t) time(nullptr) - timeStart;

	std::cout << "1 000 000 000 runs done.\nTime Elapsed: " << timeElapsed << std::endl << std::endl;

	std::cout << "nMin: " << nMin << std::endl;
	std::cout << "nMax: " << nMax << std::endl;
	std::cout << "nWrong: " << nWrong << std::endl;

	std::cin.get();
	return 0;

}