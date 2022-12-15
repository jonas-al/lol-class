#ifndef RANGED_H
#define RANGED_H

#include "Campeao.h"

class Ranged : public Campeao{

    public:
        Ranged( int, float, int, const string &, int, int, int, const string &, int, int, vector<string>, bool);
        Ranged( );
        Ranged( const Ranged & );
        virtual ~Ranged( );
        
        //método virtual puro
        virtual void afastar() = 0;

        //métodos get, set e print
        int getAlcanceInicial() {return this->alcanceInicial;}
        float getAlcanceNivel(){return this->alcanceNivel;}
        int getResistencias(){return this->resistencias;}
        string getTipoDano(){return this->tipoDano;}
        void setAlcanceInicial( int );
        virtual void printCampeao() const;

    private:
        int alcanceInicial;
        float alcanceNivel;
        int resistencias;
        string tipoDano;
        int manaInicial;
        int manaNivel;
        int manaRegen;
};

#endif