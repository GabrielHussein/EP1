#include "../inc/mapa.hpp"
#include "../inc/partida.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
Mapa::Mapa(){
}

Mapa::~Mapa(){
}

void Mapa::criar_mapa(){
  for (int i=0; i<linhas; i++){
    for (int j=0; j<colunas; j++){
      mapa[i][j] = '_';
      mapa2[i][j] = '_';
    }
  }
}
void Mapa::print_mapa(){
  int coordenadas = 0;
  cout << "Campo do jogador 1" << endl;
  cout << "    A  B  C  D  E  F  G  H  I  J  K  L  M" << endl;
  for (int i=0; i<linhas; i++){
    cout << coordenadas << " ";
    coordenadas++;
    if (coordenadas<11){
      cout << " ";
    }
    for (int j=0; j<colunas; j++){
      cout << "|";
      cout << mapa[i][j];
      cout << "|";
    }
    cout << endl;
  }
  coordenadas = 0;
  cout << "Campo do jogador 2" << endl;
  cout << "    A  B  C  D  E  F  G  H  I  J  K  L  M" << endl;
  for (int i=0; i<linhas; i++){
    cout << coordenadas << " ";
    coordenadas++;
    if (coordenadas<11){
      cout << " ";
    }
    for (int j=0; j<colunas; j++){
      cout << "|";
      cout << mapa2[i][j];
      cout << "|";
    }
    cout << endl;
  }
}
void Mapa::atualizar_mapa(int p1, int linha, int coluna){
      int i = linha;
      int j = coluna;
      if (p1 == 0){
        mapa[i][j] = '_';
      }
      else if (p1 == 6){
        mapa[i][j] = 'P';
      }
      else if (p1 == 5){
        mapa[i][j] = 'S';
      }
      else if (p1 == 4){
        mapa[i][j] = 'C';
      }
    }
void Mapa::atualizar_mapa2(int p2, int linha, int coluna){
      int i = linha;
      int j = coluna;
      if (p2 == 0){
        mapa2[i][j] = '_';
      }
      else if (p2 == 6){
        mapa2[i][j] = 'P';
      }
      else if (p2 == 5){
        mapa2[i][j] = 'S';
      }
      else if (p2 == 4){
        mapa2[i][j] = 'C';
      }
    }
void Mapa::limpar_tela(){
  system("clear");
}
