#ifndef FIGHTER_H
#define FIGHTER_H

#include "Melee.h"

class Fighter : public Melee{
    
    friend ostream & operator<<( ostream &, const Fighter & );

    public:
        Fighter( float, float, int, float, int, float, bool, const string &, int, int, vector<string>, bool );
        Fighter();
        Fighter( const Fighter & );

        Fighter & operator=(const Fighter &);
        bool operator==(const Fighter &) const;
        bool operator!=(const Fighter &) const;
        void operator!();

        //métodos funcionais da classe
        int usarUltimate();
        int usarHabilidade(){};
        void avanco(){};
        void furtividade();
        virtual int soco(){};
        virtual void desviar(){};

        //métodos get e set
        void setChanceDesvio( float );
        void setBonusDanoVida( float );
        float getChanceDesvio();
        float getBonusDanoVida();
        void sofrerDano( int );
        int realizarAcao( int, Campeao & ) {return 0;}

    private:
        float chanceDesvio;
        float bonusDanoVida;
        float MAXDANOBONUS = 0.5;
};

#endif