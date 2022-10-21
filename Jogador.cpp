#include <iostream>
using std::cout;
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;


#include "Jogador.h"

ostream &operator<<( ostream &output, const Jogador &jogador ){
    output << jogador.apelido << '\n' << jogador.partidasJogadas << '\n' << jogador.nivel << '\n' << jogador.honra << '\n' << jogador.elo;

    return output;
}

Jogador& Jogador::operator=(const Jogador &other){
    if(this != &other){
        this->~Jogador();

        this->apelido = other.apelido;
        this->partidasJogadas = other.partidasJogadas;
        this->nivel = other.nivel;
        this->honra = other.honra;
        this->elo = other.elo;
    }
    return *this;
}

bool Jogador::operator==(const Jogador &other) const{
    if( 
    this->apelido != other.apelido && 
    this->partidasJogadas != other.partidasJogadas &&
    this->nivel != other.nivel &&
    this->honra != other.honra &&
    this->elo != other.elo) return false;

    return true;
}

bool Jogador::operator!=(const Jogador &other) const{
    return ! ( *this == other );
}

Jogador::Jogador( const string &apelido, int partidasJogadas, int honra, const string &elo ){
    setApelido(apelido);
    setNivel(partidasJogadas);
    setPartidasJogadas(partidasJogadas);
    this->honra = honra;
    setElo(elo);
}

Jogador::Jogador( ):apelido("Novo Invocador"), partidasJogadas(0), nivel(0), honra(0), elo("Ferro III"){}

Jogador::Jogador( const Jogador &other ){
    this->apelido = other.apelido;
    this->partidasJogadas = other.partidasJogadas;
    this->nivel = other.nivel;
    this->honra = other.honra;
    this->elo = other.elo;
}

Jogador::~Jogador( ){}

void Jogador::setApelido( const string &apelido ){
    if( apelido.length() < 5 ){;
        this->apelido = "Novo Invocador";
        return;
    }
    this->apelido = apelido;
}

void Jogador::setPartidasJogadas( int quantidade ){
    if( quantidade < 0){
        this->partidasJogadas = 0;
        return;
    }
    this->partidasJogadas = quantidade;
}

void Jogador::setNivel( int partidasJogadas ){
    this->nivel = partidasJogadas + 5;
}

void Jogador::setElo( const string &elo ){
    if(elo.length() < 4){
        this->elo = "Ferro III";
        return;
    }
    this->elo = elo;
}

string Jogador::getApelido() const{
    return apelido;
}
int Jogador::getPartidasJogadas() const{
    return partidasJogadas;
}
int Jogador::getNivel() const{
    return nivel;
}
int Jogador::getHonra() const{
    return honra;
}
string Jogador::getElo() const{
    return elo;
}