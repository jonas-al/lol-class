#include <iostream>
using std::cout;
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iterator>
#include <map>
using std::map;
#include <cstdlib>
#include <time.h>

#include "Partida.h"

vector<string> players = {"Clarice", "Vinicius", "Taylor Swift", "João", "Caio", "Sarah", "Resque", "Felipe", "Yonas", "Camilo", "Alfredo", "Jorge"};

vector<string> champions = {"Lux", "Braum", "Caitlyn", "Orianna", "Jinx", "Ashe", "Kai'Sa", "Tristana", "Syndra", "Miss Fortune", "Twitch", "Viktor", "Jhin"};

ostream &operator<<( ostream &output, const Partida &partida ){
    output << "\nId: " << partida.idPartida << '\n' 
    << "Duração: " << partida.duracao << '\n' 
    << "\nTime Azul\n" << "Abates: " << partida.placarAzul.abates << '\n' 
    << "Assistencias: " << partida.placarAzul.assistencias << '\n' 
    << "Mortes: " << partida.placarAzul.mortes << '\n' 
    << "Gold: " << partida.placarAzul.gold << '\n'
    << "\nTime Vermelho\n" << "Abates: " << partida.placarAzul.abates << '\n' 
    << "Assistencias: " << partida.placarAzul.assistencias << '\n' 
    << "Mortes: " << partida.placarAzul.mortes << '\n' 
    << "Gold: " << partida.placarAzul.gold << '\n'
    << "Data da Partida: " << partida.dataPartida.getDia() << '/' << partida.dataPartida.getMes() << '/' << partida.dataPartida.getAno() << '\n';

    cout << "\nJogadores!!!";
    for( int i=0; i < int(partida.jogadores.size()); i++){
        output << "\nApelido: " << partida.jogadores[i]->getApelido() << '\n'
        << "Partidas Jogadas: " << partida.jogadores[i]->getPartidasJogadas() << '\n'
        << "Nível: " << partida.jogadores[i]->getNivel() << '\n'
        << "Nível Honra: " << partida.jogadores[i]->getHonra() << '\n'
        << "Elo: " << partida.jogadores[i]->getElo() << '\n';
    }

    cout << "\nCampeãos!!!";
    for( int i = 0; i < int(partida.campeaos.size()); i++ ){
        cout << "\nNome do Campeão: " << partida.campeaos[i]->getNomeCampeao() << '\n'
        << "Função: " << partida.campeaos[i]->getFuncao() << '\n';
        for( int j = 0; j < int(partida.campeaos[i]->getNomeHabilidades().size()); j++ ){
            cout << "Habilidade " << j+1 << ": " << partida.campeaos[i]->getNomeHabilidades()[j] << '\n';
        }

        for(int i = 0; i < partida.campeaos[i]->getUltimateSize(); i++){
            output << "Cargas de Ultimate: " << *(partida.campeaos[i]->getCargasUltimate()) << '\n';
        }
    }

    return output;
}

Partida& Partida::operator=(const Partida &other){
    if(this != &other){
        this->~Partida();

        this->idPartida = other.idPartida;
        this->placarAzul = other.placarAzul;
        this->duracao = other.duracao;
        this->placarVermelho = other.placarVermelho;
        this->dataPartida = other.dataPartida;
        this->jogadores = other.jogadores;
        this->campeaos = other.campeaos;
    }
    return *this;
}

bool Partida::operator==(const Partida &other) const{

    for(int i=0; i < int(jogadores.size()); i++){
        if(jogadores[i] != other.jogadores[i]) return false;
    }

    for(int i=0; i < int(campeaos.size()); i++){
        if(campeaos[i] != other.campeaos[i]) return false;
    }

    if(
    this->placarAzul.abates != other.placarAzul.abates &&
    this->placarAzul.mortes != other.placarAzul.mortes &&
    this->placarAzul.assistencias != other.placarAzul.assistencias &&
    this->placarAzul.gold != other.placarAzul.gold &&

    this->placarVermelho.abates != other.placarVermelho.abates &&
    this->placarVermelho.mortes != other.placarVermelho.mortes &&
    this->placarVermelho.assistencias != other.placarVermelho.assistencias &&
    this->placarVermelho.gold != other.placarVermelho.gold &&

    this->dataPartida.getDia() != other.dataPartida.getDia() &&
    this->dataPartida.getMes() != other.dataPartida.getMes() &&
    this->dataPartida.getAno() != other.dataPartida.getAno() &&

    this->idPartida != other.idPartida && 
    this->duracao != other.duracao) return false;

    return true;
}

bool Partida::operator!=(const Partida &other) const{
    return ! ( *this == other );
}

Partida::Partida( int idPartida, AMAG placarAzul, AMAG placarVermelho, const string &duracao){
    this->idPartida = idPartida;
    setPlacar(placarAzul, true);
    setPlacar(placarVermelho, false);
    this->duracao = duracao;
    this -> dataPartida = Data();
    setJogadores();
    setCampeaos();
}

Partida::Partida( ):idPartida(0), duracao("0"){
    placarAzul.abates = 0;
    placarAzul.assistencias = 0;
    placarAzul.mortes = 0;
    placarAzul.gold = 0;

    placarVermelho.abates = 0;
    placarVermelho.assistencias = 0;
    placarVermelho.mortes = 0;
    placarVermelho.gold = 0;
}

Partida::Partida( const Partida &other){
    this->idPartida = other.idPartida;
    this->placarAzul = other.placarAzul;
    this->placarVermelho = other.placarVermelho;
    this->duracao = other.duracao;
    this->dataPartida = other.dataPartida;
    this->jogadores = other.jogadores;
    this->campeaos = other.campeaos;
}

Partida::~Partida( ){}

void Partida::setJogadores( ){
    srand(time(0));
    for (int i = 0; i < 2; i++)
        jogadores.push_back( new Jogador(players[rand() %int(players.size())], 1, 2, "Ouro"));

}

void Partida::setCampeaos( ){
    srand(time(0));
    for (int i = 0; i < 2; i++)
        campeaos.push_back( new Campeao(champions[rand() %int(players.size())], "Mago", {"Prisão Plasmática", "Centelha Final"}));
}

void Partida::setPlacar ( AMAG placar, bool time){
    if(time){
        placarAzul.abates = placar.abates;
        placarAzul.assistencias = placar.assistencias;
        placarAzul.mortes = placar.mortes;
        placarAzul.gold = placar.gold;
        return;
    }
    placarVermelho.abates = placar.abates;
    placarVermelho.assistencias = placar.assistencias;
    placarVermelho.mortes = placar.mortes;
    placarVermelho.gold = placar.gold;
}

void Partida::getPlacar( ) const{
    cout << "Time Azul: \n";
    cout << "Abates: " << placarAzul.abates << '\n';
    cout << "Assistencias: " << placarAzul.assistencias << '\n';
    cout << "Mortes: " << placarAzul.mortes << '\n';
    cout << "Gold: " << placarAzul.gold << '\n';

    cout << "\nTime Vermelho: \n";
    cout << "Abates: " << placarVermelho.abates << '\n';
    cout << "Assistencias: " << placarVermelho.assistencias << '\n';
    cout << "Mortes: " << placarVermelho.mortes << '\n';
    cout << "Gold: " << placarVermelho.gold << '\n';
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

void Partida::getCampeaos( ) const{
    cout << "\nCampeãos!!!";
    for( int i = 0; i < int(campeaos.size()); i++ ){
        cout << "\nNome do Campeão: " << campeaos[i]->getNomeCampeao() << '\n'
        << "Função: " << campeaos[i]->getFuncao() << '\n';
        for( int j = 0; j < int(campeaos[i]->getNomeHabilidades().size()); j++ ){
            cout << "\nHabilidade " << j+1 << ": " << campeaos[i]->getNomeHabilidades()[j];
        }
    }
}