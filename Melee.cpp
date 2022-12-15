#include "Melee.h"

Melee::Melee(
    int armaduraInicial, 
    float armaduraNivel, 
    int mrInicial, 
    float mrNivel,
    bool furtivo,
    const string &nome,
    int vidaIncial,
    int escudoInicial,
    vector<string> nomeHabilidades,
    bool habilitado
):
armaduraInicial(armaduraInicial),
armaduraNivel(armaduraNivel),
mrInicial(mrInicial),
mrNivel(mrNivel),
furtivo(furtivo),
Campeao(nome, vidaIncial, escudoInicial, nomeHabilidades, habilitado){}

Melee::Melee():
armaduraInicial(1),
armaduraNivel(.1),
mrInicial(1),
mrNivel(.1),
furtivo(false){};

Melee::Melee( const Melee &other ):Campeao(other){
    this->armaduraInicial = other.armaduraInicial;
    this->armaduraNivel = other.armaduraNivel;
    this->mrInicial = other.mrInicial;
    this->furtivo = other.furtivo;
}

Melee::~Melee(){}

void Melee::setArmaduraInicial( int armadura ){
    this->armaduraInicial += armadura;
}
void Melee::setMrInicial( int mr ){
    this->mrInicial += mr;
}
void Melee::setFurtivo(){
    this->furtivo = !this->furtivo;
}

void Melee::printCampeao() const{
    Campeao::printCampeao();
    cout << "Armadura Inicial: " << this->armaduraInicial << '\n';
    cout << "Armadura Nível: " << this->armaduraNivel << '\n';
    cout << "Resistência Mágica Inicial: " << this->mrInicial << '\n';
    cout << "Resistência Mágica Nível: " << this->mrNivel << '\n';
}