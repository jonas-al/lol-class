#include <iostream>
using std::cout;
#include <string>
#include "Ranged.h"
#include "Ranged.cpp"

int main(){
    Ranged syndra(700, 1.5, 30, "Magico", "Syndra", "Mago", {"Esfera Negra", "Poder Irrestrito"});
    Ranged syndra2;
    cout << syndra2;
    cout << '\n';
    cout << syndra;

    syndra2 = syndra;
    cout << '\n';
    cout << syndra2;

    return 0;
}