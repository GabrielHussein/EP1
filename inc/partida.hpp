#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "mapa.hpp"
#include "barco.hpp"
#include "submarino.hpp"
#include "canoa.hpp"
#include "porta_avioes.hpp"
#include "jogador.hpp"
#include <string>
#include <vector>
#include <time.h>
#include <utility>

using namespace std;

class Partida{
  private:
    const static int colunas=13;
    const static int linhas=13;
    string mapa_atualizado[linhas][colunas];
    int posicao_player1[linhas][colunas] = {0};
    int posicao_player2[linhas][colunas] = {0};
    int aux_sub[linhas][colunas];
    int aux_porta;
    Mapa att_tela;
    Porta_Avioes porta_a;
    Submarino sub;
    Canoa can;
    Jogador jogador1;
    Jogador jogador2;
  public:
    Partida();
    ~Partida();
    void ler_mapa();
    void gerar_tela();
    void terminar_jogo();
    void atirar_player1();
    void atirar_player2();
    bool determinar_vencedor();
    void colocar_canoa(int , int , int );
    void colocar_submarino(int , int , int , string);
    void colocar_porta_avioes(int , int , int, string);
};

#endif
