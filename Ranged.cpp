#include <iostream>
#include "Ranged.h"

Ranged::Ranged
(
    int alcanceInicial, 
    float alcanceNivel, 
    int resistencias, 
    const string &tipoDano,
    const string &nome,
    const string &funcao,
    vector<string> nomeHabilidades
) : Campeao(nome, funcao, nomeHabilidades)
{
    this->alcanceInicial = alcanceInicial;
    this->alcanceNivel = alcanceNivel;
    this->resistencias = resistencias;
    this->tipoDano = tipoDano;
}

Ranged::Ranged():
alcanceInicial(0), 
alcanceNivel(0),
resistencias(0),
tipoDano("Null"){}

Ranged::Ranged(const Ranged &other):Campeao( static_cast< Campeao >(other) ){
    this->alcanceInicial = other.alcanceInicial;
    this->alcanceNivel = other.alcanceNivel;
    this->resistencias = other.resistencias;
    this->tipoDano = other.tipoDano;
}

ostream &operator<<( ostream &output, const Ranged &campeao ){
    output << static_cast< Campeao>(campeao) << '\n' <<
    "Alcance Incial: " << campeao.alcanceInicial << '\n' <<
    "Alcance Nivel: " << campeao.alcanceNivel << '\n' <<
    "Resistências: " << campeao.resistencias << '\n' <<
    "Tipo Dano: " << campeao.tipoDano << '\n';

    return output;
}

Ranged & Ranged::operator=(const Ranged &other){
    if(this != &other){
        *static_cast< Campeao * >( this ) = static_cast< Campeao >( other );
        this->alcanceInicial = other.alcanceInicial;
        this->alcanceNivel = other.alcanceNivel;
        this->resistencias = other.resistencias;
        this->tipoDano = other.tipoDano;
    }
    return *this;
}

bool Ranged::operator==(const Ranged &other) const{
    if(static_cast< Campeao >(*this) != static_cast< Campeao >(other) ||
    this->alcanceInicial != other.alcanceInicial || 
    this->alcanceNivel != other.alcanceNivel || 
    this->resistencias != other.resistencias || 
    this->tipoDano != other.tipoDano) return false;

    return true;
}

bool Ranged::operator!=(const Ranged &other) const{
    if(static_cast< Campeao >(*this) == static_cast< Campeao >(other) && 
    *this  == other) return false;

    return true;
}

void Ranged::operator!(){
    this->setHabilitado(!this->getHabilitado());
}

int Ranged::getAlcanceInicial() const{
    return alcanceInicial;
}

float Ranged::getAlcanceNivel() const{
    return alcanceNivel;
}

int Ranged::getResistencias() const{
    return resistencias;
}

string Ranged::getTipoDano() const{
    return tipoDano;
}

void Ranged::setAlcanceInicial( int alcanceInicial ){
    this->alcanceInicial = alcanceInicial;
}

void Ranged::setAlcanceNivel( float alcanceNivel){
    this->alcanceNivel = alcanceNivel;
}

void Ranged::setResistencias( int resistencias ){
    this->resistencias = resistencias;
}

void Ranged::setTipoDano( string tipoDano ){
    this->tipoDano = tipoDano;
}