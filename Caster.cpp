#include "Caster.h"

map<int, vector<string>> Caster::acoes = { 
    {0, {"Usar Habilidade", "Usar Ultimate", "Explodir Poder"}},
    {1, {"Afastar"}},
    {2, {"Artodoar", "Transcender"}}
};

Caster::Caster(
    int poderHabilidade,
    float danoBonus,
    float vampMagico,
    const string &tipoMagia,
    float penetracaoMagica,
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
poderHabilidade(poderHabilidade),
danoBonus(danoBonus),
vampMagico(vampMagico),
Mage(
    tipoMagia,
    penetracaoMagica,
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
    habilitado
){}

Caster::Caster(){
    CasterStruct campeao = Campeao::getChampCaster();
    this->poderHabilidade = campeao.poderHabilidade;
    this->danoBonus = campeao.danoBonus;
    this->vampMagico = campeao.vampMagico;
}

Caster::Caster( const Caster &other ):Mage(other){
    this->poderHabilidade = other.poderHabilidade;
    this->danoBonus = other.danoBonus;
    this->vampMagico = other.vampMagico;
}

ostream & operator<<( ostream &output, const Caster &campeao ){
    output << static_cast< Mage >(campeao) << '\n' <<
    "Poder de Habilidade: " << campeao.poderHabilidade << '\n' <<
    "Dano Bônus: " << campeao.danoBonus << '\n' <<
    "Vampirismo Mágico: " << campeao.vampMagico*100 <<'%'<<'\n';

    return output;
}

Caster & Caster::operator=(const Caster &other){
    if(this != &other){
        *static_cast< Mage * >( this ) = static_cast< Mage >( other );
        this->poderHabilidade = other.poderHabilidade;
        this->danoBonus = other.danoBonus;
        this->vampMagico = other.vampMagico;
    }
    return *this;
}

bool Caster::operator==(const Caster &other) const{
    if(static_cast< Mage >(*this) != static_cast< Mage >(other) ||
    this->poderHabilidade != other.poderHabilidade || 
    this->danoBonus != other.danoBonus || 
    this->vampMagico != other.vampMagico) return false;

    return true;
}

bool Caster::operator!=(const Caster &other) const{
    if(static_cast< Mage >(*this) == static_cast< Mage >(other) && 
    *this  == other) return false;

    return true;
}

void Caster::operator!(){
    this->setHabilitado(!this->getHabilitado());
}

int Caster::usarUltimate(){
    int danoCausado;
    static_cast< Mage >(*this).usarUltimate();
    this->setPoderHabilidade(this->getPoderHabilidade()+(this->getPoderHabilidade()*0.2));
    this->setDanoBonus(this->getDanoBonus()+(getDanoBonus()*0.1));

    danoCausado = (10 + (this->getPoderHabilidade()*0.7))*this->getDanoBonus();
    this->setVida(danoCausado*this->getVampMagico());
    
    return danoCausado;
}

int Caster::usarHabilidade(){
    int danoCausado;
    cout << "Escolha uma habilidade para usar: " << '\n';
    int escolha;
    for( auto i = 0; i < this->getNomeHabilidades().size(); i++){
        cout << i+1 << " - " << this->getNomeHabilidades()[i] << '\n';
    }
    cout << "Escolha uma habilidade: ";
    cin >> escolha;
    
    danoCausado = (50 + (this->getPoderHabilidade()*0.7));
    danoCausado += (danoCausado*this->getDanoBonus());
    this->setVida(this->getVida() + danoCausado*this->getVampMagico());
    return danoCausado;
}

void Caster::afastar(){
    cout << "sai de min :# - Caster" << '\n';
    static_cast< Mage >(*this).afastar();
    this->setVampMagico(0.2);
}

void Caster::artodoar( Campeao &inimigo ){
    inimigo.setHabilitado(false);
}

int Caster::explodirPoder(){
    int danoCausado;

    danoCausado = (50 + (this->getPoderHabilidade()*0.9))*this->getDanoBonus();
    this->setVida(this->getVida() + danoCausado*this->getVampMagico());
    return danoCausado;
}
void Caster::transcender(){
    this->setPoderHabilidade(this->getPoderHabilidade()+(this->getPoderHabilidade()*0.5));
}

int Caster::realizarAcao( int acaoEscolhida, Campeao &inimigo ){
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
    if (acaoEscolhida == 0 && escolhaHabilidade == 3){
        return this->explodirPoder();
    }
    if (acaoEscolhida == 1 && escolhaHabilidade == 1){
        this->afastar();
        return 0;
    }
    if (acaoEscolhida == 2 && escolhaHabilidade == 0){
        this->artodoar(inimigo);
        return 0;
    }
    if (acaoEscolhida == 2 && escolhaHabilidade == 2){
        this->transcender();
        return 0;
    }
}

void Caster::setPoderHabilidade( int PH ){
    this->poderHabilidade += PH;
}
void Caster::setDanoBonus( int danoBonus ){
    this->danoBonus += danoBonus;
}
void Caster::setVampMagico( float vampMagico ){
    this->vampMagico += vampMagico;
}
int Caster::getPoderHabilidade(){
    return this->poderHabilidade;
}
int Caster::getDanoBonus(){
    return this->danoBonus;
}
float Caster::getVampMagico(){
    return this->vampMagico;
}