/* 
 * Functions class
 * @author: Gustavo Schwantz Oliveira
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H 

#include <string>
#include <memory>
#include "node.h" 
#include "moves.h"

class Functions {
public:

	Functions (const std::string& fs)
	    :final_state{fs}
	{

	}

	~Functions ()
	{

	}


    /* Verify if n0 is more or equal distant from final state (less priority) than n1 */
	bool operator() (const std::shared_ptr<Node>& n0, const std::shared_ptr<Node>& n1)
    {
	    return f (n0) >= f (n1);
    }

    /* the heuristic function returns the manhattan distance of node "n" */
    /* from final state */
    int h (const std::shared_ptr<Node>& n);

private:

    /* the f funtion for de A* */
	int f (const std::shared_ptr<Node>& n)
    {
	    return g (n) + h (n);

    }

    /* g function is just the path cost */
    int g (const std::shared_ptr<Node>& n)
    {
	    return n->get_path_cost ();
    }

    /* measure the manhattan distance of two members of the table */
    int manhattan_distance (const int& i, const int& f);
    
    const std::string final_state; /* goal state */
};

#endif
