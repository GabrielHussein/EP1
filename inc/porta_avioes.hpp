#ifndef PORTA_AVIOES_HPP
#define PORTA_AVIOES_HPP

#include <string>
#include <time.h>
#include "../inc/barco.hpp"

using namespace std;

class Porta_Avioes : public Barco {
    private:
        int habilidade;
    public:
        Porta_Avioes();
        ~Porta_Avioes();
        int refletir_missel();
        int get_casas();
        void set_casas(int casas);
};
#endif
