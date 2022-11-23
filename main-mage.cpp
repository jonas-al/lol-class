#include <iostream>
using std::cout;
#include <string>

#include "Mage.h"
#include "Mage.cpp"


int main(){
    Mage lux("Luz", 750, 2.5, 30, "Mágico", "Lux", "Mago", {"Prisão Plasmática", "Centelha Final"});
    cout << lux;
    
    return 0;
}