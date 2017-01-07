#include "functions.h"

int Functions::h (const std::shared_ptr<Node>& n)
{
	int total_distance = 0;
	std::string state = n->get_state ();

	for (const auto& c : state) {
		if (c == '0')
			continue;
        total_distance += manhattan_distance (state.find (c), final_state.find (c));    
	}

    return total_distance;
}

int Functions::manhattan_distance (const int& i, const int& f)
{
	switch (i) {
		case 0:
		    if (f == 0) 
		    	return 0;
		    else if (f == 1 || f == 3)
		    	return 1;
		    else if (f == 2 || f == 4 || f == 6)
		    	return 2;
		    else if (f == 5 || f == 7)
		    	return 3;
		    else
		    	return 4;

		case 1:
		    if (f == 1) 
		    	return 0;
		    else if (f == 0 || f == 2 || f == 4)
		    	return 1;
		    else if (f == 3 || f == 5 || f == 7)
		    	return 2;
		    else
		    	return 3;    

		case 2:
		    if (f == 2) 
		    	return 0;
		    else if (f == 1 || f == 5)
		    	return 1;
		    else if (f == 0 || f == 4 || f == 8)
		    	return 2;
		    else if (f == 3 || f == 7)
		    	return 3;
		    else
		    	return 4;

		case 3:
		    if (f == 3) 
		    	return 0;
		    else if (f == 0 || f == 6 || f == 4)
		    	return 1;
		    else if (f == 1 || f == 5 || f == 7)
		    	return 2;
		    else
		    	return 3;       

		case 4:
		    if (f == 4) 
		    	return 0;
		    else if (f == 1 || f == 3 || f == 5 || f == 7)
		    	return 1;
		    else
		    	return 2;       

		case 5:
		    if (f == 5) 
		    	return 0;
		    else if (f == 8 || f == 2 || f == 4)
		    	return 1;
		    else if (f == 3 || f == 1 || f == 7)
		    	return 2;
		    else
		    	return 3;       

		case 6:
		    if (f == 6) 
		    	return 0;
		    else if (f == 7 || f == 3)
		    	return 1;
		    else if (f == 0 || f == 4 || f == 8)
		    	return 2;
		    else if (f == 1 || f == 5)
		    	return 3;
		    else
		    	return 4;

		case 7:
		    if (f == 7) 
		    	return 0;
		    else if (f == 6 || f == 8 || f == 4)
		    	return 1;
		    else if (f == 3 || f == 5 || f == 1)
		    	return 2;
		    else
		    	return 3;       

		case 8:
		    if (f == 8) 
		    	return 0;
		    else if (f == 7 || f == 5)
		    	return 1;
		    else if (f == 2 || f == 4 || f == 6)
		    	return 2;
		    else if (f == 3 || f == 1)
		    	return 3;
		    else
		    	return 4;      

	}
}