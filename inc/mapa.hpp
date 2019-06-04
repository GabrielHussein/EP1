#ifndef MAPA_HPP
#define MAPA_HPP

#include "barco.hpp"
#include <string>
#include <vector>

using namespace std;

class Mapa{
    private:
        const static int colunas=13;
        const static int linhas=13;
        char mapa[linhas][colunas];
        char mapa2[linhas][colunas];
    public:
        Mapa();
        ~Mapa();
        void criar_mapa();
        void print_mapa();
        void limpar_tela();
        void atualizar_mapa(int, int, int);
        void atualizar_mapa2(int, int, int);
};
#endif
