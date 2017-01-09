#include <iostream>
#include <string>
#include <chrono>
#include "search.h"
#include "eightpuzzle.h"

void bfs_test ()
{
	Search search;

    //EightPuzzle p0 ("123456780", "123456780");
    //EightPuzzle p1 ("243106758", "123456780");
    EightPuzzle p2 ("158023467", "123456780");
    //EightPuzzle p3 ("207854361", "123456780");
    //EightPuzzle p4 ("876543210", "123456780");
    //EightPuzzle p5 ("684507312", "123456780");
    //EightPuzzle p6 ("087654321", "123456780");
    //EightPuzzle p7 ("807654231", "123456780");
    //EightPuzzle p8 ("708654321", "123456780");
    //EightPuzzle p9 ("708564132", "123456780");
    //EightPuzzle p10 ("708546123", "123456780");

    //EightPuzzle p11 ("123457680", "123456780");
    //EightPuzzle p12 ("518023467", "123456780");

    //std::vector<EightPuzzle> problems{p0, p1, p2, p3, p4, p5,
    //    p6, p7, p8, p9, p10, p11, p12};

    std::cout << "Breadth-First Search Test:\n" << std::endl; 

    for (const auto& p : {p2}) {
        auto t0 = std::chrono::high_resolution_clock::now ();
        
        std::cout << "Estado Inicial: " << p.initial_state () << std::endl;
        auto path = search.breadth_first_search (p);

        auto t1 = std::chrono::high_resolution_clock::now ();

        std::cout << "Número de estados p/ a solução: " << path.size () << std::endl;
        std::cout << "Número de estados testados: " << search.get_closed_list_size () << std::endl;
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
    /*EightPuzzle p3 ("207854361", "123456780");
    EightPuzzle p4 ("876543210", "123456780");
    EightPuzzle p5 ("684507312", "123456780");
    EightPuzzle p6 ("087654321", "123456780");
    EightPuzzle p7 ("807654231", "123456780");
    EightPuzzle p8 ("708654321", "123456780");
    EightPuzzle p9 ("708564132", "123456780");
    EightPuzzle p10 ("708546123", "123456780");

    EightPuzzle p11 ("123457680", "123456780");
    EightPuzzle p12 ("518023467", "123456780");

    std::vector<EightPuzzle> problems{p0, p1, p2, p3, p4, p5,
        p6, p7, p8, p9, p10, p11, p12};*/

    std::cout << "\nDepth-First Search Test:\n" << std::endl; 

    for (const auto& p : {p0, p1, p2}) {
        auto t0 = std::chrono::high_resolution_clock::now ();
        
        std::cout << "Estado Inicial: " << p.initial_state () << std::endl;
        auto path = search.depth_first_search (p);

        auto t1 = std::chrono::high_resolution_clock::now ();

        std::cout << "Número de estados p/ a solução: " << path.size () << std::endl;
        std::cout << "Número de estados testados: " << search.get_closed_list_size () << std::endl;
        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds> 
            (t1 - t0).count () << " milliseconds\n" << std::endl;
    }
}

void a_star_test ()
{
    Search search;

    //EightPuzzle p0 ("123456780", "123456780");
    //EightPuzzle p1 ("243106758", "123456780");
    EightPuzzle p2 ("158023467", "123456780");
    //EightPuzzle p3 ("207854361", "123456780");
    //EightPuzzle p4 ("876543210", "123456780");
    //EightPuzzle p5 ("684507312", "123456780");
    //EightPuzzle p6 ("087654321", "123456780");
    //EightPuzzle p7 ("807654231", "123456780");
    //EightPuzzle p8 ("708654321", "123456780");
    //EightPuzzle p9 ("708564132", "123456780");
    //EightPuzzle p10 ("708546123", "123456780");

    //EightPuzzle p11 ("123457680", "123456780");
    //EightPuzzle p12 ("518023467", "123456780");

    //std::vector<EightPuzzle> problems{p0, p1, p2, p3, p4, p5,
    //    p6, p7, p8, p9, p10, p11, p12};

    std::cout << "\nA* Test:\n" << std::endl; 

    for (const auto& p : {p2}) {
        auto t0 = std::chrono::high_resolution_clock::now ();
        
        std::cout << "Estado Inicial: " << p.initial_state () << std::endl;
        auto path = search.a_star (p);

        auto t1 = std::chrono::high_resolution_clock::now ();

        std::cout << "Número de estados p/ a solução: " << path.size () << std::endl;
        std::cout << "Número de estados testados: " << search.get_closed_list_size () << std::endl;
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
    EightPuzzle p5 ("684507312", "123456780");
    EightPuzzle p6 ("087654321", "123456780");
    EightPuzzle p7 ("807564231", "123456780");
    EightPuzzle p8 ("708654231", "123456780");
    EightPuzzle p9 ("708564132", "123456780");
    EightPuzzle p10 ("708546123", "123456780");

    EightPuzzle p11 ("123457680", "123456780");
    EightPuzzle p12 ("518023467", "123456780");

    std::vector<EightPuzzle> problems{p0, p1, p2, p3, p4, p5,
        p6, p7, p8, p9, p10, p11, p12};
    
    std::cout << "Hill Climbing Test:\n" << std::endl; 

    for (const auto& p : problems) {
        auto t0 = std::chrono::high_resolution_clock::now ();
        
        std::cout << "Estado Inicial: " << p.initial_state () << std::endl;
        auto path = search.random_restart_hill_climbing (p);

        auto t1 = std::chrono::high_resolution_clock::now ();

        std::cout << "Número de estados p/ a solução: " << path.size () << std::endl;
        std::cout << "Número de estados testados: " << search.get_closed_list_size () << std::endl;
        std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds> 
            (t1 - t0).count () << " milliseconds\n" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
	//bfs_test ();
    dls_test ();
    //a_star_test ();
    //hill_climbing_test ();

	return 0;
}