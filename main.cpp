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