#include <iostream>
#include "../priorityqueue.h"

int main(int argc, char const *argv[])
{
	PriorityQueue<int> pq;

	pq.insert_ (3);
	pq.insert_ (3);
	pq.insert_ (1);
	pq.insert_ (4);

	pq.insert_all({-3, 0, 400, 100});

	while (!pq.empty ())
	    std::cout << pq.remove_first () << std::endl;

	return 0;
}