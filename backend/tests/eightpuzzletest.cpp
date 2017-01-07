#include <iostream>
#include <string>
#include "eightpuzzle.h"

int main(int argc, char const *argv[])
{
	EightPuzzle ep ("123456780", "012345678");

	auto node{new Node (Moves::up, "801524673", nullptr)};

	for (auto d : ep.sucessor_fun (node)) {
        if (d.first == Moves::right)
        	std::cout << "\nAction: " << "RIGHT" << std::endl;
        if (d.first == Moves::left)
        	std::cout << "\nAction: " << "LEFT" << std::endl;
        if (d.first == Moves::up)
        	std::cout << "\nAction: " << "UP" << std::endl;
        if (d.first == Moves::down)
        	std::cout << "\nAction: " << "DOWN" << std::endl;

        std::cout << "State: " << d.second << std::endl;
        std::cout << std::endl;
	} 

	delete node;

	return 0;
}