#ifndef RAGEUSER_H
#define RAGEUSER_H

#include <iostream>

#include "Fighter.h"

class RageUser : public Fighter{

    friend ostream & operator<<( ostream &, const RageUser & );

    public:
        RageUser( int, float, float, float, int, float, int, float, bool, const string &, int, int, vector<string>, bool);
        RageUser( );
        RageUser( const RageUser & );

        RageUser & operator=(const RageUser &);
        bool operator==(const RageUser &) const;
        bool operator!=(const RageUser &) const;
        void operator!();

        //métodos funcionais da classe
        int usarUltimate();
        int usarHabilidade();
        void avanco();
        void furtividade();
        int soco();
        void desviar();
        int liberarFuria();
        int transformar();
        int realizarAcao( int, Campeao & );
        void sofrerDano( int );

        //métodos get e set
        int getFuriaInicial();
        void setFuriaInicial( int );

    private:
        int furiaInicial;
        float furiaRegen;
        static map<int, vector<string>> acoes;
        int MAXFURIA = 200;
};

#endif