#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "mapa.hpp"
#include "barco.hpp"
#include "submarino.hpp"
#include "canoa.hpp"
#include "porta_avioes.hpp"
#include "partida.hpp"
#include <string>
#include <vector>
using namespace std;
class Jogador {
  private:
    int num_barcos;
    int pontos;
  public:
    Jogador();
    ~Jogador();
    int get_num_barcos();
    void set_num_barcos(int num_barcos);
    int get_pontos();
    void set_pontos(int pontos);
    int gerar_pontuacao();
    int gerar_barcos();
};

#endif
