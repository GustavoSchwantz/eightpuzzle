#include "informacoes.h"

Informacoes::Informacoes (const std::string& f)
    :frase (f)
{
	set_border_width (5);

	valor.set_overwrite_mode (false);

	pack_start (frase, Gtk::PACK_SHRINK);
	pack_end (valor, Gtk::PACK_SHRINK);
}   

Informacoes::~Informacoes ()
{

} 

void Informacoes::set_output (const int& v)
{
	valor.set_text (std::to_string (v));
}