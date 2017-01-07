#include "entradas.h"

Entradas::Entradas ()
{
	set_border_width (10);

	inicial[0].set_width_chars (1);
	inicial[1].set_width_chars (1);
	inicial[2].set_width_chars (1);
	inicial[3].set_width_chars (1);
	inicial[4].set_width_chars (1);
	inicial[5].set_width_chars (1);
	inicial[6].set_width_chars (1);
	inicial[7].set_width_chars (1);
	inicial[8].set_width_chars (1);

	inicial[0].set_max_length (1);
	inicial[1].set_max_length (1);
	inicial[2].set_max_length (1);
	inicial[3].set_max_length (1);
	inicial[4].set_max_length (1);
	inicial[5].set_max_length (1);
	inicial[6].set_max_length (1);
	inicial[7].set_max_length (1);
	inicial[8].set_max_length (1);

	grid0.add (inicial[0]);
	grid0.add (inicial[1]);
	grid0.add (inicial[2]);
	grid0.attach (inicial[3], 0, 1, 1, 1);
	grid0.attach (inicial[4], 1, 1, 1, 1);
	grid0.attach (inicial[5], 2, 1, 1, 1);
	grid0.attach (inicial[6], 0, 2, 1, 1);
	grid0.attach (inicial[7], 1, 2, 1, 1);
	grid0.attach (inicial[8], 2, 2, 1, 1);

	pack_start (grid0, Gtk::PACK_EXPAND_PADDING);

	meta[0].set_width_chars (1);
	meta[1].set_width_chars (1);
	meta[2].set_width_chars (1);
	meta[3].set_width_chars (1);
	meta[4].set_width_chars (1);
	meta[5].set_width_chars (1);
	meta[6].set_width_chars (1);
	meta[7].set_width_chars (1);
	meta[8].set_width_chars (1);

	meta[0].set_max_length (1);
	meta[1].set_max_length (1);
	meta[2].set_max_length (1);
	meta[3].set_max_length (1);
	meta[4].set_max_length (1);
	meta[5].set_max_length (1);
	meta[6].set_max_length (1);
	meta[7].set_max_length (1);
	meta[8].set_max_length (1);

	grid1.add (meta[0]);
	grid1.add (meta[1]);
	grid1.add (meta[2]);
	grid1.attach (meta[3], 0, 1, 1, 1);
	grid1.attach (meta[4], 1, 1, 1, 1);
	grid1.attach (meta[5], 2, 1, 1, 1);
	grid1.attach (meta[6], 0, 2, 1, 1);
	grid1.attach (meta[7], 1, 2, 1, 1);
	grid1.attach (meta[8], 2, 2, 1, 1);

	pack_start (grid1, Gtk::PACK_EXPAND_PADDING);
}

Entradas::~Entradas ()
{

}

std::string Entradas::get_inicial ()
{
	std::string estado;

	for (int i = 0; i != 9; ++i)
		estado += inicial[i].get_text (); 

	return (verifica_entrada (estado)) ? estado : throw EntradaInvalida{"Entrada Inválida!"};
}

std::string Entradas::get_meta ()
{
	std::string estado;

	for (int i = 0; i != 9; ++i)
		estado += meta[i].get_text (); 
	
	return (verifica_entrada (estado)) ? estado : throw EntradaInvalida{"Entrada Inválida!"};
}

bool Entradas::verifica_entrada (const std::string& e)
{
	std::string modelo ("012345678");

	for (const auto& c : modelo)
		if (e.find (c) == std::string::npos)
			return false;

    return true;		
}