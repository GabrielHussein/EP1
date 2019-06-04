#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include "../inc/barco.hpp"
#include "../inc/submarino.hpp"
#include "../inc/canoa.hpp"
#include "../inc/porta_avioes.hpp"
#include "../inc/mapa.hpp"
#include "../inc/partida.hpp"
#include "../inc/jogador.hpp"

using namespace std;

int main(int argc, char *argv[]){
    srand(time(NULL));
    Partida * partida = new Partida();
    partida->ler_mapa();
    partida->gerar_tela();
    while(partida->determinar_vencedor() == false){
    partida->atirar_player1();
    partida->atirar_player2();
  }
    cout << "Obrigado por jogar." << endl;
  delete partida;
    return 0;
}
