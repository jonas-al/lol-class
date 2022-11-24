#include <iostream>
#include "Melee.h"

Melee::Melee(int armaduraInicial, 
    float armaduraNivel, 
    int mrInicial, 
    float mrNivel, 
    bool mana,
    string tipoDano,
    string nome,
    string funcao,
    vector<string> nomeHabilidades
) : Campeao(nome, funcao, nomeHabilidades)
{
    this->armaduraInicial = armaduraInicial;
    this->armaduraNivel = armaduraNivel;
    this->mrInicial = mrInicial;
    this->mrNivel = mrNivel;
    this->mana = mana;
}

Melee::Melee():
armaduraInicial(0),
armaduraNivel(0),
mrInicial(0),
mrNivel(0),
mana(false),
Campeao(){}

Melee::Melee( const Melee &other) : Campeao(static_cast< Campeao >(other)){
    this->armaduraInicial = other.armaduraInicial;
    this->armaduraNivel = other.armaduraNivel;
    this->mrInicial = other.mrInicial;
    this->mrNivel = other.mrNivel;
    this->mana = other.mana;
}

ostream & operator<<( ostream &output, const Melee &campeao ){
    output << static_cast< Campeao >(campeao) << '\n' <<
    "Armadura Inicial: " << campeao.armaduraInicial << '\n' <<
    "Armadura Nivel: " << campeao.armaduraNivel << '\n' <<
    "Resistência Mágica: " << campeao.mrInicial << '\n' <<
    "Resistência Mágica Nível: " << campeao.mrNivel << '\n' <<
    "Utiliza mana?: " << (campeao.mana? ("Sim") : ("Não")) << '\n';

    return output;
}

Melee & Melee::operator=(const Melee &other){
    if(this != &other){
        *static_cast< Campeao *> ( this ) = static_cast< Campeao > ( other );
        this->armaduraInicial = other.armaduraInicial;
        this->armaduraNivel = other.armaduraNivel;
        this->mrInicial = other.mrInicial;
        this->mrNivel = other.mrNivel;
        this->mana = other.mana;
    }
    return *this;
}

bool Melee::operator==(const Melee &other) const{
    if(static_cast< Campeao >(*this) != static_cast< Campeao >(other) ||
    this->armaduraInicial != other.armaduraInicial || 
    this->armaduraNivel != other.armaduraNivel || 
    this->mrInicial != other.mrInicial || 
    this->mrNivel != other.mrNivel || 
    this->mana != other.mana) return false;

    return true;
}

bool Melee::operator!=(const Melee &other) const{
    if(static_cast< Campeao >(*this) == static_cast< Campeao >(other) ||
    *this == other) return false;

    return true;
}

void Melee::operator!(){
    this->setHabilitado(!this);
}