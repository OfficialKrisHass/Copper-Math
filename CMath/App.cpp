#include <iostream>
#include <vector>

#define INCLUDE_GLM
#include "CMath.h"

#include <GLM/glm.hpp>

using namespace CMath;

#define Test(x, y, feature) { if(x == y) { std::cout << feature << " was Successfull!" << std::endl; }\
							  else { std::cout << "----------" << feature " Was Not successfull!" << std::endl;\
									 unsuccessfullFeatures.push_back(feature); } }

std::vector<std::string> unsuccessfullFeatures;

//Tests
void TestNumberManipulation();
void TestTrigonometry();
void TestVectorMath();

void PrintUnsuccessfullFeatures();

int main() {

	TestNumberManipulation();
	TestTrigonometry();
	TestVectorMath();

	PrintUnsuccessfullFeatures();

	std::cin.get();
	return 0;

}

void TestNumberManipulation() {

	std::cout << "-----------------------------" << std::endl;
	std::cout << "-----Number Manipulation-----" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;

	Test(Min(3, 5), 3, "Min - 3 and 5");
	Test(Min(5, 3), 3, "Min - 5 and 3");
	Test(Min(-78, 498), -78, "Min - -78 and 489");
	Test(Min(498, -78), -78, "Min - 489 and -78");

	std::cout << std::endl;

	Test(Max(3, 5), 5, "Max - 3 and 5");
	Test(Max(5, 3), 5, "Max - 5 and 3");
	Test(Max(-78, 498), 498, "Max - -78 and 489");
	Test(Max(498, -78), 498, "Max - 489 and -78");

	std::cout << std::endl;

	Test(RoundNearest(0.3f), 0, "Round Nearest - 0.3");
	Test(RoundNearest(0.8f), 1, "Round Nearest - 0.8");
	Test(RoundNearest(-78.3f), -78, "Round Nearest - -78-3");
	
	std::cout << std::endl;

	Test(RoundSmallest(0.3f), 0, "Round Smallest - 0.3");
	Test(RoundSmallest(0.8f), 0, "Round Smallest - 0.8");
	Test(RoundSmallest(-78.3f), -78, "Round Smallest - -78-3");

	std::cout << std::endl;

	Test(Clamp(78, 3, 100), 78, "Clamp - 78 between 3 and 100");
	Test(Clamp(78, 3, 10), 10, "Clamp - 78 between 3 and 10");
	Test(Clamp(1, 3, 10), 3, "Clamp - 1 between 3 and 10");

	std::cout << std::endl;

}
void TestTrigonometry() {

	std::cout << "----------------------" << std::endl;
	std::cout << "-----Trigonometry-----" << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;

	Test(CMath::RadiansToDegrees(2.0f * (float) CMath::pi), glm::degrees(2.0f * (float) CMath::pi), "Radians to Degrees - 2pi");
	Test(CMath::RadiansToDegrees(0.0f), glm::degrees(0.0f), "Radians to Degrees - zero");
	Test(CMath::RadiansToDegrees(2.58469f), glm::degrees(2.58469f), "Radians to Degrees - 2.58469");

	std::cout << std::endl;

	Test(CMath::RadiansToDegrees(Vector3(2.0f * (float) CMath::pi)), glm::degrees(glm::vec3(2.0f * (float) CMath::pi)), "Radians to Degrees VECTOR3 - 2pi");
	Test(CMath::RadiansToDegrees(Vector3(2.58469f)), glm::degrees(glm::vec3(2.58469f)), "Radians to Degrees VECTOR3 - 2.58469");

	std::cout << std::endl;

	Test(CMath::DegreesToRadians(360.0f), glm::radians(360.0f), "Degrees to Radians - 360");
	Test(CMath::DegreesToRadians(0.0f), glm::radians(0.0f), "Degrees to Radians - 0");
	Test(CMath::DegreesToRadians(180.0f), glm::radians(180.0f), "Degrees to Radians - 90");
	Test(CMath::DegreesToRadians(123.0f), glm::radians(123.0f), "Degrees to Radians - 123");

	std::cout << std::endl;

	Test(CMath::DegreesToRadians(Vector3(360.0f)), glm::radians(glm::vec3(360.0f)), "Degrees to Radians VECTOR3 - 360");
	Test(CMath::DegreesToRadians(Vector3(123.0f)), glm::radians(glm::vec3(123.0f)), "Degrees to Radians VECTOR3 - 123");

	std::cout << std::endl;

}
void TestVectorMath() {

	std::cout << "---------------------" << std::endl;
	std::cout << "-----Vector Math-----" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	Vector2 a2 = Vector2(10, 5);
	Vector2 b2 = Vector2(39, 7.5f);
	Vector2 c2 = Vector2(-15, 9);

	Test(a2 + b2, (glm::vec2) a2 + (glm::vec2) b2, "Vector2 Addition - a + b");
	Test(a2 - b2, (glm::vec2) a2 - (glm::vec2) b2, "Vector2 Subtraction - a - b");
	Test(a2 * b2, (glm::vec2) a2 * (glm::vec2) b2, "Vector2 Multiplication - a * b");
	Test(c2 / a2, (glm::vec2) c2 / (glm::vec2) a2, "Vector2 Dividing - c / a");

	std::cout << std::endl;

	Test(a2 + 73.8f, (glm::vec2) a2 + 73.8f, "Vector2 Addition - a + 73.8");
	Test(a2 - 3.9f, (glm::vec2) a2 - 3.9f, "Vector2 Subtraction - a - 3.9");
	Test(a2 * -2.0f, (glm::vec2) a2 * -2.0f, "Vector2 Multiplication - a * -2");
	Test(c2 / 5.0f, (glm::vec2) c2 / 5.0f, "Vector2 Dividing - c / 5");

	std::cout << std::endl;

	Vector3 a3 = Vector3(10, 0, 7);
	Vector3 b3 = Vector3(49, 3, 15);
	Vector3 c3 = Vector3(-27.8f, -8, 39);

	Test(a3 + b3, (glm::vec3) a3 + (glm::vec3) b3, "Vector3 Addition - a + b");
	Test(a3 - b3, (glm::vec3) a3 - (glm::vec3) b3, "Vector3 Subtraction - a - b");
	Test(a3 * b3, (glm::vec3) a3 * (glm::vec3) b3, "Vector3 Multiplication - a * b");
	Test(c3 / a3, (glm::vec3) c3 / (glm::vec3) a3, "Vector3 Dividing - c / a");

	std::cout << std::endl;

	Test(a3 + 73.8f, (glm::vec3) a3 + 73.8f, "Vector3 Addition - a + 73.8");
	Test(a3 - 3.9f, (glm::vec3) a3 - 3.9f, "Vector3 Subtraction - a - 3.9");
	Test(a3 * -2.0f, (glm::vec3) a3 * -2.0f, "Vector3 Multiplication - a * -2");
	Test(c3 / 5.0f, (glm::vec3) c3 / 5.0f, "Vector3 Dividing - c / 5");

	std::cout << std::endl;

	Vector4 a4 = Vector4(255, 255, 128, 255);
	Vector4 b4 = Vector4(237, 136, 128, 196);
	Vector4 c4 = Vector4(255, 165, 255, 0);

	Test(a4 + b4, (glm::vec4) a4 + (glm::vec4) b4, "Vector4 Addition - a + b");
	Test(a4 - b4, (glm::vec4) a4 - (glm::vec4) b4, "Vector4 Subtraction - a - b");
	Test(a4 * b4, (glm::vec4) a4 * (glm::vec4) b4, "Vector4 Multiplication - a * b");
	Test(c4 / a4, (glm::vec4) c4 / (glm::vec4) a4, "Vector4 Dividing - c / a");

	std::cout << std::endl;

	Test(a4 + 74.8f, (glm::vec4) a4 + 74.8f, "Vector4 Addition - a + 74.8");
	Test(a4 - 4.9f, (glm::vec4) a4 - 4.9f, "Vector4 Subtraction - a - 4.9");
	Test(a4 * -2.0f, (glm::vec4) a4 * -2.0f, "Vector4 Multiplication - a * -2");
	Test(c4 / 5.0f, (glm::vec4) c4 / 5.0f, "Vector4 Dividing - c / 5");

	std::cout << std::endl;

}

void PrintUnsuccessfullFeatures() {

	std::cout << "\n\n\n" << std::endl;
	std::cout << "These Features were unsuccessfull!" << std::endl;

	for (const std::string& feature : unsuccessfullFeatures) {

		std::cout << "    " << feature << std::endl;

	}

}