#include "Shooter.h"

map<int, vector<string>> Shooter::acoes = { 
    {0, {"Usar Habilidade", "Usar Ultimate", "Atirar"}},
    {1, {"Afastar", "Curar"}},
    {2, {"Curar"}}
};

Shooter::Shooter
(
    const string &tipoArma,
    int danoAtaque,
    float chanceCritico,
    int alcanceInicial, 
    float alcanceNivel, 
    int resistencias, 
    const string &tipoDano,
    int manaInicial,
    int manaNivel,
    int manaRegen,
    const string &nome,
    int vidaIncial,
    int escudoInicial,
    vector<string> nomeHabilidades,
    bool habilitado
):
tipoArma(tipoArma),
danoAtaque(danoAtaque),
chanceCritico(chanceCritico),
Ranged( 
    alcanceInicial, 
    alcanceNivel, 
    resistencias, 
    tipoDano,
    manaInicial,
    manaNivel,
    manaRegen,
    nome,
    vidaIncial,
    escudoInicial,
    nomeHabilidades,
    habilitado){}   

Shooter::Shooter(){
    ShooterStruct campeao = Campeao::getChampShooter();
    this->tipoArma = campeao.tipoArma;
    this->danoAtaque = campeao.danoAtaque;
    this->chanceCritico = campeao.chanceCritico;
}

Shooter::Shooter( const Shooter &other ){
    this->tipoArma = other.tipoArma;
    this->danoAtaque = other.danoAtaque;
    this->chanceCritico = other.chanceCritico;
}

ostream & operator<<( ostream &output, const Shooter &campeao ){
    campeao.printCampeao();
    output << "Tipo Arma: " << campeao.tipoArma << '\n' <<
    "Dano de Ataque: " << campeao.danoAtaque << '\n' <<
    "Chance de acerto crítico: " << campeao.chanceCritico*100 <<'%'<< '\n';

    return output;
}

Shooter & Shooter::operator=(const Shooter &other){
    if(this != &other){
        this->tipoArma = other.tipoArma;
        this->danoAtaque = other.danoAtaque;
        this->chanceCritico = other.chanceCritico;
    }
    return *this;
}

bool Shooter::operator==(const Shooter &other) const{
    if( this->tipoArma != other.tipoArma || 
    this->danoAtaque != other.danoAtaque ||
    this->chanceCritico != other.chanceCritico ) return false;

    return true;
}

bool Shooter::operator!=(const Shooter &other) const{
    if(*this == other) return false;

    return true;
}

void Shooter::operator!(){
    this->setHabilitado(!this->getHabilitado());
}

int Shooter::usarUltimate(){
    int danoCausado;
    cout << "usando ultimate... - Shooter" << '\n';
    this->setDanoAtaque(this->getDanoAtaque()+(this->getDanoAtaque()*0.4));
    this->setChanceCritico(this->getChanceCritico()+(getChanceCritico()*0.25));

    danoCausado = (10 + (this->getDanoAtaque()*0.7))*this->getChanceCritico();
    return danoCausado;
}

int Shooter::usarHabilidade(){
    int danoCausado;
    cout << "usando uma habilidade..." << '\n';
    cout << "Escolha uma habilidade para usar: " << '\n';
    int escolha;
    for( auto i = 0; i < this->getNomeHabilidades().size(); i++){
        cout << i+1 << " - " << this->getNomeHabilidades()[i] << '\n';
    }
    cout << "Escolha uma habilidade: ";
    cin >> escolha;
    
    danoCausado = (50 + (this->getDanoAtaque()*0.7))*this->getChanceCritico();
    return danoCausado;
}

void Shooter::afastar(){
    cout << "sai de min :# - Shooter" << '\n';
    this->setAlcanceInicial(25);
}

int Shooter::atirar(){
    int danoCausado;
    cout << "atirei :3 - Shooter" << '\n';
    danoCausado = (80 + (this->getDanoAtaque()*0.7))*this->getChanceCritico();
    return danoCausado;
}

void Shooter::curar(){
    cout << "curei mores :* - Shooter" << '\n';
    this->setVida(75 + (this->getDanoAtaque()*this->getChanceCritico()));
}

int Shooter::getDanoAtaque() const{
    return this->danoAtaque;
}
float Shooter::getChanceCritico() const{
    return this->chanceCritico;
}
void Shooter::setDanoAtaque( int danoAtaque ){
    this->danoAtaque = danoAtaque;
}
void Shooter::setChanceCritico( float chanceCritico ){
    this->chanceCritico = chanceCritico;
}
int Shooter::causarDano(){
    return 0;
}
void Shooter::sofrerDano( int danoSofrido ){
    this->setVida(this->getVida() - danoSofrido);
}
int Shooter::realizarAcao( int acaoEscolhida, Campeao &inimigo ){
    int escolhaHabilidade;
    cout << "Escolha um comando: " << '\n';
    for (int i = 0; i<acoes[acaoEscolhida].size(); i++){
        cout << i+1 << " - " << acoes[acaoEscolhida][i] << '\n';
    }
    cout << "Informe a sua escolha: ";
    cin >> escolhaHabilidade; escolhaHabilidade -= 1;

    if (acaoEscolhida == 0 && escolhaHabilidade == 0){
        return this->usarHabilidade();
    }
    if (acaoEscolhida == 0 && escolhaHabilidade == 1){
        return this->usarUltimate();
    }
    if (acaoEscolhida == 0 && escolhaHabilidade == 2){
        return this->atirar();
    }
    if (acaoEscolhida == 1 && escolhaHabilidade == 0){
        this->afastar();
        return 0;
    }
    if (acaoEscolhida == 1 && escolhaHabilidade == 1){
        this->curar();
        return 0;
    }
    if (acaoEscolhida == 2 && escolhaHabilidade == 0){
        this->curar();
        return 0;
    }
}