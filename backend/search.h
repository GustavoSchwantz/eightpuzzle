/* 
 * Search class
 * @author: Gustavo Schwantz Oliveira
 */

#ifndef SEARCH
#define SEARCH

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <limits>
#include "moves.h"
#include "node.h"
#include "eightpuzzle.h"
#include "fringe.h"
#include "myqueue.h"
#include "mystack.h"
#include "priorityqueue.h"
#include "functions.h"

#define N_RESTART 10000

using n_ptr = std::shared_ptr<Node>;

class Search {
public:
	Search ()
	{

	}

	~Search ()
	{

	}

	unsigned int get_closed_list_size () const
	{
		return closed_list.size ();
	}

	std::vector<Moves> breadth_first_search (const EightPuzzle& p)
    {
	    return graph_search (p, std::make_shared<MyQueue<n_ptr>> ());
    }

    std::vector<Moves> iterative_deepening_search (const EightPuzzle& p);

    std::vector<Moves> depth_limited_search (const EightPuzzle& p, const int& d);
    
    std::vector<Moves> a_star (const EightPuzzle& p)
    {
	    return graph_search (p, std::make_shared<PriorityQueue<n_ptr>> (Functions (p.initial_state ())));
    }

    std::vector<Moves> random_restart_hill_climbing (const EightPuzzle& p);

private:
	std::vector<Moves> graph_search (const EightPuzzle& p, const std::shared_ptr< Fringe<n_ptr> >& f);
	std::vector<Moves> recursive_dls (const n_ptr& n, const EightPuzzle& p, const int& l);
	n_ptr random_hill_climbing (const EightPuzzle& p, std::vector<Moves>& a, const n_ptr& n);
	std::vector<n_ptr> expand (const n_ptr& n, const EightPuzzle& p);
	bool is_not_in_closed (const std::string& s);
    std::vector<Moves> solution (const n_ptr& n);
    n_ptr select_neighbor_randomly (const n_ptr& n, const EightPuzzle& p);
    int distance (const n_ptr& n, const EightPuzzle& p);

	std::vector<std::string> closed_list;
};

#endif