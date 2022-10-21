#include <iostream>
using std::cout;

#include <map>
using std::map;

#include <cstdlib>
#include <time.h>

#include "Partida.h"
#include "Partida.cpp"

int main(){
    Partida::AMAG blue;
    blue.abates = 5;
    blue.assistencias = 1;
    blue.mortes = 0;
    blue.gold = 5200;

    Partida::AMAG red;
    red.abates = 6;
    red.assistencias = 8;
    red.mortes = 1;
    red.gold = 3200;

    Partida partida1(1, blue, red, "2 minutos");
    cout << partida1;

    Partida partida2(2, blue, red, "3 minutos");
    cout << partida2;

    cout << "\nVerificando se os objetos são iguais: ";
    if(partida1.operator==(partida2) == 1){
        cout << "São iguais!!!";
    }else{cout << "São diferentes!!!";}

    cout << "\nIgualando os objetos e verficando a igualdade novamente: ";
    partida1.operator=(partida2);
    if(partida1.operator==(partida2) == 1){
        cout << "São iguais!!!";
    }else{cout << "São diferentes!!!";}

    return 0;
}

/*Id: 1
Duração: 2 minutos

Time Azul
Abates: 5
Assistencias: 1
Mortes: 0
Gold: 5200

Time Vermelho
Abates: 6
Assistencias: 8
Mortes: 1
Gold: 3200

Data da Partida: 21/10/2022

Jogadores!!!
Apelido: Resque
Partidas Jogadas: 21
Nível: 26
Nível Honra: 2
Elo: Prata I

Apelido: Sarah
Partidas Jogadas: 10
Nível: 15
Nível Honra: 2
Elo: Bronze II

Campeões!!!
Nome do Campeão: Lux
Função: Mago
Habilidade 1: Prisão Plasmática
Habilidade 2: Centelha Final
Cargas de Ultimate: 5

Nome do Campeão: Twitch
Função: Atirador
Habilidade 1: Contaminar
Habilidade 2: Passando Fogo
Cargas de Ultimate: 5

Id: 2
Duração: 3 minutos

Time Azul
Abates: 5
Assistencias: 1
Mortes: 0
Gold: 5200

Time Vermelho
Abates: 6
Assistencias: 8
Mortes: 1
Gold: 3200

Data da Partida: 21/10/2022

Jogadores!!!
Apelido: Felipe
Partidas Jogadas: 47
Nível: 52
Nível Honra: 2
Elo: Bronze III

Apelido: Resque
Partidas Jogadas: 32
Nível: 37
Nível Honra: 2
Elo: Bronze I

Campeões!!!
Nome do Campeão: Braum
Função: Suporte/Tank
Habilidade 1: Mordida do Inverno
Habilidade 2: Fissura Glacial
Cargas de Ultimate: 5

Nome do Campeão: Jinx
Função: Atirador
Habilidade 1: Zap!
Habilidade 2: Super Mega Missel da Morte
Cargas de Ultimate: 5

Verificando se os objetos são iguais: São diferentes!!!
Igualando os objetos e verficando a igualdade novamente: São iguais!!!*/