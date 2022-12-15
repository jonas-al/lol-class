#include <iostream>
#include "EnergyUser.h"

EnergyUser::EnergyUser(
    int energiaInical,
    int energiaRegen,
    int armaduraInicial, 
    float armaduraNivel, 
    int mrInicial, 
    float mrNivel,
    bool furtivo,
    const string &nome,
    int vidaIncial,
    vector<string> nomeHabilidades,
    bool habilitado
):
energiaInical(energiaInical),
energiaRegen(energiaRegen),
Melee(
    armaduraInicial,
    armaduraNivel,
    mrInicial,
    mrNivel,
    furtivo,
    nome,
    vidaIncial,
    nomeHabilidades,
    habilitado
){}

void EnergyUser::usarUltimate(){
    cout << "usando ultimate... - EnergyUser" << '\n';
}

void EnergyUser::usarHabilidade(){
    cout << "usando uma habilidade... - EnergyUser" << '\n';
}

void EnergyUser::subirNivel(){
    cout << "upando... - EnergyUser" << '\n';
}

void EnergyUser::abate(){
    cout << "matei um... - EnergyUser" << '\n';
}

void EnergyUser::assistencia(){
    cout << "roubaram minha kill :( - EnergyUser" << '\n';
}

void EnergyUser::avanco(){
    cout << "vou te pegar haha :# - EnergyUser" << '\n';
}

void EnergyUser::furtividade(){
    cout << "me escondi :3 - EnergyUser" << '\n';
}

void EnergyUser::recarregar(){
    cout << "iphone - EnergyUser" << '\n';
}
void EnergyUser::assasinar(){
    cout << "vo ti matar - EnergyUser" << '\n';
}
