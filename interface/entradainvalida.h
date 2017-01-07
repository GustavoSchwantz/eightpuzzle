#ifndef ENTRADA_INVALIDA
#define ENTRADA_INVALIDA

#include <string>
#include <stdexcept>

class EntradaInvalida : public std::runtime_error {
public:
	EntradaInvalida (const std::string& s)
	    : std::runtime_error (s)
	{

	}    
};

#endif 