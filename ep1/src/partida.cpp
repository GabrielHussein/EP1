#include "../inc/partida.hpp"
#include "../inc/mapa.hpp"
#include "../inc/barco.hpp"
#include "../inc/submarino.hpp"
#include "../inc/canoa.hpp"
#include "../inc/porta_avioes.hpp"
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include <utility>
#include <string>
using namespace std;
Partida::Partida(){
}
Partida::~Partida(){
}
void Partida::gerar_tela(){
  att_tela.criar_mapa();
  att_tela.print_mapa();
}

void Partida::atirar_player1(){
  jogador1.set_pontos(12 - jogador2.get_num_barcos());
  int pontos = jogador1.get_pontos();
  cout << "Vez do primeiro jogador. Pontuação atual: "<< pontos << endl;
  int i = 0, j = 0;
  cout << "Escolha uma linha: " << endl;
  cin >> i;
  cout << "Escolha uma coluna(Coloque o inteiro correspondente a letra, considere A=0): " << endl;
  cin >> j;
  if ((i<0 || i>12) || (j<0 || j>12)){
    cout << "Por favor coloque uma linha e/ou coluna válida." << endl;
    atirar_player1();
  }
  att_tela.limpar_tela();
  if(posicao_player2[i][j] == 4 || posicao_player2[i][j] == 5 || posicao_player2[i][j] == 6){
    att_tela.print_mapa();
    cout << "Esta parte já foi acertada, escolha outro local." << endl;
    atirar_player1();
  }
  else if(posicao_player2[i][j] == 1){
    int num_aleatorio = porta_a.refletir_missel();
    if (num_aleatorio < 51){
      cout << "Você destruiu uma parte de um Porta-Aviões!" << endl;
      posicao_player2[i][j] = 6;
      aux_porta++;
      if(aux_porta == 4){
        jogador2.set_num_barcos(12 - (jogador1.get_pontos()+1));
        aux_porta = 0;
      }
  }
    if (num_aleatorio >= 51){
      cout << "O Porta-Aviões refletiu o míssel." << endl;
   }
  }
  else if(posicao_player2[i][j] == 2){
    if(aux_sub[i][j] == 0){
      aux_sub[i][j] = posicao_player2[i][j];
    }
    if (aux_sub[i][j] == 2){
      aux_sub[i][j] = aux_sub[i][j] - 1;
      cout << "Você acertou um Submarino, ele ainda possui 1 de vida neste local, acerte de novo para revelá-lo." << endl;
  }
    else if (aux_sub[i][j] == 1){
     cout << "Você destruiu uma parte do Submarino!" << endl;
     posicao_player2[i][j] = 5;
     if(posicao_player2[i-1][j] == 5 || posicao_player2[i+1][j] == 5 || posicao_player2[i][j+1] == 5 || posicao_player2[i][j-1] == 5){
       jogador2.set_num_barcos(12 - (jogador1.get_pontos()+1));
     }
     aux_sub[i][j] = 0;
    }
  }
  else if(posicao_player2[i][j] == 3){
    cout << "Você destruiu uma Canoa!" << endl;
    posicao_player2[i][j] = 4;
    jogador2.set_num_barcos(12 - (jogador1.get_pontos()+1));
  }
  else if(posicao_player2[i][j] == 0){
    cout << "Você errou." << endl;
  }
  int embarcacao2 = posicao_player2[i][j];
  att_tela.atualizar_mapa2(embarcacao2, i, j);
  att_tela.print_mapa();
}

void Partida::atirar_player2(){
  jogador2.set_pontos(12 - jogador1.get_num_barcos());
  int pontos1 = jogador2.get_pontos();
  int i = 0, j = 0;
  cout << "Vez do segundo jogador. Pontuação atual: "<< pontos1 << endl;
  cout << "Escolha uma linha: " << endl;
  cin >> i;
  cout << "Escolha uma coluna(Coloque o inteiro correspondente a letra, considere A=0): " << endl;
  cin >> j;
  if ((i<0 || i>12) || (j<0 || j>12)){
    cout << "Por favor coloque uma linha e/ou coluna válida." << endl;
    atirar_player2();
  }
  att_tela.limpar_tela();
  if(posicao_player1[i][j] == 4 || posicao_player1[i][j] == 5 || posicao_player1[i][j] == 6){
    cout << "Esta parte já foi acertada, escolha outro local." << endl;
    atirar_player2();
  }
  else if(posicao_player1[i][j] == 1){
    int num_aleatorio = porta_a.refletir_missel();
    if (num_aleatorio < 51){
      cout << "Você destruiu uma parte de um Porta-Aviões!" << endl;
      posicao_player1[i][j] = 6;
      aux_porta++;
      if(aux_porta == 4){
        jogador1.set_num_barcos(12 - (jogador2.get_pontos()+1));
        aux_porta = 0;
      }
  }
    if (num_aleatorio >= 51){
      cout << "O Porta-Aviões refletiu o míssel." << endl;
   }
  }
  else if(posicao_player1[i][j] == 2){
    if(aux_sub[i][j] == 0){
      aux_sub[i][j] = posicao_player1[i][j];
    }
    if (aux_sub[i][j] == 2){
      aux_sub[i][j] = aux_sub[i][j] - 1;
      cout << "Você acertou um Submarino, ele ainda possui 1 de vida neste local, acerte de novo para revelá-lo." << endl;
  }
    else if (aux_sub[i][j] == 1){
     cout << "Você destruiu uma parte do Submarino!" << endl;
     posicao_player1[i][j] = 5;
     if(posicao_player1[i-1][j] == 5 || posicao_player1[i+1][j] == 5 || posicao_player1[i][j+1] == 5 || posicao_player1[i][j-1] == 5){
       jogador1.set_num_barcos(12 - (jogador2.get_pontos()+1));
     }
     aux_sub[i][j] = 0;
    }
  }
  else if(posicao_player1[i][j] == 3){
    cout << "Você destruiu uma Canoa!" << endl;
    posicao_player1[i][j] = 4;
    jogador1.set_num_barcos(12 - (jogador2.get_pontos()+1));
  }
  else if(posicao_player1[i][j] == 0){
    cout << "Você errou." << endl;
  }
  int embarcacao =  posicao_player1[i][j];
  att_tela.atualizar_mapa(embarcacao, i, j);
  att_tela.print_mapa();
}

bool Partida::determinar_vencedor(){
  bool jogador1_vencedor = false;
  bool jogador2_vencedor = false;
  if (jogador1.get_pontos() == 12){
    jogador1_vencedor = true;
    cout << "O jogador 1 venceu a partida, parabéns!" << endl;
    return jogador1_vencedor;
  }
  else if (jogador2.get_pontos() == 12){
    jogador2_vencedor = true;
    cout << "O jogador 2 venceu a partida, parabéns!" << endl;
    return jogador2_vencedor;
  }
  return false;
}

void Partida::ler_mapa(){
int aux = -1;
ifstream leitura_mapa;
leitura_mapa.open("doc/map_1.txt");
  if (leitura_mapa.is_open()){
    while (!leitura_mapa.eof()){
     string nome1, sentido1, largura, altura;
     int linha, coluna;
     getline(leitura_mapa, largura);
     if (largura[0]=='#' || largura==""){
       continue;
     }
     istringstream linha_arquivo {
       largura
     };
     linha_arquivo >> largura;
     linha_arquivo >> altura;
     linha = stoi(largura);
     coluna = stoi(altura);
     linha_arquivo >> nome1;
     linha_arquivo >> sentido1;
     aux++;
     if(nome1 == "canoa"){
       colocar_canoa(linha, coluna, aux);
     }
     else if(nome1 == "submarino"){
       colocar_submarino(linha, coluna, aux, sentido1);
     }
     else if(nome1 == "porta-avioes"){
       colocar_porta_avioes(linha, coluna, aux, sentido1);
     }
    }
  }
      leitura_mapa.close();
}

void Partida::colocar_canoa(int i, int j, int contador){
  if (contador<6){
    posicao_player1[i][j] = 3;
  }
  else if (contador>=6){
    posicao_player2[i][j] = 3;
  }
}

void Partida::colocar_submarino(int i, int j, int contador, string sentido1){
  if(contador>5 && contador<10){
    posicao_player1[i][j] = 2;
  if (sentido1 == "cima"){
    posicao_player1[i-1][j] = 2;
  }
  if (sentido1 == "baixo"){
    posicao_player1[i+1][j] = 2;
  }
  if (sentido1 == "esquerda"){
    posicao_player1[i][j-1] = 2;
  }
  if (sentido1 == "direita"){
    posicao_player1[i][j+1] = 2;
  }
}
else if(contador>=10){
  posicao_player2[i][j] = 2;
    if (sentido1 == "cima"){
      posicao_player2[i+1][j] = 2;
}
    if (sentido1 == "baixo"){
      posicao_player2[i-1][j] = 2;
}
    if (sentido1 == "esquerda"){
      posicao_player2[i][j-1] = 2;
    }
    if (sentido1 == "direita"){
      posicao_player2[i][j+1] = 2;
    }
    }
}
void Partida::colocar_porta_avioes(int i, int j, int contador, string sentido1){
  if(contador>9 && contador<12){
    posicao_player1[i][j] = 1;
    if (sentido1 == "cima"){
      posicao_player1[i-1][j] = 1;
      posicao_player1[i-2][j] = 1;
      posicao_player1[i-3][j] = 1;
    }
    if (sentido1 == "baixo"){
      posicao_player1[i+1][j] = 1;
      posicao_player1[i+2][j] = 1;
      posicao_player1[i+3][j] = 1;
    }
    if (sentido1 == "esquerda"){
      posicao_player1[i][j-1] = 1;
      posicao_player1[i][j-2] = 1;
      posicao_player1[i][j-3] = 1;
    }
    if (sentido1 == "direita"){
      posicao_player1[i][j+1] = 1;
      posicao_player1[i][j+2] = 1;
      posicao_player1[i][j+3] = 1;
    }
}
  else if(contador>=12){
    posicao_player2[i][j] = 1;
    if (sentido1 == "cima"){
      posicao_player2[i-1][j] = 1;
      posicao_player2[i-2][j] = 1;
      posicao_player2[i-3][j] = 1;
    }
    if (sentido1 == "baixo"){
      posicao_player2[i+1][j] = 1;
      posicao_player2[i+2][j] = 1;
      posicao_player2[i+3][j] = 1;
    }
    if (sentido1 == "esquerda"){
      posicao_player2[i][j-1] = 1;
      posicao_player2[i][j-2] = 1;
      posicao_player2[i][j-3] = 1;
    }
    if (sentido1 == "direita"){
      posicao_player2[i][j+1] = 1;
      posicao_player2[i][j+2] = 1;
      posicao_player2[i][j+3] = 1;
    }
  }
}
