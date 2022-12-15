#include "Partida.h"

//Instanciação dos vetores statics
vector<string> Partida::players = {"Clarice", "Vinizinho", "Taylor Swift", "João", "Caio", "Sarah", "Resque", "Felipe", "Yonas", "Camilo", "Alfredo", "Jorge","Eude","MMO"};

vector<string> Partida::elos = {"Ferro I", "Ferro II", "Ferro III", "Bronze I", "Bronze II", "Bronze III", "Prata I", "Prata II", "Prata III", "Ouro I", "Ouro II", "Ouro III", "Platina I", "Platina II", "Platina III", "Diamante I", "Diamante II", "Diamante III", "Mestre", "Grão-Mestre", "Challenger"};

Partida::Partida( int idPartida,const string &duracao){
    this->idPartida = idPartida;
    this->duracao = duracao;
    this -> dataPartida = Data();
}

Partida::Partida( ):idPartida(0), duracao("0"), dataPartida(Data()){
    setJogadores();
}

Partida::Partida( const Partida &other){
    this->idPartida = other.idPartida;
    this->duracao = other.duracao;
    this->dataPartida = other.dataPartida;
    this->jogadores = other.jogadores;
    this->players = other.players;
    this->elos = other.elos;
}

Partida::~Partida( ){}

void Partida::setJogadores( ){
    srand(time(0));
    for (int i = 0; i < MAXJOGADORES; i++){
        jogadores.push_back( new Jogador(players[rand() %int(players.size())], rand() %int(50), 2, elos[rand() %int(elos.size())]));
    }

}

void Partida::getJogadores ( ) const{
    cout << "\nJogadores!!!";
    for( int i=0; i < int(jogadores.size()); i++){
        cout << "\nApelido: " << jogadores[i]->getApelido() << '\n'
        << "Partidas Jogadas: " << jogadores[i]->getPartidasJogadas() << '\n'
        << "Nível: " << jogadores[i]->getNivel() << '\n'
        << "Nível Honra: " << jogadores[i]->getHonra() << '\n'
        << "Elo: " << jogadores[i]->getElo() << '\n';
    }
}

void Partida::addPlayer( const string &nomeJogador ){
    players.push_back( nomeJogador );
}

void Partida::addElo( const string &nomeElo ){
    elos.push_back( nomeElo );
}