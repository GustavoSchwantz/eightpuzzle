/* 
 * Fringe class
 * @author: Gustavo Schwantz Oliveira
 *
 * Fringe serve as a interface for MyQueue and PriorityQueue
 *
 */

#ifndef FRINGE_H
#define FRINGE_H

#include <vector>

template<typename T>
class Fringe : protected std::vector<T> {
public:
	virtual bool empty () = 0;
	virtual T first () = 0;
	virtual T remove_first () = 0;
	virtual void insert_ (T element) = 0;
    virtual void insert_all (std::vector<T> elements) = 0;
    virtual ~Fringe () {}
};

#endif