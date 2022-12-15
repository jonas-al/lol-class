#ifndef CAMPEAO_H
#define CAMPEAO_H

#include "Partida.h"

struct SupportStruct {
    int cura = 20;
    int escudo = 20;
    float resistenciaEscudo = .10;
    float bonusCuraEscudo = .10;
    string tipoMagia = "Fantasia";
    float penetracaoMagica = .20;
    int alcanceInicial = 300;
    float alcanceNivel = .10;
    int resistencias = 20; 
    string tipoDano = "Mágico";
    int manaInicial = 400;
    int manaNivel = .1;
    int manaRegen = 2;
    string nome = "Lulu";
    int vidaIncial = 400;
    int escudoInicial = 0;
    vector<string> nomeHabilidades = {"LANÇA-PURPURINA", "CRESCIMENTO VIRENTE"};
    bool habilitado = true;
};

struct CasterStruct{
    int poderHabilidade = 300;
    float danoBonus = .10;
    float vampMagico = .20;
    string tipoMagia = "Luz";
    float penetracaoMagica = .15;
    int alcanceInicial = 300;
    float alcanceNivel = .10;
    int resistencias = 20;
    string tipoDano = "Mágico";
    int manaInicial = 400;
    int manaNivel = .1;
    int manaRegen = 2;
    string nome = "Lux";
    int vidaIncial = 450;
    int escudoInicial = 150;
    vector<string> nomeHabilidades = {"PRISÃO PLÁSMATICA", "CENTELHA FINAL"};
    bool habilitado = true;
};

struct RageUserStruct{
    int furiaInicial = 200;
    float furiaRegen = .10;
    float chanceDesvio = .1;
    float bonusDanoVida = .5;
    int armaduraInicial = 40;
    float armaduraNivel = .5;
    int mrInicial = 45;
    float mrNivel = .5;
    bool furtivo = false;
    string nome = "Shyvanna";
    int vidaIncial = 600;
    int escudoInicial = 0;
    vector<string> nomeHabilidades = {"MORDIDA DUPLA", "DESCIDA DO DRAGÃO"};
    bool habilitado = true;
};

struct ShooterStruct{
    string tipoArma = "Metralhadora";
    int danoAtaque = 300;
    float chanceCritico = .35;
    int alcanceInicial = 450;
    float alcanceNivel = .7;
    int resistencias = 30;
    string tipoDano = "Físico";
    int manaInicial = 300;
    int manaNivel = 7;
    int manaRegen = 2;
    string nome = "Jinx";
    int vidaIncial = 400;
    int escudoInicial = 100;
    vector<string> nomeHabilidades = {"ZAP!", "SUPER MEGA MÍSSIL DA MORTE!"};
    bool habilitado = true;
};

struct TankStruct{
    float reducaoDano = .10;
    float bonusVida = .1;
    int armaduraInicial = 45;
    float armaduraNivel = .7;
    int mrInicial = 45;
    float mrNivel = .7;
    bool furtivo = false;
    string nome = "Maokai";
    int vidaIncial = 800;
    int escudoInicial = 0;
    vector<string> nomeHabilidades = {"ESMAGAMENTO ESPINHOSO", "GARRAS DA NATUREZA"};
    bool habilitado = true;
};

class Campeao : public Partida{

    public:
        Campeao( const string &, int, int, vector<string>, bool);
        Campeao( );
        Campeao( const Campeao & );
        virtual ~Campeao( );
        
        //métodos virtuais puros
        virtual int usarUltimate() = 0;
        virtual int usarHabilidade() = 0;
        virtual void sofrerDano( int ) = 0;
        virtual int realizarAcao( int, Campeao & ) = 0;

        //métodos get, set e print
        virtual void printCampeao() const;
        void printHabilidades() const;
        int getVida() {return this->vidaIncial;}
        int getEscudo() {return this->escudoInicial;}
        string getNomeCampeao() {return this->nomeCampeao;}
        vector<string> getNomeHabilidades() {return this->nomeHabilidades;}
        bool getHabilitado() {return this->habilitado;}
        virtual void setVida( int );
        virtual void setEscudo( int );
        virtual void setHabilitado( bool );
        SupportStruct getChampSupport(){return champSupport;}
        CasterStruct getChampCaster(){return champCaster;}
        ShooterStruct getChampShooter(){return champShooter;}
        RageUserStruct getChampRageUser(){return champRageUser;}
        TankStruct getChampTank(){return champTank;}
        

        //método de batalha entre campeões.
        static void batalha( vector < Campeao * > campeoes );
        int selecionarCampeao( );
        int campeaoSelecionado = 0;
        

    private:
        string nomeCampeao;
        int vidaIncial;
        int escudoInicial;
        vector<string> nomeHabilidades;
        bool habilitado;
        
        SupportStruct champSupport;
        CasterStruct champCaster;
        ShooterStruct champShooter;
        RageUserStruct champRageUser;
        TankStruct champTank;
};



#endif