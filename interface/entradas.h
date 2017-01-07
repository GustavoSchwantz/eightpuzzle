#ifndef ENTRADAS
#define ENTRADAS

#include <gtkmm/grid.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <array>
#include <string>
#include "entradainvalida.h"

class Entradas : public Gtk::Box {
public:
	Entradas ();
	~Entradas ();

    std::string get_inicial (); 
    std::string get_meta ();

private:
	bool verifica_entrada (const std::string& e);

    std::array<Gtk::Entry, 9> inicial, meta;
    Gtk::Grid grid0, grid1;
};

#endif