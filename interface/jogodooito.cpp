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

    iniciar.signal_clicked ().connect (sigc::mem_fun (*this, &JogoDoOito::on_buttom_clicked));

    info0.set_output (0);
    info1.set_output (0);

 	show_all_children ();
}   

JogoDoOito::~JogoDoOito ()
{
	
}

void JogoDoOito::on_buttom_clicked ()
{
	if (radiobuttons.get_algoritmo () == Algoritmo::hill) 
		std::cout << "\nAlgoritmo: Hill Climbing" << std::endl;
	else if (radiobuttons.get_algoritmo () == Algoritmo::profundidade) 
		std::cout << "\nAlgoritmo: Busca em Pofundidade" << std::endl;
	else if (radiobuttons.get_algoritmo () == Algoritmo::estrela) 
		std::cout << "\nAlgoritmo: A*" << std::endl;
	else
		std::cout << "\nAlgoritmo: Busca em Largura" << std::endl;

	try {
	
	std::cout << "Estado Inicial " << entradas.get_inicial () << std::endl;
	std::cout << "Estado Meta " << entradas.get_meta () << std::endl;

    } catch (EntradaInvalida e) {
        std::cout << e.what () << std::endl;
    }

    info0.set_output (42);
    info1.set_output (42);
}