#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;
using std::to_string;
#include <map>
using std::map;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <math.h>
#include <typeinfo>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <thread>
#include <iterator>

#include "Data.cpp"
#include "Jogador.cpp"

class Partida{

    public:
        Partida( int, const string &);
        Partida( );
        Partida( const Partida &);
        virtual ~Partida( );

        void setJogadores( );
        void addPlayer( const string & );
        void addElo( const string & );
        void getJogadores ( ) const;

    private:
        int idPartida;
        string duracao;
        Data dataPartida;
        vector<Jogador *> jogadores;

        static const int MAXJOGADORES = 2;
        static vector<string> players;
        static vector<string> elos;
};


#endif