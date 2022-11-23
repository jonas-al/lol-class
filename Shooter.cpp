#include <iostream>
#include "Shooter.h"

Shooter::Shooter
(
    const string &tipoArma,
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
    this->tipoArma = tipoArma;
}   

Shooter::Shooter():tipoArma("Nenhuma"){}

Shooter::Shooter(const Shooter &other):Ranged(static_cast < Ranged >(other)){
    this->tipoArma = other.tipoArma;
}

ostream & operator<<( ostream &output, const Shooter &campeao ){
    output << static_cast< Ranged >(campeao) << 
    "Tipo Arma: " << campeao.tipoArma << '\n';

    return output;
}

Shooter & Shooter::operator=(const Shooter &other){
    if(this != &other){
        this->setNomeCampeao(static_cast< Campeao >(other).getNomeCampeao());
        this->setFuncao(static_cast< Campeao >(other).getFuncao());
        this->setNomeHabilidades(static_cast< Campeao >(other).getNomeHabilidades());
        this->setHabilitado(static_cast< Campeao >(other).getHabilitado());

        this->setAlcanceInicial(static_cast< Ranged >(other).getAlcanceInicial());
        this->setAlcanceNivel(static_cast< Ranged >(other).getAlcanceNivel());
        this->setResistencias(static_cast< Ranged >(other).getResistencias());
        this->setTipoDano(static_cast< Ranged >(other).getTipoDano());
        
        this->tipoArma = other.tipoArma;
    }
    return *this;
}

bool Shooter::operator==(const Shooter &other) const{
    if(static_cast< Campeao >(*this) != static_cast< Campeao >(other) ||
    static_cast< Ranged >(*this) != static_cast< Ranged >(other) ||
    this->tipoArma != other.tipoArma) return false;

    return true;
}

bool Shooter::operator!=(const Shooter &other) const{
    if(static_cast< Campeao >(*this) == static_cast< Campeao >(other) && 
    static_cast< Ranged >(*this) == static_cast< Ranged >(other) &&
    *this == other) return false;

    return true;
}

void Shooter::operator!(){
    this->setHabilitado(!this->getHabilitado());
}