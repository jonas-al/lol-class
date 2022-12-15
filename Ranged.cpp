#include <iostream>
#include "Ranged.h"

Ranged::Ranged
(
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
):alcanceInicial(alcanceInicial),
alcanceNivel(alcanceNivel),
resistencias(resistencias),
tipoDano(tipoDano),
manaInicial(manaInicial),
manaNivel(manaNivel),
manaRegen(manaRegen),
Campeao(nome, vidaIncial, escudoInicial, nomeHabilidades, habilitado){}

Ranged::Ranged(){
    if(campeaoSelecionado == 1 ){
        SupportStruct campeao = getChampSupport();
        this->alcanceInicial = campeao.alcanceInicial;
        this->alcanceNivel = campeao.alcanceNivel;
        this->resistencias = campeao.resistencias;
        this->tipoDano = campeao.tipoDano;
        this->manaInicial = campeao.manaInicial;
        this->manaNivel = campeao.manaNivel;
        this->manaRegen = campeao.manaRegen;
    }
    if( campeaoSelecionado == 2 ){
        CasterStruct campeao = getChampCaster();
        this->alcanceInicial = campeao.alcanceInicial;
        this->alcanceNivel = campeao.alcanceNivel;
        this->resistencias = campeao.resistencias;
        this->tipoDano = campeao.tipoDano;
        this->manaInicial = campeao.manaInicial;
        this->manaNivel = campeao.manaNivel;
        this->manaRegen = campeao.manaRegen;
    }
    else{
        ShooterStruct campeao = getChampShooter();
        this->alcanceInicial = campeao.alcanceInicial;
        this->alcanceNivel = campeao.alcanceNivel;
        this->resistencias = campeao.resistencias;
        this->tipoDano = campeao.tipoDano;
        this->manaInicial = campeao.manaInicial;
        this->manaNivel = campeao.manaNivel;
        this->manaRegen = campeao.manaRegen;
    }
}

Ranged::Ranged( const Ranged &other ):Campeao(other){
    this->alcanceInicial = other.alcanceInicial;
    this->alcanceNivel = other.alcanceNivel;
    this->resistencias = other.resistencias;
    this->tipoDano = other.tipoDano;
    this->manaInicial = other.manaInicial;
    this->manaNivel = other.manaNivel;
    this->manaRegen = other.manaRegen;
}

Ranged::~Ranged(){}

void Ranged::setAlcanceInicial( int alcance){
    this->alcanceInicial += alcance;
}

void Ranged::printCampeao() const{
    Campeao::printCampeao();
    cout << "Alcance Inicial: " << this->alcanceInicial << '\n';
    cout << "Alcance Nível: " << this->alcanceNivel*100 <<'%'<<'\n';
    cout << "Resistências: " << this->resistencias << '\n';
    cout << "Tipo dano: " << this->tipoDano << '\n';
    cout << "Mana Incial: " << this->manaInicial << '\n';
    cout << "Mana Nível: " << this->manaNivel << '\n';
    cout << "Regeneração de Mana: " << this->manaRegen << '\n';
}