#ifndef TANK_H
#define TANK_H

#include "Melee.h"

class Tank : public Melee{

    friend ostream & operator<<( ostream &, const Tank & );

    public:
        Tank( float, float, int, float, int, float, bool, const string &, int, int, vector<string>, bool );
        Tank();
        Tank( const Tank & );

        Tank & operator=(const Tank &);
        bool operator==(const Tank &) const;
        bool operator!=(const Tank &) const;
        void operator!();

        //métodos funcionais da classe
        int usarUltimate();
        int usarHabilidade();
        void avanco();
        void furtividade();
        void enrijecer();
        void protejer();
        void sofrerDano( int );
        int realizarAcao( int, Campeao & );

        //métodos get e set
        float getReducaoDano();
        float getBonusVida();
        void setReducaoDano( float );
        float setBonusVida( float );
        

    private:
        float reducaoDano;
        float bonusVida;
        const float MAXVIDA = 6000;
        static map<int, vector<string>> acoes;
};

#endif