#ifndef RANGED_H
#define RANGED_H

#include <iostream>

#include "Campeao.cpp"

class Ranged : public Campeao{

    friend ostream &operator<<( ostream &, const Ranged & );

    public:
        Ranged( int, float, int, const string &, const string &, const string &, vector<string> );
        Ranged();
        Ranged(const Ranged &);

        Ranged & operator=(const Ranged &);
        bool operator==(const Ranged &) const;
        bool operator!=(const Ranged &) const;
        void operator!();

        int getAlcanceInicial() const;
        float getAlcanceNivel() const;
        int getResistencias() const;
        string getTipoDano() const;

        void setAlcanceInicial( int );
        void setAlcanceNivel( float );
        void setResistencias( int );
        void setTipoDano( string );

    private:
        int alcanceInicial;
        float alcanceNivel;
        int resistencias;
        string tipoDano;
};

#endif