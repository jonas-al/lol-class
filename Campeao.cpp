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
    output << "Nome Campeão: " << campeao.nomeCampeao << '\n' 
    << "Função: " << campeao.funcao << '\n' 
    << (campeao.habilitado? ("Status: Habilitado\n") : ("Status: Desabilitado\n")) ;

    output << "Habilidades: ";
    for(int i = 0; i < int(campeao.nomeHabilidades.size()); i++){
        if(i == int(campeao.nomeHabilidades.size())-1)
            output << campeao.nomeHabilidades[i];
        else
            output << campeao.nomeHabilidades[i] << " || ";
    }

    return output; 
}

Campeao& Campeao::operator=(const Campeao &other){
    if(this != &other){
        this->nomeCampeao = other.nomeCampeao;
        this->funcao = other.funcao;
        this->nomeHabilidades = other.nomeHabilidades;
        this->habilitado = other.habilitado;
    }
    return *this;
}

bool Campeao::operator==(const Campeao &other) const{
    if( this->nomeCampeao != other.nomeCampeao || 
    this->funcao != other.funcao || 
    this->habilitado != other.habilitado) return false;

    return true;
}

bool Campeao::operator!=(const Campeao &other) const{
    return ! ( *this == other );
}

void Campeao::operator!(){
    this->habilitado = !habilitado;
}

Campeao::Campeao(const string &nome, const string &funcao, vector<string> nomeHabilidades){
    setNomeCampeao(nome);
    setFuncao(funcao);
    this->nomeHabilidades = nomeHabilidades;
    this->habilitado = true;
}

Campeao::Campeao( ):
nomeCampeao("Novo Campeão"), 
funcao("Sem função"){
    this->habilitado = true;
}

Campeao::Campeao(const Campeao &other){
    this->nomeCampeao = other.nomeCampeao;
    this->funcao = other.funcao;
    this->nomeHabilidades = other.nomeHabilidades;
    this->habilitado = other.habilitado;
}

Campeao::~Campeao( ){
    
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

void Campeao::setNomeHabilidades(vector<string> nomeHabilidades){
    this->nomeHabilidades = nomeHabilidades;
}

void Campeao::setHabilitado(bool habilitado){
    this->habilitado = habilitado;
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

bool Campeao::getHabilitado() const{
    return habilitado;
}