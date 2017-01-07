#include <iostream>
#include "../mystack.h"

int main(int argc, char const *argv[])
{
	MyStack<int> ms;

	//ms.insert_on_end (10);
	//ms.insert_on_end (20);
	//ms.insert_on_end (30);

	ms.insert_all_on_end ({40, 50, 60});

	for (int i = 0; i != 3; ++i)
		std::cout << ms.remove_first () << std::endl;

	return 0;
}