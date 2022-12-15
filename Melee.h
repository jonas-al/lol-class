#ifndef MELEE_H
#define MELEE_H

#include "Campeao.h"

class Melee : public Campeao{

    public:
        Melee( int, float, int, float, bool, const string &, int, int, vector<string>, bool);
        Melee( );
        Melee( const Melee & );
        virtual ~Melee();

        //métodos virtuais puros
        virtual void avanco() = 0;
        virtual void furtividade() = 0;

        //métodos get, set e print
        int getArmaduraInicial(){return this->armaduraInicial;}
        int getMrInicial(){return this->mrInicial;}
        float getArmaduraNivel() {return this->armaduraInicial;}
        float getMrNivel(){return this->mrNivel;}
        bool getFurtivo(){return this->furtivo;}
        void setFurtivo();
        void setArmaduraInicial( int );
        void setMrInicial( int );
        virtual void printCampeao() const;

    private:
        int armaduraInicial;
        float armaduraNivel;
        int mrInicial;
        float mrNivel;
        bool furtivo;
};

#endif