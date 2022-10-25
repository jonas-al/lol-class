#ifndef CAMPEAO_H
#define CAMPEAO_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Campeao{
    
    friend ostream & operator<<( ostream &, const Campeao & );

    public:
        Campeao( const string &, const string &, vector<string>);
        Campeao( );
        Campeao(const Campeao &);
        ~Campeao( );

        Campeao & operator=(const Campeao &);
        bool operator==(const Campeao &) const;
        bool operator!=(const Campeao &) const;
        void operator!();

        void getUltimates( ) const;
        void setNomeCampeao( const string & );
        void setFuncao( const string & );
        void printHabilidades() const;
        void mudarCargasUltimate( int );

        string getNomeCampeao() const;
        string getFuncao() const;
        vector<string> getNomeHabilidades() const;
        int * getCargasUltimate( ) const;
        int getUltimateSize( ) const;

    private:
        string nomeCampeao;
        string funcao;
        vector<string> nomeHabilidades;
        bool habilitado;

        int *ultimatePtr;
        int ultimateSize;
        int nextEntrieUltimate;

        void allocUltimate( int );
};



#endif