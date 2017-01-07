#include <iostream>
#include <string>
#include <memory>
#include "../functions.h"

int main(int argc, char const *argv[])
{
	Functions function ("123456780");

	auto n0 = std::make_shared<Node> ("158423067");
	auto n1 = std::make_shared<Node> ("158023467");
	auto n2 = std::make_shared<Node> ("158423607");
	//auto n3 = std::make_shared<Node> ("243156708");
	//auto n4 = std::make_shared<Node> ("243106758");

	std::cout << function.h (n0) << std::endl;
	std::cout << function.h (n1) << std::endl;
	std::cout << function.h (n2) << std::endl;
	//std::cout << function.h (n3) << std::endl;
	//std::cout << function.h (n4) << std::endl;

	return 0;
}