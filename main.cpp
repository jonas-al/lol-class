#include "Partida.h"
#include "Partida.cpp"
#include "Campeao.h"
#include "Campeao.cpp"
#include "Ranged.h"
#include "Ranged.cpp"
#include "Mage.h"
#include "Mage.cpp"
#include "Shooter.h"
#include "Shooter.cpp"
#include "Support.h"
#include "Support.cpp"
#include "Caster.h"
#include "Caster.cpp"
#include "Melee.h"
#include "Melee.cpp"
#include "Fighter.h"
#include "Fighter.cpp"
#include "Tank.h"
#include "Tank.cpp"
#include "RageUser.h"
#include "RageUser.cpp"

int main(){
    Campeao *teste1 = new Caster();
    Campeao *teste2 = new RageUser();
    
    vector< Campeao * > campeoes;
    campeoes.push_back(teste1);
    campeoes.push_back(teste2);

    Campeao::batalha( campeoes );
    return 0;
}