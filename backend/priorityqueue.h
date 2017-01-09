/* 
 * PriorityQueue class
 * @author: Gustavo Schwantz Oliveira
 *
 * The first node select will be the more close from final state
 *
 */

#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "fringe.h"
#include "functions.h"

template<typename T>
class PriorityQueue : public Fringe<T> {
public:

	PriorityQueue (Functions f)
	    :function{f}
	{

	}    

	bool empty_ ()
	{
		return this->empty ();
	}

	T first ()
	{
        return this->back ();
	}

	T remove_first ()
	{
		T element = this->back ();
        this->pop_back ();
        return element;
	}

	void insert_ (T element)
    {
	    for (auto it = this->begin (); it != this->end (); ++it)
	    	if (function (element, *it)) {
	    		this->insert (it, element);
	    		return;
	    	}

        this->push_back (element);
    }

    void insert_all (std::vector<T> elements)
    {
	    for (const auto &e : elements)
	    	insert_ (e);
    }

private:
	Functions function;
};

#endif