#ifndef SUPPORT_H
#define SUPPORT_H

#include "Mage.h"

class Support : public Mage{

    friend ostream & operator<<( ostream &, const Support & );

    public:
        Support( int, int, float, float, const string &, float, int, float, int, const string &, int, int, int, const string &, int, int, vector<string>, bool );
        Support();
        Support( const Support & );
        
        Support & operator=(const Support &);
        bool operator==(const Support &) const;
        bool operator!=(const Support &) const;
        void operator!();

        //métodos funcionais da classe
        int usarUltimate();
        int usarHabilidade();
        void afastar();
        virtual void artodoar( Campeao & );
        void darEscudo();
        void darCura();
        int realizarAcao( int, Campeao & );

        //métodos get e set
        int getCura();
        int getEscudo();
        float getResistenciaEscudo();
        float getBonusCuraEscudo();
        void setCura( int );
        void setEscudo( int );
        void setResistenciaEscudo( int );
        void setBonusCura( int );
        

    private:
        int cura;
        int escudo;
        float resistenciaEscudo;
        float bonusCuraEscudo;
        static map<int, vector<string>> acoes;
};

#endif