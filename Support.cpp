#include <iostream>
#include "Support.h"

map<int, vector<string>> Support::acoes = { 
    {0, {"Usar Habilidade", "Usar Ultimate"}},
    {1, {"Afastar"}},
    {2, {"Artodoar", "Escudo", "Cura"}}
};

Support::Support(
    int cura,
    int escudo,
    float resistenciaEscudo,
    float bonusCuraEscudo,
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
cura(cura),
escudo(escudo),
resistenciaEscudo(resistenciaEscudo),
bonusCuraEscudo(bonusCuraEscudo),
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

Support::Support(){
    SupportStruct campeao = Campeao::getChampSupport();
    this->cura = campeao.cura;
    this->escudo = campeao.escudo;
    this->resistenciaEscudo = campeao.resistenciaEscudo;
    this->bonusCuraEscudo = campeao.bonusCuraEscudo;
}

Support::Support( const Support &other ):Mage(other){
    this->cura= other.cura;
    this->escudo= other.escudo;
    this->resistenciaEscudo= other.resistenciaEscudo;
    this->bonusCuraEscudo= other.bonusCuraEscudo;
}

ostream & operator<<( ostream &output, const Support &campeao ){
    campeao.printCampeao();
    output << static_cast< Mage >(campeao) << '\n' <<
    "Cura: " << campeao.cura << '\n' <<
    "Escudo: " << campeao.escudo << '\n' <<
    "Resistência Escudo: " << campeao.resistenciaEscudo << '\n' <<
    "Bonus de Cura e Escudo: " << campeao.bonusCuraEscudo << '\n';

    return output;
}

Support & Support::operator=(const Support &other){
    if(this != &other){
        *static_cast< Mage * >( this ) = static_cast< Mage >( other );
        this->cura = other.cura;
        this->escudo = other.escudo;
        this->resistenciaEscudo = other.resistenciaEscudo;
        this->bonusCuraEscudo = other.bonusCuraEscudo;
    }
    return *this;
}

bool Support::operator==(const Support &other) const{
    if(static_cast< Mage >(*this) != static_cast< Mage >(other) ||
    this->cura != other.cura || 
    this->escudo != other.escudo || 
    this->resistenciaEscudo != other.resistenciaEscudo || 
    this->bonusCuraEscudo != other.bonusCuraEscudo) return false;

    return true;
}

bool Support::operator!=(const Support &other) const{
    if(static_cast< Mage >(*this) == static_cast< Mage >(other) && 
    *this  == other) return false;

    return true;
}

void Support::operator!(){
    this->setHabilitado(!this->getHabilitado());
}

int Support::usarUltimate(){
    cout << "usando ultimate... - Support" << '\n';
    static_cast< Mage >(*this).usarUltimate();
    this->setCura(this->getCura()+(this->getCura()*bonusCuraEscudo));
    this->setEscudo(this->getEscudo()+(this->getEscudo()*bonusCuraEscudo));

    return 0;
}

int Support::usarHabilidade(){
    cout << "usando uma habilidade... - Support" << '\n';
    cout << "Escolha uma habilidade para usar: " << '\n';
    int escolha;
    for( auto i = 0; i < this->getNomeHabilidades().size(); i++){
        cout << i+1 << " - " << this->getNomeHabilidades()[i] << '\n';
    }
    cout << "Escolha uma habilidade: ";
    cin >> escolha;

    return 0;
}

void Support::afastar(){
    cout << "afastar - Support" << '\n';
    static_cast< Mage >(*this).afastar();
    this->setBonusCura(15);
}

void Support::artodoar( Campeao &inimigo ){
    cout << "artodoar - Support" << '\n';
    inimigo.setHabilitado(false);
}
void Support::darEscudo(){
    cout << "darEscudo - Support" << '\n';
    int escudo = this->getEscudo() + (this->getEscudo() * this->getBonusCuraEscudo());
    static_cast< Mage >(*this).setEscudo(this->getEscudo() + escudo);
}
void Support::darCura(){
    cout << "darCura - Support" << '\n';
    int cura = this->getCura() + (this->getCura() * this->getBonusCuraEscudo());
    static_cast< Mage >(*this).setVida(this->getVida() + cura);
}

int Support::realizarAcao( int acaoEscolhida, Campeao &inimigo ){
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
    if (acaoEscolhida == 1 && escolhaHabilidade == 1){
        this->afastar();
        return 0;
    }
    if (acaoEscolhida == 2 && escolhaHabilidade == 0){
        this->artodoar(inimigo);
        return 0;
    }
    if (acaoEscolhida == 2 && escolhaHabilidade == 2){
        this->darEscudo();
        return 0;
    }
    if (acaoEscolhida == 2 && escolhaHabilidade == 3){
        this->darCura();
        return 0;
    }
}

int Support::getCura(){
    return this->cura;
}
int Support::getEscudo(){
    return this->escudo;
}
float Support::getResistenciaEscudo(){
    return this->resistenciaEscudo;
}
float Support::getBonusCuraEscudo(){
    return this->bonusCuraEscudo;
}
void Support::setCura( int cura ){
    this->cura += cura;
}
void Support::setEscudo( int escudo ){
    this->escudo += escudo;
}
void Support::setResistenciaEscudo( int resistenciaEscudo ){
    this->resistenciaEscudo += resistenciaEscudo;
}
void Support::setBonusCura( int bonusCura ){
    this->bonusCuraEscudo += bonusCura;
}