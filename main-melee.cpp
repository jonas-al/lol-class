#include <iostream>
using std::cout;
#include <string>
#include "Melee.h"
#include "Melee.cpp"

int main(){
    Melee sett(70, 1.2, 70, 2.3, false, "Físico", "Sett", "Lutador", {"Quebra-Crânio", "Hora do Show"});
    cout << sett;

    return 0;
}