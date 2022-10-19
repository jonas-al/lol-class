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

class Partida{

    friend ostream & operator<<( ostream &, const Partida & );

    public:
        struct AMAG{
            int abates;
            int mortes;
            int assistencias;
            int gold;
        };

        Partida( int, AMAG, AMAG, const string &);
        Partida( );
        Partida( const Partida &);
        ~Partida( );

        Partida & operator=(const Partida &);
        bool operator==(const Partida &) const;
        bool operator!=(const Partida &) const;

        void setJogadores( );
        void setCampeaos( );
        void setPlacar ( AMAG, bool );
        void getPlacar( ) const;
        void getJogadores ( ) const;
        void getCampeaos( ) const;

    private:
        int idPartida;
        AMAG placarAzul;
        AMAG placarVermelho;
        string duracao;
        Data dataPartida;
        vector<Jogador *> jogadores;
        vector<Campeao *> campeaos;
};


#endif