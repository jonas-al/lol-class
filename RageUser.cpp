#include "RageUser.h"

map<int, vector<string>> RageUser::acoes = { 
    {0, {"Usar Habilidade", "Usar Ultimate", "Soco", "Liberar Furia", "Transformar"}},
    {1, {"Avanço", "Desviar"}},
    {2, {"Furtividade"}}
};

RageUser::RageUser(
    int furiaInicial,
    float furiaRegen,
    float chanceDesvio,
    float bonusDanoVida,
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
furiaInicial(furiaInicial),
furiaRegen(furiaRegen),
Fighter(
    chanceDesvio,
    bonusDanoVida,
    armaduraInicial,
    armaduraNivel,
    mrInicial,
    mrNivel,
    furtivo,
    nome,
    vidaIncial,
    escudoInicial,
    nomeHabilidades,
    habilitado
){}

RageUser::RageUser( const RageUser &other ):Fighter(other){
    this->furiaInicial = other.furiaInicial;
    this->furiaRegen = other.furiaRegen;
}

RageUser::RageUser(){
    RageUserStruct campeao = Campeao::getChampRageUser();
    this->furiaInicial = campeao.furiaInicial;
    this->furiaRegen = campeao.furiaRegen;
}

ostream & operator<<( ostream &output, const RageUser &campeao ){
    output << static_cast< Fighter >(campeao) << '\n' <<
    "Furia Inicial: " << campeao.furiaInicial << '\n' <<
    "Regeneração de Furia: " << campeao.furiaRegen*100 <<'%'<< '\n';

    return output;
}

RageUser & RageUser::operator=(const RageUser &other){
    if(this != &other){
        *static_cast< Fighter * >( this ) = static_cast< Fighter >( other );
        this->furiaInicial = other.furiaInicial;
        this->furiaRegen = other.furiaRegen;
    }
    return *this;
}

bool RageUser::operator==(const RageUser &other) const{
    if(static_cast< Fighter >(*this) != static_cast< Fighter >(other) ||
    this->furiaInicial != other.furiaInicial || 
    this->furiaRegen != other.furiaRegen) return false;

    return true;
}

bool RageUser::operator!=(const RageUser &other) const{
    if(static_cast< Fighter >(*this) == static_cast< Fighter >(other) && 
    *this  == other) return false;

    return true;
}

void RageUser::operator!(){
    this->setHabilitado(!this->getHabilitado());
}

int RageUser::usarUltimate(){
    int danoCausado;
    static_cast< Fighter >(*this).usarUltimate();
    
    danoCausado = (15 + (this->getFuriaInicial()*1))*this->getBonusDanoVida();
    return danoCausado;
}

int RageUser::usarHabilidade(){
    int danoCausado;
    cout << "usando uma habilidade... - RageUser" << '\n';
    cout << "usando uma habilidade... - Caster" << '\n';
    cout << "Escolha uma habilidade para usar: " << '\n';
    int escolha;
    for( auto i = 0; i < this->getNomeHabilidades().size(); i++){
        cout << i+1 << " - " << this->getNomeHabilidades()[i] << '\n';
    }
    cout << "Escolha uma habilidade: ";
    cin >> escolha;
    
    danoCausado = (25 + (this->getFuriaInicial()*1))*this->getBonusDanoVida();
    return danoCausado;
}

void RageUser::avanco(){
    this->setVida(this->getVida() + (this->getVida()*this->furiaRegen));
    this->setFuriaInicial(this->getFuriaInicial()*this->furiaRegen);
}

void RageUser::furtividade(){
    this->setFurtivo();
}

int RageUser::soco(){
    int danoCausado;
    danoCausado = (10 + (this->getFuriaInicial()*1))*this->getBonusDanoVida();
    return danoCausado;
}

void RageUser::desviar(){
    this->setChanceDesvio(this->getChanceDesvio()+0.1);
}

int RageUser::liberarFuria(){
    int danoCausado;
    danoCausado = (10 + (this->getFuriaInicial()*1))*this->getBonusDanoVida();
    return danoCausado;
}
int RageUser::transformar(){
    int danoCausado;
    this->usarUltimate();
    danoCausado = (10 + (this->getFuriaInicial()*1))*this->getBonusDanoVida();
    return danoCausado;
}

int RageUser::realizarAcao( int acaoEscolhida, Campeao &inimigo ){
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
    if (acaoEscolhida == 0 && escolhaHabilidade == 2){
        return this->soco();
    }
    if (acaoEscolhida == 0 && escolhaHabilidade == 3){
        return this->liberarFuria();
    }
    if (acaoEscolhida == 0 && escolhaHabilidade == 4){
        this->transformar();
        return 0;
    }
    if (acaoEscolhida == 1 && escolhaHabilidade == 0){
        this->avanco();
        return 0;
    }
    if (acaoEscolhida == 1 && escolhaHabilidade == 1){
        this->desviar();
        return 0;
    }
    if (acaoEscolhida == 2 && escolhaHabilidade == 0){
        this->furtividade();
        return 0;
    }
}

void RageUser::sofrerDano( int danoBruto ){
    if(!this->getFurtivo()){
        int danoSofrido = danoBruto  - (this->getArmaduraInicial() - this->getMrInicial());
        if(danoSofrido <= 0){
            cout << "Dano sofrido: " << danoSofrido << '\n';
            this->setVida( this->getVida() - (this->getArmaduraInicial()+this->getMrInicial()));
            return;
        }
        cout << "Dano sofrido: " << danoSofrido << '\n';
        this->setVida( this->getVida() - danoSofrido );
    }
}

int RageUser::getFuriaInicial(){return this->furiaInicial;}

void  RageUser::setFuriaInicial( int furia ){
    this->furiaInicial += furia;
}