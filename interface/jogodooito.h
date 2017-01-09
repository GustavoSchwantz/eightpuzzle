#ifndef JOGO_DO_OITO
#define JOGO_DO_OITO 

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <vector>
#include <utility>
#include <string>
#include "radiobuttonbox.h"
#include "entradas.h"
#include "informacoes.h"
#include "caminho.h"
#include "../backend/search.h"
#include "../backend/eightpuzzle.h"
#include "../backend/moves.h"


class JogoDoOito : public Gtk::Window {
public:
	JogoDoOito ();
	~JogoDoOito ()
    {

    }

private:
	void iniciar_pressionado ();
    std::string formata_caminho (const std::vector<Moves>& c);

    Gtk::Box main_box;
    RadioButtonBox radiobuttons;
    Gtk::Frame opcao, estados;
    Entradas entradas;
    Gtk::Button iniciar;
    Informacoes info0, info1;
    Caminho caminho;
};

#endif