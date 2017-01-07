#include "example.h"

std::vector<std::pair<Moves, std::string>> Example::sucessor_fun (const std::string& s) const
{

    std::vector<std::pair<Moves, std::string>> suc;

	if (s == "1000") {

		suc.push_back (std::make_pair (Moves::no_action, "0100"));
		suc.push_back (std::make_pair (Moves::no_action, "0010"));
		suc.push_back (std::make_pair (Moves::no_action, "0001"));
	}

    if (s == "0100") {

		suc.push_back (std::make_pair (Moves::no_action, "1000"));
		suc.push_back (std::make_pair (Moves::no_action, "0010"));
		suc.push_back (std::make_pair (Moves::no_action, "0001"));
	}

	if (s == "0010") {

		suc.push_back (std::make_pair (Moves::no_action, "1000"));
		suc.push_back (std::make_pair (Moves::no_action, "0100"));
		suc.push_back (std::make_pair (Moves::no_action, "0001"));
	}
	
	if (s == "0001") {

		suc.push_back (std::make_pair (Moves::no_action, "0100"));
		suc.push_back (std::make_pair (Moves::no_action, "0010"));
		suc.push_back (std::make_pair (Moves::no_action, "1000"));
	}

	return suc;
}