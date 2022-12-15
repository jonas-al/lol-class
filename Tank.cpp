#include "Tank.h"

map<int, vector<string>> Tank::acoes = { 
    {0, {"Usar Habilidade", "Usar Ultimate"}},
    {1, {"Avanço", "Enrijecer", "Proteger"}},
    {2, {"Furtividade"}}
};

Tank::Tank
(
    float reducaoDano,
    float bonusVida,
    int armaduraInicial, 
    float armaduraNivel, 
    int mrInicial, 
    float mrNivel,
    bool furtivo,
    const string &nome,
    int vidaIncial,
    int escudoInicial,
    vector<string> nomeHabilidades,
    bool habilitado
):
reducaoDano(reducaoDano),
bonusVida(bonusVida),
Melee( 
    armaduraInicial, 
    armaduraNivel, 
    mrInicial, 
    mrNivel,
    furtivo,
    nome,
    vidaIncial,
    escudoInicial,
    nomeHabilidades,
    habilitado){}

Tank::Tank( const Tank &other ):Melee(other){
    this->reducaoDano = other.reducaoDano;
    this->bonusVida = other.bonusVida;
}

Tank::Tank(){
    TankStruct campeao = Campeao::getChampTank();
    this->reducaoDano = campeao.reducaoDano;
    this->bonusVida = campeao.bonusVida;
}

ostream & operator<<( ostream &output, const Tank &campeao ){
    campeao.printCampeao();
    output << "Redução de Dano: " << campeao.reducaoDano<< '\n' <<
    "Bônus de Vida: " << campeao.bonusVida*100 <<'%'<< '\n';

    return output;
}

Tank & Tank::operator=(const Tank &other){
    if(this != &other){
        this->reducaoDano = other.reducaoDano;
        this->bonusVida = other.bonusVida;
    }
    return *this;
}

bool Tank::operator==(const Tank &other) const{
    if( this->reducaoDano != other.reducaoDano || 
    this->bonusVida != other.bonusVida ) return false;

    return true;
}

bool Tank::operator!=(const Tank &other) const{
    if(*this == other) return false;

    return true;
}

void Tank::operator!(){
    this->setHabilitado(!this->getHabilitado());
}

int Tank::usarUltimate(){
    int danoCausado;
    cout << "usando ultimate... - Tank" << '\n';
    
    danoCausado = (15 + (this->getArmaduraInicial() + this->getMrInicial()));
    return danoCausado;
}

int Tank::usarHabilidade(){
    int danoCausado;
    cout << "usando uma habilidade... - Tank" << '\n';
    cout << "Escolha uma habilidade para usar: " << '\n';
    int escolha;
    for( auto i = 0; i < this->getNomeHabilidades().size(); i++){
        cout << i+1 << " - " << this->getNomeHabilidades()[i] << '\n';
    }
    cout << "Escolha uma habilidade: ";
    cin >> escolha;
    
    danoCausado = (40 + (this->getArmaduraInicial() + this->getMrInicial()));
    return danoCausado;
}

void Tank::avanco(){
    cout << "Avançando :D - Tank" << '\n';
    this->setVida(this->getVida()*this->getBonusVida());
}
void Tank::furtividade(){
    cout << "Me escondi :@ - Tank" << '\n';
    this->setFurtivo();
}

void Tank::enrijecer(){
    cout << "enrijecer - Tank" << '\n';
    this->setArmaduraInicial(.10);
    this->setMrInicial(.10);
    this->setReducaoDano(.20);
    this->setVida(this->getVida() + (this->getVida()*this->getBonusVida()));
}

void Tank::protejer(){
    cout << "eu te protejo :)))) - Tank" << '\n';
    this->setReducaoDano(.2);
}

void Tank::sofrerDano( int danoBruto ){
    if(!this->getFurtivo()){
        int danoSofrido = danoBruto - (danoBruto*this->getReducaoDano()) - this->getArmaduraInicial() - this->getMrInicial();
        if(danoSofrido <= 0){
            this->setVida( this->getVida() - (this->getArmaduraInicial()+this->getMrInicial()));
            return;
        }
        cout << "Dano sofrido: " << danoSofrido << '\n';
        this->setVida( this->getVida() - danoSofrido );
    }
}

int Tank::realizarAcao( int acaoEscolhida, Campeao &inimigo ){
    int escolhaHabilidade;
    this->setFurtivo();
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
    if (acaoEscolhida == 1 && escolhaHabilidade == 0){
        this->avanco();
        return 0;
    }
    if (acaoEscolhida == 1 && escolhaHabilidade == 1){
        this->enrijecer();
        return 0;
    }
    if (acaoEscolhida == 1 && escolhaHabilidade == 2){
        this->protejer();
        return 0;
    }
    if (acaoEscolhida == 2 && escolhaHabilidade == 0){
        this->avanco();
        return 0;
    }
}

float Tank::getReducaoDano(){
    return this->reducaoDano;
}
float Tank::getBonusVida(){
    return this->bonusVida;
}
void Tank::setReducaoDano( float reducaoDano ){
    this->reducaoDano += reducaoDano;
}
float Tank::setBonusVida( float bonusVida ){
    this->bonusVida += bonusVida;
}