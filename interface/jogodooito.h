#ifndef JOGO_DO_OITO
#define JOGO_DO_OITO 

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <vector>
#include <utility>
#include "radiobuttonbox.h"
#include "entradas.h"
#include "informacoes.h"
#include "caminho.h"


class JogoDoOito : public Gtk::Window {
public:
	JogoDoOito ();
	~JogoDoOito ();

private:
	void on_buttom_clicked ();

    Gtk::Box main_box;
    RadioButtonBox radiobuttons;
    Gtk::Frame opcao, estados;
    Entradas entradas;
    Gtk::Button iniciar;

    Algoritmo algoritmo;
    Informacoes info0, info1;
    Caminho caminho;
};

#endif