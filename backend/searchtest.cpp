#include <iostream>
#include <string>
#include <chrono>
#include "search.h"
#include "eightpuzzle.h"

void bfs_test ()
{
	Search search;

    EightPuzzle p0 ("123456780", "123456780");
    EightPuzzle p1 ("243106758", "123456780");
    EightPuzzle p2 ("158023467", "123456780");
    EightPuzzle p3 ("207854361", "123456780");
    EightPuzzle p4 ("876543210", "123456780");

    EightPuzzle p5 ("123457680", "123456780");
    EightPuzzle p6 ("518023467", "123456780");

    std::vector<EightPuzzle> problems{p0, p1, p2, p3, p4, p5, p6};

    std::cout << "Breadth-First Search Test:\n" << std::endl; 

    for (const auto& p : problems) {
        auto t0 = std::chrono::high_resolution_clock::now ();

        auto path = search.breadth_first_search (p);

        auto t1 = std::chrono::high_resolution_clock::now ();

        std::cout << "Número de estados p/ a solução: " << path.size () << std::endl;
        std::cout << "Número de estados testados: " << search.get_tested_states () << std::endl;
        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds> 
            (t1 - t0).count () << " milliseconds\n" << std::endl;
    }
}

void dls_test ()
{
    Search search;

    EightPuzzle p0 ("123456780", "123456780");
    EightPuzzle p1 ("243106758", "123456780");
    EightPuzzle p2 ("158023467", "123456780");
    EightPuzzle p3 ("207854361", "123456780");
    EightPuzzle p4 ("876543210", "123456780");

    EightPuzzle p5 ("123457680", "123456780");
    EightPuzzle p6 ("518023467", "123456780");

    std::vector<EightPuzzle> problems{p0, p1, p2, p3, p4, p5, p6};

    std::cout << "Depth-Limited Search Test:\n" << std::endl; 

    for (const auto& p : problems) {
        auto t0 = std::chrono::high_resolution_clock::now ();

        auto path = search.depth_limited_search (p);

        auto t1 = std::chrono::high_resolution_clock::now ();

        std::cout << "Número de estados p/ a solução: " << path.size () << std::endl;
        std::cout << "Número de estados testados: " << search.get_tested_states () << std::endl;
        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds> 
            (t1 - t0).count () << " milliseconds\n" << std::endl;
    }
}

void a_star_test ()
{
    Search search;

    EightPuzzle p0 ("123456780", "123456780");
    EightPuzzle p1 ("243106758", "123456780");
    EightPuzzle p2 ("158023467", "123456780");
    EightPuzzle p3 ("207854361", "123456780");
    EightPuzzle p4 ("876543210", "123456780");

    EightPuzzle p5 ("123457680", "123456780");
    EightPuzzle p6 ("518023467", "123456780");

    std::vector<EightPuzzle> problems{p0, p1, p2, p3, p4, p5, p6};

    std::cout << "A* Test:\n" << std::endl; 

    for (const auto& p : problems) {
        auto t0 = std::chrono::high_resolution_clock::now ();

        auto path = search.a_star (p);

        auto t1 = std::chrono::high_resolution_clock::now ();

        std::cout << "Número de estados p/ a solução: " << path.size () << std::endl;
        std::cout << "Número de estados testados: " << search.get_tested_states () << std::endl;
        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds> 
            (t1 - t0).count () << " milliseconds\n" << std::endl;
    }
}

void hill_climbing_test ()
{
    Search search;

    EightPuzzle p0 ("123456780", "123456780");
    EightPuzzle p1 ("243106758", "123456780");
    EightPuzzle p2 ("158023467", "123456780");
    EightPuzzle p3 ("207854361", "123456780");
    EightPuzzle p4 ("876543210", "123456780");

    EightPuzzle p5 ("123457680", "123456780");
    EightPuzzle p6 ("518023467", "123456780");

    std::vector<EightPuzzle> problems{p0, p1, p2, p3, p4, p5, p6};

    std::cout << "Hill Climbing Test:\n" << std::endl; 

    for (const auto& p : problems) {
        auto t0 = std::chrono::high_resolution_clock::now ();

        auto path = search.random_restart_hill_climbing (p);

        auto t1 = std::chrono::high_resolution_clock::now ();

        std::cout << "Número de estados p/ a solução: " << path.size () << std::endl;
        std::cout << "Número de estados testados: " << search.get_tested_states () << std::endl;
        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds> 
            (t1 - t0).count () << " milliseconds\n" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
	bfs_test ();
    dls_test ();
    //a_star_test ();
    //hill_climbing_test ();

	return 0;
}