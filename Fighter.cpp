#include <iostream>

#include "Fighter.h"

Fighter::Fighter
(
    float chanceDesvio,
    float bonusDanoVida,
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
chanceDesvio(chanceDesvio),
bonusDanoVida(bonusDanoVida),
Melee( 
    armaduraInicial, 
    armaduraNivel, 
    mrInicial, 
    mrNivel,
    furtivo,
    nome,
    vidaIncial,
    escudoInicial,
    nomeHabilidades,
    habilitado){}

Fighter::Fighter(){
    RageUserStruct campeao = getChampRageUser();
    this->chanceDesvio = campeao.chanceDesvio;
    this->bonusDanoVida = campeao.bonusDanoVida;
}

Fighter::Fighter( const Fighter &other ):Melee(other){
    this->chanceDesvio = other.chanceDesvio;
    this->bonusDanoVida = other.bonusDanoVida;
}

ostream & operator<<( ostream &output, const Fighter &campeao ){
    campeao.printCampeao();
    output << "Chance de Desvio: " << campeao.chanceDesvio*100 <<'%'<< '\n' <<
    "Bônus de Dano: " << campeao.bonusDanoVida*100 <<'%';

    return output;
}

Fighter & Fighter::operator=(const Fighter &other){
    if(this != &other){
        this->chanceDesvio = other.chanceDesvio;
        this->bonusDanoVida = other.bonusDanoVida;
    }
    return *this;
}

bool Fighter::operator==(const Fighter &other) const{
    if( this->chanceDesvio != other.chanceDesvio || 
    this->bonusDanoVida != other.bonusDanoVida ) return false;

    return true;
}

bool Fighter::operator!=(const Fighter &other) const{
    if(*this == other) return false;

    return true;
}

void Fighter::operator!(){
    this->setHabilitado(!this->getHabilitado());
}

int Fighter::usarUltimate(){
    this->setArmaduraInicial(this->getArmaduraInicial()+(this->getArmaduraInicial()*this->getArmaduraNivel()));
    this->setMrInicial(this->getMrInicial()+(this->getMrInicial()*this->getMrNivel()));

    return 0;
}

void Fighter::furtividade(){
    this->setFurtivo();
}

void Fighter::setChanceDesvio( float chanceDesvio ){
    this->chanceDesvio += chanceDesvio;
}
void Fighter::setBonusDanoVida( float bonusDanoVida ){
    this->bonusDanoVida += bonusDanoVida;
}
float Fighter::getChanceDesvio(){
    return this->chanceDesvio;
}
float Fighter::getBonusDanoVida(){
    return this->bonusDanoVida;
}

void Fighter::sofrerDano( int danoBruto ){
    if(!this->getFurtivo()){
        int danoSofrido = danoBruto - this->getArmaduraInicial() - this->getMrInicial();
        cout << "Dano sofrido: " << danoSofrido << '\n';
        this->setVida( this->getVida() - danoSofrido );
    }
}