#ifndef CASTER_H
#define CASTER_H

#include "Mage.h"

class Caster : public Mage{

    friend ostream & operator<<( ostream &, const Caster & );

    public:
        Caster( int, float, float, const string &, float, int, float, int, const string &, int, int, int, const string &, int, int,vector<string>, bool );
        Caster();
        Caster( const Caster & );
        
        Caster & operator=(const Caster &);
        bool operator==(const Caster &) const;
        bool operator!=(const Caster &) const;
        void operator!();

        //métodos funcionais da classe
        int usarUltimate();
        int usarHabilidade();
        void afastar();
        virtual void artodoar( Campeao & );
        int explodirPoder();
        void transcender();
        int realizarAcao( int, Campeao & );
        
        //métodos set e get
        void setPoderHabilidade( int );
        void setDanoBonus( int );
        void setVampMagico( float );
        int getPoderHabilidade();
        int getDanoBonus();
        float getVampMagico();
        

    private:
        int poderHabilidade;
        int danoBonus;
        float vampMagico;
        static map<int, vector<string>> acoes;
        float MAXPH = 2000;
};

#endif