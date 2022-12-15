#ifndef MAGE_H
#define MAGE_H

#include "Ranged.h"

class Mage : public Ranged{

    friend ostream & operator<<( ostream &, const Mage & );

    public:
        Mage( const string &, float, int, float, int, const string &, int, int, int, const string &, int, int, vector<string>, bool);
        Mage();
        Mage( const Mage & );

        Mage & operator=(const Mage &);
        bool operator==(const Mage &) const;
        bool operator!=(const Mage &) const;
        void operator!();

        //métodos funcionais da classe
        int usarUltimate();
        int usarHabilidade(){return 0;}
        void sofrerDano( int );
        int causarDano( ) {return 0;}
        int realizarAcao( ) {return 0;};
        void afastar();
        int realizarAcao( int, Campeao & ) {return 0;}

        //método de exibição
        void printCampeao() const;

    private:
        string tipoMagia;
        float penetracaoMagica;
        const float MAXCDREDUCTION = 0.4;
};

#endif