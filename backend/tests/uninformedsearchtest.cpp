#include <iostream>
#include <string>
#include <chrono>
#include "uninformedsearch.h"

void test ()
{
	EightPuzzle problem ("243106758", "123456780");
	UninformedSearch us;

	std::cout << "\nPassos da raíz até a solução : \n" << std::endl;

	auto t0 = std::chrono::high_resolution_clock::now ();

    for (auto s : us.depth_first_search (problem)) {
    	if (s == Moves::no_action)
        	std::cout << "Action: " << "NO ACTION" << std::endl;
    	if (s == Moves::right)
        	std::cout << "Action: " << "RIGHT" << std::endl;
        if (s == Moves::left)
        	std::cout << "Action: " << "LEFT" << std::endl;
        if (s == Moves::up)
        	std::cout << "Action: " << "UP" << std::endl;
        if (s == Moves::down)
        	std::cout << "Action: " << "DOWN" << std::endl;
    }

    auto t1 = std::chrono::high_resolution_clock::now ();

    std::cout << std::endl;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds> 
        (t1 - t0).count () << " milliseconds" << std::endl;
}

int main(int argc, char const *argv[])
{
	test ();

	return 0;
}