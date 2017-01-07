/* 
 * Node class
 * @author: Gustavo Schwantz Oliveira
 *
 * This class it is the definition a node from the 8-puzzle problem. I pick up
 * the definition of a "node" from Russel S., AI - A Modern Approach, 2nd, ch. 3
 *
 */

#ifndef NODE_H
#define NODE_H

#include <string>
#include <memory>
#include "moves.h"

class Node {
public:
	Node ()
	    :father{nullptr} , path_cost{0}, depth{0}
	{
		
	}

	Node (const std::string& s)
	    :state{s}, father{nullptr}, action{Moves::no_action}, path_cost{0}, depth{0}
	{
		
	}

    Node (const std::string& s, const std::shared_ptr<Node>& f, const Moves& a, const int& pc, const int& d)
	    :state{s}, father{f}, action{a}, path_cost{pc}, depth{d}
	{
		
	}

	~Node ()
	{

	}

	std::string get_state () const
	{
		return state;
	}
    
    std::shared_ptr<Node> get_father () const
    {
    	return father;
    }

    Moves get_action () const
    {
    	return action;
    }

    int get_path_cost () const
    {
    	return path_cost;
    }

    int get_depth () const
    {
    	return depth;
    }

    void set_state (const std::string& s) 
	{
		state = s;
	}
    
    void set_father (const std::shared_ptr<Node>& f) 
    {
    	father = f;
    }

    void set_action (const Moves& a) 
    {
    	action = a;
    }

    void set_path_cost (const int& pc) 
    {
    	path_cost = pc;
    }

    void set_depth (const int& d) 
    {
    	depth = d;
    }
    
private:
    std::string state; /* the state of 8-puzzle problem that the node represent */
    std::shared_ptr<Node> father; /* a pointer to the father */
    Moves action; /* the movement made in father node for result in this node */
    int path_cost; /* cost to go from root to the node "n" */
    int depth; /* node's depth */
};

#endif