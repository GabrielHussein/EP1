#include "../inc/porta_avioes.hpp"
#include "../inc/barco.hpp"
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

Porta_Avioes::Porta_Avioes(){
  casas = 4;
  nome = 'P';
  vida = 1;
}
Porta_Avioes::~Porta_Avioes(){
}
int Porta_Avioes::refletir_missel(){
  habilidade = rand() % 100 + 1;
  return habilidade;
}
int Porta_Avioes::get_casas(){
  return casas;
}

void Porta_Avioes::set_casas(int casas){
  this->casas = casas;
}
