#include "../inc/partida.hpp"
#include "../inc/mapa.hpp"
#include "../inc/barco.hpp"
#include "../inc/submarino.hpp"
#include "../inc/canoa.hpp"
#include "../inc/porta_avioes.hpp"
#include "../inc/jogador.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Jogador::Jogador(){
  num_barcos = 12;
  pontos = 0;
}

Jogador::~Jogador(){}

int Jogador::get_num_barcos(){
  return num_barcos;
}

void Jogador::set_num_barcos(int num_barcos){
  this->num_barcos = num_barcos;
}

int Jogador::get_pontos(){
  return pontos;
}

void Jogador::set_pontos(int pontos){
  this->pontos = pontos;
}

int Jogador::gerar_pontuacao(){
  pontos = pontos + 1;
  return pontos;
}

int Jogador::gerar_barcos(){
  num_barcos = num_barcos - 1;
  return num_barcos;
}
