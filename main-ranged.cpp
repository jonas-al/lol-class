#include <iostream>
using std::cout;
#include <string>
#include "Ranged.h"
#include "Ranged.cpp"

int main(){
    Ranged syndra(700, 1.5, 30, "Magico", "Syndra", "Qenga", {"Esfera Negra", "Poder Irrestrito"});
    Ranged syndra2;
    cout << syndra2;
    //cout << syndra;
    //syndra.operator!();
    //cout << syndra;
    //cout << syndra2;

    return 0;
}