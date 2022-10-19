#include <iostream>
using std::cout;
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <math.h> 


#include "Campeao.h"

ostream &operator<<( ostream &output, const Campeao &campeao ){
    output << campeao.nomeCampeao << '\n' << campeao.funcao;
    for(int i = 0; i < int(campeao.nomeHabilidades.size()); i++){
        output << '\n' << campeao.nomeHabilidades[i];
    }

    for(int i = 0; i < campeao.ultimateSize; i++){
        output << "Cargas de Ultimate: " << campeao.ultimatePtr[i];
    }

    return output;
}

Campeao& Campeao::operator=(const Campeao &other){
    if(this != &other){
        this->~Campeao();

        this->nomeCampeao = other.nomeCampeao;
        this->funcao = other.funcao;
        this->nomeHabilidades = other.nomeHabilidades;
        this->ultimatePtr = other.ultimatePtr;
        this->ultimateSize = other.ultimateSize;
        this->nextEntrieUltimate = other.nextEntrieUltimate;
    }
    return *this;
}

bool Campeao::operator==(const Campeao &other) const{
    if( this->nomeCampeao != other.nomeCampeao && 
    this->funcao != other.funcao && 
    this->ultimatePtr != other.ultimatePtr &&
    this->ultimateSize != other.ultimateSize &&
    this->nextEntrieUltimate != other.nextEntrieUltimate) return false;

    return true;
}

bool Campeao::operator!=(const Campeao &other) const{
    return ! ( *this == other );
}

Campeao::Campeao(const string &nome, const string &funcao, vector<string> nomeHabilidades){
    setNomeCampeao(nome);
    setFuncao(funcao);
    this->nomeHabilidades = nomeHabilidades;

    this-> ultimatePtr = 0;
    this->ultimateSize = 0;
    this->nextEntrieUltimate = 0;
    allocUltimate( 5 );
}

Campeao::Campeao( ):
nomeCampeao("Novo Campeão"), 
funcao("Sem função"){
    this-> ultimatePtr = 0;
    this->ultimateSize = 0;
    this->nextEntrieUltimate = 0;
}

Campeao::Campeao(const Campeao &other){
    this->nomeCampeao = other.nomeCampeao;
    this->funcao = other.funcao;
    this->nomeHabilidades = other.nomeHabilidades;
    this->ultimatePtr = other.ultimatePtr;
    this->ultimateSize = other.ultimateSize;
    this->nextEntrieUltimate = other.nextEntrieUltimate;
}

Campeao::~Campeao( ){
    delete [] ultimatePtr;
}

void Campeao::setNomeCampeao(const string &nomeCampeao){
    if(nomeCampeao.length() > 2){
        this->nomeCampeao = nomeCampeao;
        return;
    }
    this->nomeCampeao = "Novo Campeão";
}

void Campeao::setFuncao(const string &funcao){
    if(funcao.length() > 2){
        this->funcao = funcao;
        return;
    }
    this->funcao = "Sem função";
}

void Campeao::printHabilidades() const{
    for(int i = 0; i < int(nomeHabilidades.size()); i++){
        cout << nomeHabilidades[i];
    }
}

string Campeao::getNomeCampeao() const{
    return nomeCampeao;
}
string Campeao::getFuncao() const{
    return funcao;
}

vector<string> Campeao::getNomeHabilidades() const{
    return nomeHabilidades;
}

void Campeao::allocUltimate( int cargasUltimate ){
    int *ultimateTemp;

    if ( nextEntrieUltimate < ultimateSize )
    {
        ultimatePtr[ nextEntrieUltimate++ ] = cargasUltimate;
        return;
    }

    if( ultimateSize == 0 )
    {
        ultimateSize = 1;
        ultimatePtr = new int[ ultimateSize ];
        ultimatePtr[ nextEntrieUltimate++ ] = cargasUltimate;
        return;
    }

    if(ultimateSize <= nextEntrieUltimate){
        ultimateTemp = new int[ ultimateSize ];

        for(int i = 0; i < ultimateSize; i++)
            ultimateTemp[ i ] = ultimatePtr[ i ];
        
        delete [] ultimatePtr;
        ultimateSize += int(ceil(ultimateSize * 0.5));
        ultimatePtr = new int[ ultimateSize ];

        for(int i = 0; i < ultimateSize; i++)
            ultimateTemp[ i ] = ultimatePtr[ i ];

        ultimatePtr[ nextEntrieUltimate++ ] = cargasUltimate;
        delete [] ultimateTemp;
        return;
    }
}

int * Campeao::getCargasUltimate( ) const{
   return ultimatePtr;
}

int Campeao::getUltimateSize( ) const{
    return ultimateSize;
}