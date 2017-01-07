#ifndef INFORMACOES 
#define INFORMACOES 

#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <string>

class Informacoes : public Gtk::Box {
public:
	Informacoes (const std::string& f);
	~Informacoes ();

	void set_output (const int& v);

private:
	Gtk::Label frase;
	Gtk::Entry valor;
};

#endif