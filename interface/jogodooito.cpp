#include "jogodooito.h"
#include <iostream>

JogoDoOito::JogoDoOito ()
    :main_box (Gtk::ORIENTATION_VERTICAL),
    opcao ("Selecione um algoritmo de busca"),
    estados ("Informe o estado inicial e o estado meta"),
    iniciar ("Iniciar Busca"),
    info0 ("Número de Estados Testados: "),
    info1 ("Número de Estados para Solução: ")
{
	set_title ("Quebra-Cabeça do Oito");
	set_border_width (15);

 	add (main_box);

 	opcao.add (radiobuttons);
 	estados.add (entradas);

 	opcao.set_border_width (5);
 	estados.set_border_width (5);

    iniciar.set_border_width (5);

	main_box.pack_start (opcao);
	main_box.pack_start (estados);
	main_box.pack_start (iniciar);
	main_box.pack_start (info0);
	main_box.pack_start (info1);
	main_box.pack_start (caminho);

    iniciar.signal_clicked ().connect (sigc::mem_fun (*this, &JogoDoOito::iniciar_pressionado));

    info0.set_output (0);
    info1.set_output (0);

 	show_all_children ();
}   

void JogoDoOito::iniciar_pressionado ()
{
	Search search;
    std::vector<Moves> path;

	try {

	    if (radiobuttons.get_algoritmo () == Algoritmo::hill) {
	        path = search.random_restart_hill_climbing (EightPuzzle (entradas.get_inicial (), entradas.get_meta ()));	
	        info0.set_output (search.get_closed_list_size ());
            info1.set_output (path.size ());
            caminho.set_path (formata_caminho (path));
	    }
	    else if (radiobuttons.get_algoritmo () == Algoritmo::profundidade) {
            path = search.iterative_deepening_search (EightPuzzle (entradas.get_inicial (), entradas.get_meta ()));	
	        info0.set_output (search.get_closed_list_size () + 1);
            info1.set_output (path.size ());
            caminho.set_path (formata_caminho (path));
	    }
	    else if (radiobuttons.get_algoritmo () == Algoritmo::estrela) {
            path = search.a_star (EightPuzzle (entradas.get_inicial (), entradas.get_meta ()));	
	        info0.set_output (search.get_closed_list_size () + 1);
            info1.set_output (path.size ());
            caminho.set_path (formata_caminho (path));
	    }
	    else {
	    	path = search.breadth_first_search (EightPuzzle (entradas.get_inicial (), entradas.get_meta ()));	
	        info0.set_output (search.get_closed_list_size () + 1);
            info1.set_output (path.size ());
            caminho.set_path (formata_caminho (path));
	    }

    } catch (EntradaInvalida) {
    	caminho.set_path ("Entrada incorreta! Por favor, digite uma configuração válida.");
    }
}

std::string JogoDoOito::formata_caminho (const std::vector<Moves>& c)
{
	if (!c.size ())
		return "O estado meta não é alcançável à partir desse estado inicial.";

	std::string cam_for;

	for (const auto& m : c) {
		if (m == Moves::no_action)
			cam_for += "->NO ACTION";
		if (m == Moves::left)
			cam_for += "->LEFT";
		if (m == Moves::right)
			cam_for += "->RIGHT";
		if (m == Moves::up)
			cam_for += "->UP";
		if (m == Moves::down)
			cam_for += "->DOWN";
	}

	return cam_for;
}