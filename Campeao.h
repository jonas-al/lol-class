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

        void setNomeCampeao( const string & );
        void setFuncao( const string & );
        void setNomeHabilidades(vector<string>);
        void setHabilitado(bool);
        void printHabilidades() const;

        string getNomeCampeao() const;
        string getFuncao() const;
        vector<string> getNomeHabilidades() const;
        bool getHabilitado() const;

    private:
        string nomeCampeao;
        string funcao;
        vector<string> nomeHabilidades;
        bool habilitado;
};



#endif