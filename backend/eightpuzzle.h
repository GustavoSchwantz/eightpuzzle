/*
 * EightPuzzle class 
 * @author: Gustavo Schwantz Oliveira
 *
 * This class it is the definition of the 8-puzzle problem. I pick up
 * the definition of a "problem" from Russel S., AI - A Modern Approach, 2nd, ch. 3
 *
 */

#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H

#include <utility>
#include <vector>
#include <string>
#include "moves.h"

#define STEP_COST 1 /* the cost from move from one state to another */

class EightPuzzle {
public:
	EightPuzzle (const std::string& i, const std::string& f)
	    :initial{i}, final{f}
	{

	}  

	~EightPuzzle ()
	{
		
	} 

	const std::string& initial_state () const
	{
		return initial;
	}

	const std::string& final_state () const
	{
		return final;
	}

    /* this function receive a state and return a set of pairs <Action, State> */
	std::vector<std::pair<Moves, std::string>> sucessor_fun (const std::string& s) const;
    
    /* receive a state and verify if it is the goal */
	bool goal_test (const std::string& s) const
	{
		return s == final;
	}

     /* just return a step cost. The parameters serve for nothing */
     /*(yes, this is stupid, but is more cool this way) */
	int step_cost (const std::string& s, const Moves& a, const std::string& r) const
	{
		return STEP_COST;
	}

private:
	const std::string initial, final; /* the initial and final states */
};

#endif