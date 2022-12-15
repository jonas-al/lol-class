#include <iostream>
#include "Mage.h"

Mage::Mage
(
    const string &tipoMagia,
    float penetracaoMagica,
    int alcanceInicial, 
    float alcanceNivel, 
    int resistencias, 
    const string &tipoDano,
    int manaInicial,
    int manaNivel,
    int manaRegen,
    const string &nome,
    int vidaIncial,
    int escudoInicial,
    vector<string> nomeHabilidades,
    bool habilitado
):
tipoMagia(tipoMagia),
penetracaoMagica(penetracaoMagica),
Ranged( 
    alcanceInicial, 
    alcanceNivel, 
    resistencias, 
    tipoDano,
    manaInicial,
    manaNivel,
    manaRegen,
    nome,
    vidaIncial,
    escudoInicial,
    nomeHabilidades,
    habilitado
){}

Mage::Mage():tipoMagia("teste"),
penetracaoMagica(.1){}

Mage::Mage( const Mage &other ):Ranged(other){
    this->tipoMagia = other.tipoMagia;
    this->penetracaoMagica = other.penetracaoMagica;
}

ostream & operator<<( ostream &output, const Mage &campeao ){
    campeao.printCampeao( );
    output << "Tipo Mágia: " << campeao.tipoMagia;
    return output;
}

Mage & Mage::operator=(const Mage &other){
    if(this != &other){
        this->tipoMagia = other.tipoMagia;
        this->penetracaoMagica = other.penetracaoMagica;
    }
    return *this;
}

bool Mage::operator==(const Mage &other) const{
    if(this->tipoMagia != other.tipoMagia || this->penetracaoMagica != other.penetracaoMagica) return false;
    return true;
}

bool Mage::operator!=(const Mage &other) const{
    if(*this == other) return false;
    return true;
}

void Mage::operator!(){
    this->setHabilitado(!this->getHabilitado());
}

int Mage::usarUltimate(){
    cout << "usarUltimate... - Mage" << '\n';
    this->setAlcanceInicial(this->getAlcanceInicial()+(this->getAlcanceInicial()*this->getAlcanceNivel()));
    return 0;
}

void Mage::sofrerDano( int danoSofrido ){
    cout << "Dano sofrido: " << danoSofrido << '\n';
    this->setVida(this->getVida() - danoSofrido);
}

void Mage::afastar(){
    this->setAlcanceInicial(25);
}

void Mage::printCampeao() const{
    Ranged::printCampeao();
}