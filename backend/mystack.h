#ifndef MYSTACK
#define MYSTACK

#include "fringe.h"

template<typename T>
class MyStack : public Fringe<T> {
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
	    this->push_back (element);
    }

    void insert_all (std::vector<T> elements)
    {
	    for (const auto &e : elements)
	    	this->push_back (e);
    }
};

#endif