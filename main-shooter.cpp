#include <iostream>
using std::cout;
#include <string>

#include "Shooter.h"
#include "Shooter.cpp"


int main(){
    Shooter cait("Rifle", 750, 2.5, 30, "Físico", "Caitlyn", "Atirador", {"Pácificadora de Piltover", "Às na Manga"});
    cout << cait;
    
    return 0;
}