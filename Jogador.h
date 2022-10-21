#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Jogador{
    friend ostream & operator<<( ostream &, const Jogador & );
    
    public:
        Jogador( const string &, int, int, const string & );
        Jogador();
        Jogador(const Jogador &);
        ~Jogador();

        Jogador & operator=(const Jogador &);
        bool operator==(const Jogador &) const;
        bool operator!=(const Jogador &) const;

        void setApelido( const string & );
        void setPartidasJogadas( int );
        void setNivel( int );
        void setElo( const string & );

        string getApelido() const;
        int getPartidasJogadas() const;
        int getNivel() const;
        int getHonra() const;
        string getElo() const;


    private:
        string apelido;
        int partidasJogadas;
        int nivel;
        int honra;
        string elo;
};

#endif