#ifndef SHOOTER_H
#define SHOOTER_H

#include "Ranged.h"

class Shooter : public Ranged{

    friend ostream & operator<<( ostream &, const Shooter & );

    public:
        Shooter( const string &, int, float, int, float, int, const string &, int, int, int, const string &, int, int, vector<string>, bool );
        Shooter();
        Shooter( const Shooter & );
        
        Shooter & operator=(const Shooter &);
        bool operator==(const Shooter &) const;
        bool operator!=(const Shooter &) const;
        void operator!();

        int usarUltimate();
        int usarHabilidade();
        void afastar();
        int atirar();
        void curar();
        void sofrerDano( int );
        int getDanoAtaque() const;
        float getChanceCritico() const;
        void setDanoAtaque( int );
        void setChanceCritico( float );
        int causarDano();
        int realizarAcao( int, Campeao & );

    private:
        string tipoArma;
        int danoAtaque;
        float chanceCritico;
        static map<int, vector<string>> acoes;
        const float MAXATKSPEED = 2.5;
};

#endif