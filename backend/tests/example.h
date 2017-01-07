#include <utility>
#include <vector>
#include "moves.h"

class Example {
public:
	Example ()
	{

	}

	~Example ()
	{

	}

	std::vector<std::pair<Moves, std::string>> sucessor_fun (const std::string& s) const;
};