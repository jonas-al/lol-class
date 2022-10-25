#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Data.cpp"
#include "Jogador.cpp"
#include "Campeao.cpp"

struct AMAG{
    int abates;
    int mortes;
    int assistencias;
    int gold;
};

class Partida{

    friend ostream & operator<<( ostream &, const Partida & );

    public:
        Partida( int, AMAG, AMAG, const string &);
        Partida( );
        Partida( const Partida &);
        ~Partida( );

        Partida & operator=(const Partida &);
        bool operator==(const Partida &) const;
        bool operator!=(const Partida &) const;
        void operator!();

        void setJogadores( );
        void setCampeaos( );
        void setPlacar ( AMAG, bool );
        void addPlayer( const string & );
        void addChampion( const string & );
        void addElo( const string & );
        void getPlacar( ) const;
        void getJogadores ( ) const;
        void getCampeaos( ) const;
        void addCargaUltimate ( int );
        

    private:
        int idPartida;
        AMAG placarAzul;
        AMAG placarVermelho;
        string duracao;
        Data dataPartida;
        vector<Jogador *> jogadores;
        vector<Campeao *> campeaos;

        static const int MAXJOGADORES = 2;
        static vector<string> players;
        static vector<vector<string>> champions;
        static vector<string> elos;
};


#endif