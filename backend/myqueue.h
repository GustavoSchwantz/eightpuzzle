/* 
 * MyQueue class
 * @author: Gustavo Schwantz Oliveira
 *
 */

#ifndef MYQUEUE_H 
#define MYQUEUE_H

#include "fringe.h"

template<typename T>
class MyQueue : public Fringe<T> {
public:
	
	bool empty ()
	{
		return (this->size ()) ? false : true;
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
	    this->insert (this->begin (), element);
    }

    void insert_all (std::vector<T> elements)
    {
	    this->insert (this->begin (), elements.begin (), elements.end ());
    }
};

#endif