# EP1 - OO 2019.1 (UnB - Gama)

&nbsp;&nbsp;Este projeto consiste em criar um jogo em C++ similar ao game Battleship (ou batalha naval), onde todas suas instruções, dicas e requisitos para a avaliação estão sendo descritos na [wiki](https://gitlab.com/oofga/eps/eps_2019_1/ep1/wikis/home) do repositório.

## Descrição do projeto
&nbsp;&nbsp;O projeto é uma implementação de um jogo chamado batalha naval, é amplamente conhecido no mundo todo. Nele, dois adversários batalham com o objetivo de destruir a frota inimiga, tentando adivinhar em quais posições seu algoz posicionou seus barcos e submarinos. Atualmente, com o advento dos jogos eletrônicos, é fácil encontrar versões digitais desse divertido passatempo.

* Embarcações
&nbsp;&nbsp;
Foram feitas três navegações diferentes para este projeto: Um porta-aviões, um submarino e uma canoa.
Porta-Aviões:
O porta-aviões possui 4 casas de comprimento e uma habilidade em que se é possível aleatoriamente refletir um míssel lançado contra uma de suas partes.

    Submarino:
O submarino possui 2 casas de comprimento e cada uma de suas partes possui 2 vidas.

    Canoa:
Uma embarcação simples, a canoa possui 1 casa de comprimento e não possui habilidade alguma.

* Regras e mapa:\
&nbsp;&nbsp;O jogo é feito para dois jogadores humanos e um vencedor é definido assim que um dos dois chegar a 12 pontos, sendo que cada ponto é definido pelo número de embarcações completamente destruídas.
Há apenas um mapa pré-definido extraído de "doc/map_1.txt", este arquivo que foi modificado para facilitar a leitura do mesmo durante o programa.

* Como jogar:\
&nbsp;&nbsp;Assim que compilado o código o jogo já iniciará com o mapa sem mostrar onde estão as    embarcações, então o primeiro jogador deve inserir suas coordenadas para lançar um míssel no campo do jogador inimigo, assim que inseridas seguindo as instruções de código as coordenadas então o míssel será lançado, uma mensagem aparecerá no topo da tela acima dos dois campos indicando o resultado da ação, seja ela um tiro na água, um tiro em uma navegação existente e em qual navegação você atirou e se alguma das habilidades entrou em efeito, ou também se você está atirando em uma área já acertada anteriormente. Se você acertar em uma embarcação e esta parte for destruída o campo substituirá a visualização padrão por um caractere que representa o tipo de navegação acertado, sendo 'C' para canoa, 'S' para submarino e 'P' para porta-aviões.

## Instruções de execução

&nbsp;&nbsp;Após conferir se o "map_1.txt" está no local correto para leitura segue-se este passo a passo.
Para construir os objetos definidos pelo projeto, juntamente com o binário para realizar a execução:
```
$ make
```

Para executar o binário criado e iniciar o programa:
```
$ make run
```
## Observações

&nbsp;&nbsp;Devido ao começo tardio da atividade não foi possível cobrir algumas falhas, alguns problemas conhecidos são:

Ao colocar algo diferente de um inteiro no momento de definir as coordenadas ocorrerá um erro que rodará infinitamente devido a condição de finalização de jogo ser baseada na pontuação, logo a falha compromete o funcionamento do programa e é necessário fechar o terminal.\
Ao tentar acertar uma parte anteriormente destruída o programa irá pedir para o jogador inserir novamente as coordenadas de alguma área não destruída/vazia, o programa se porta corretamente nesta parte porém ao colocar coordenadas válidas serão impressas n mapas, sendo n o número de vezes em que o jogador insere coordenadas repetidas, porém esta falha não compromete o funcionamento do programa.\
Não consegui colocar a implementação de destruição do porta-aviões por porta-aviões singular, apenas por meio de um auxiliar, logo se 4 casas de 4 porta-aviões distintos forem destruídos o jogo conta como 1 ponto.
