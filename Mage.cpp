#include <iostream>
#include "Mage.h"

Mage::Mage
(
    const string &tipoMagia,
    int alcanceInicial, 
    float alcanceNivel, 
    int resistencias, 
    const string &tipoDano,
    const string &nome,
    const string &funcao,
    vector<string> nomeHabilidades
) : Ranged( 
    alcanceInicial, 
    alcanceNivel, 
    resistencias, 
    tipoDano, 
    nome, 
    funcao, 
    nomeHabilidades )
{
    this->tipoMagia = tipoMagia;
}   

Mage::Mage():tipoMagia("Nenhuma"){}

Mage::Mage(const Mage &other):Ranged(static_cast < Ranged >(other)){
    this->tipoMagia = other.tipoMagia;
}

ostream & operator<<( ostream &output, const Mage &campeao ){
    output << static_cast< Ranged >(campeao) << 
    "Tipo Mágia: " << campeao.tipoMagia << '\n';

    return output;
}

Mage & Mage::operator=(const Mage &other){
    if(this != &other){
        this->setNomeCampeao(static_cast< Campeao >(other).getNomeCampeao());
        this->setFuncao(static_cast< Campeao >(other).getFuncao());
        this->setNomeHabilidades(static_cast< Campeao >(other).getNomeHabilidades());
        this->setHabilitado(static_cast< Campeao >(other).getHabilitado());

        this->setAlcanceInicial(static_cast< Ranged >(other).getAlcanceInicial());
        this->setAlcanceNivel(static_cast< Ranged >(other).getAlcanceNivel());
        this->setResistencias(static_cast< Ranged >(other).getResistencias());
        this->setTipoDano(static_cast< Ranged >(other).getTipoDano());
        
        this->tipoMagia = other.tipoMagia;
    }
    return *this;
}

bool Mage::operator==(const Mage &other) const{
    if(static_cast< Campeao >(*this) != static_cast< Campeao >(other) ||
    static_cast< Ranged >(*this) != static_cast< Ranged >(other) ||
    this->tipoMagia != other.tipoMagia) return false;

    return true;
}

bool Mage::operator!=(const Mage &other) const{
    if(static_cast< Campeao >(*this) == static_cast< Campeao >(other) && 
    static_cast< Ranged >(*this) == static_cast< Ranged >(other) &&
    *this == other) return false;

    return true;
}

void Mage::operator!(){
    this->setHabilitado(!this->getHabilitado());
}