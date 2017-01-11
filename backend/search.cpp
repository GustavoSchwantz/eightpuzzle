#include "search.h"

std::vector<Moves> Search::graph_search (const EightPuzzle& p, const std::shared_ptr< Fringe<n_ptr> >& f)
{
	closed_list.erase (closed_list.begin (), closed_list.end ());
	f->insert_ (std::make_shared<Node> (p.initial_state ())); 

	for ( ; ; ) {
		if (f->empty_ ()) { return {}; }

		auto node = f->remove_first ();

		if (p.goal_test (node->get_state ())) { return solution (node); }

		if (is_not_in_closed (node->get_state ())) {

			closed_list.push_back (node->get_state ());
			f->insert_all (expand (node, p));
		}
	}
}

std::vector<Moves> Search::iterative_deepening_search (const EightPuzzle& p)
{
    for (int depth = 0; depth != std::numeric_limits<int>::max (); ++depth) {
        std::vector<Moves> path = depth_limited_search (p, depth);
        if (path.size ()) { return path; }
    }

    return {};
}

std::vector<Moves> Search::depth_limited_search (const EightPuzzle& p, const int& d)
{
	closed_list.erase (closed_list.begin (), closed_list.end ());
    return recursive_dls (std::make_shared<Node> (p.initial_state ()), p, d);
}


std::vector<Moves> Search::recursive_dls (const n_ptr& n, const EightPuzzle& p, const int& l)
{
	if (p.goal_test (n->get_state ())) { return solution (n); }

	else if (n->get_depth () == l) { return {}; }

	else 
		if (is_not_in_closed (n->get_state ())) {

			closed_list.push_back (n->get_state ());

			for (const auto& succ : expand (n, p)) {

		        std::vector<Moves> path = recursive_dls (succ, p, l);
		        if (path.size ()) { return path; }
	        }
		}

	return {};
}

std::vector<Moves> Search::random_restart_hill_climbing (const EightPuzzle& p)
{
	closed_list.erase (closed_list.begin (), closed_list.end ());
	n_ptr initial_node{std::make_shared<Node> (p.initial_state ())};

	std::vector<Moves> path;

	for (int i = 0; i != N_RESTART; ++i) {
		auto node = random_hill_climbing (p, path, initial_node);
		if (p.goal_test (node->get_state ())) {
			return (path.size ()) ? path : (path.push_back (Moves::no_action), path);
		}

		initial_node = select_neighbor_randomly (node, p);
		path.push_back (initial_node->get_action ());
	}
	
	return {};
}

n_ptr Search::random_hill_climbing (const EightPuzzle& p, std::vector<Moves>& a, const n_ptr& n)
{
	auto current{n};

	for ( ; ; ) {
		auto neighbor{select_neighbor_randomly (current, p)};

		if (distance (neighbor, p) > distance (current, p)) {
		    return current; 
		}

		a.push_back (neighbor->get_action ());

		current = neighbor;
	}
}

std::vector<n_ptr> Search::expand (const n_ptr& n, const EightPuzzle& p)
{
	std::vector<n_ptr> sucessors;

    for (auto d : p.sucessor_fun (n->get_state ())) {
    	auto s{std::make_shared<Node> ()};

    	s->set_state (d.second);
        s->set_father (n);
        s->set_action (d.first);
        s->set_path_cost (n->get_path_cost () + p.step_cost (n->get_state (), d.first, d.second));
        s->set_depth (n->get_depth () + 1);

    	sucessors.push_back (s);
    }

    return sucessors;
}

bool Search::is_not_in_closed (const std::string& s)
{
	for (auto e : closed_list)
		if (s == e)
			return false;

	return true;	
}

std::vector<Moves> Search::solution (const n_ptr& n)
{
	std::vector<Moves> path;

	if (!n->get_father ()) {
		path.push_back (n->get_action ());
		return path;
	}
	

    for (auto node = n; node->get_father () != nullptr; node = node->get_father ()) 
    	path.push_back (node->get_action ());

    std::reverse (path.begin (), path.end ());

    return path;
}

n_ptr Search::select_neighbor_randomly (const n_ptr& n, const EightPuzzle& p)
{
	if (is_not_in_closed (n->get_state ())) 
		closed_list.push_back (n->get_state ());

	std::vector<n_ptr> sucessors;

    for (auto d : p.sucessor_fun (n->get_state ())) {
    	auto s{std::make_shared<Node> ()};

    	s->set_state (d.second);
        s->set_action (d.first);

    	sucessors.push_back (s);
    }

    std::random_shuffle (sucessors.begin (), sucessors.end ());

    return sucessors.front ();
}

int Search::distance (const n_ptr& n, const EightPuzzle& p)
{
	return Functions (p.final_state ()).h (n);
}