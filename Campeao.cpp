#include "Campeao.h"
#include "Caster.h"
#include "Shooter.h"

Campeao::Campeao(const string &nome, int vida, int escudo,vector<string> nomeHabilidades, bool habilitado):nomeCampeao(nome), vidaIncial(vida), escudoInicial(escudo),nomeHabilidades(nomeHabilidades), habilitado(habilitado){}

Campeao::Campeao(){
    int escolha = this->selecionarCampeao();

    if(escolha == 1){
        SupportStruct campeao = Campeao::getChampSupport();
        this->campeaoSelecionado = 1;
        this->nomeCampeao = campeao.nome;
        this->vidaIncial = campeao.vidaIncial;
        this->escudoInicial = campeao.escudoInicial;
        this->habilitado = campeao.habilitado;
        this->nomeHabilidades = campeao.nomeHabilidades;
    }

    if(escolha == 2){
        CasterStruct campeao = Campeao::getChampCaster();
        this->campeaoSelecionado = 2;
        this->nomeCampeao = campeao.nome;
        this->vidaIncial = campeao.vidaIncial;
        this->escudoInicial = campeao.escudoInicial;
        this->habilitado = campeao.habilitado;
        this->nomeHabilidades = campeao.nomeHabilidades;
    }

    if(escolha == 3){
        ShooterStruct campeao = Campeao::getChampShooter();
        this->campeaoSelecionado = 3;
        this->nomeCampeao = campeao.nome;
        this->vidaIncial = campeao.vidaIncial;
        this->escudoInicial = campeao.escudoInicial;
        this->habilitado = campeao.habilitado;
        this->nomeHabilidades = campeao.nomeHabilidades;
    }

    if(escolha == 4){
        RageUserStruct campeao = Campeao::getChampRageUser();
        this->campeaoSelecionado = 4;
        this->nomeCampeao = campeao.nome;
        this->vidaIncial = campeao.vidaIncial;
        this->escudoInicial = campeao.escudoInicial;
        this->habilitado = campeao.habilitado;
        this->nomeHabilidades = campeao.nomeHabilidades;
    }

    if(escolha == 5){
        TankStruct campeao = Campeao::getChampTank();
        this->campeaoSelecionado = 5;
        this->nomeCampeao = campeao.nome;
        this->vidaIncial = campeao.vidaIncial;
        this->escudoInicial = campeao.escudoInicial;
        this->habilitado = campeao.habilitado;
        this->nomeHabilidades = campeao.nomeHabilidades;
    }
}

Campeao::Campeao( const Campeao &other ){
    this->nomeCampeao = other.nomeCampeao;
    this->vidaIncial = other.vidaIncial;
    this->escudoInicial = other.escudoInicial;
    this->nomeHabilidades = other.nomeHabilidades;
    this->habilitado = other.habilitado;
}

Campeao::~Campeao( ){}

void Campeao::printCampeao() const{
    cout << "Nome do Campeão: " << this->nomeCampeao << '\n';
    cout << "Vida Inicial: " << this->vidaIncial << '\n';
    cout << "Escudo Inicial: " << this->escudoInicial << '\n';
    this->printHabilidades();
    cout << "Habilitado: " << this->vidaIncial << '\n';
}

void Campeao::printHabilidades() const{
    for(int i = 0; i < int(nomeHabilidades.size()); i++){
        cout <<"Habilidade "<<i+1<<": "<< nomeHabilidades[i] << '\n';
    }
}

void Campeao::setVida( int vida ){
    this->vidaIncial = vida;
}

void Campeao::setEscudo( int escudo ){
    this->escudoInicial += escudo;
}

void Campeao::setHabilitado( bool estado ){
    this->habilitado = estado;
}

void Campeao::sofrerDano( int danoSofrido ){
    this->setVida( this->getVida() - danoSofrido );
}

int Campeao::selecionarCampeao(){
    int escolha;
    cout << "Escolha uma das seguintes classes: \n";
    cout << "1 - Support, 2 - Caster, 3 - Shooter, 4 - Rage User, 5 - Tank\n";
    cout << "Digite sua escolha: ";
    cin >> escolha;

    return escolha;
}

void Campeao::batalha( vector < Campeao * > campeoes ){
    vector<string> classes;
    string classe, vencedor;
    int acaoEscolhida;
    Caster *casterPtr; Shooter *shooterPtr;
    for (int i = 0; i < int(campeoes.size()); i++){
        casterPtr = dynamic_cast < Caster * >( campeoes[ i ] );
        shooterPtr = dynamic_cast < Shooter * >( campeoes[ i ] );
        if(casterPtr != 0){
            campeoes[ i ]->setVida(campeoes[ i ]->getVida() + campeoes[ i ]->getEscudo());
        }
        if(shooterPtr != 0){
            campeoes[ i ]->setVida(campeoes[ i ]->getVida() + campeoes[ i ]->getEscudo());
        }
        classe = typeid(*campeoes[i]).name();
        classe.erase(classe.begin());
        classes.push_back(classe);
    }
    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << '\n';
    cout << "Batalha entre um campeão da classe " << classes[0] << " e um campeão da classe " << classes[1] << "!!!\n";
    while(campeoes[0]->getVida() > 0 && campeoes[1]->getVida() > 0 ){
        if(campeoes[0]->getHabilitado()){
            cout << "\nÉ a vez do(a) " << campeoes[0]->getNomeCampeao()<< '\n';
            cout <<"Vida atual: " << campeoes[0]->getNomeCampeao() << ": " << campeoes[0]->getVida() << '\n';
            cout <<"Vida atual: " << campeoes[1]->getNomeCampeao() << ": " << campeoes[1]->getVida() << '\n';
            cout << "Selecione uma ação!!!" << '\n';
            cout << "1 - Atacar, 2 - Defender, 3 - Efeito: ";
            cin >> acaoEscolhida; acaoEscolhida -= 1;

            if(acaoEscolhida == 0){
            campeoes[1]->sofrerDano(campeoes[0]->realizarAcao(acaoEscolhida, *campeoes[1]));
            }
            if(acaoEscolhida == 1){
            campeoes[0]->realizarAcao(acaoEscolhida, *campeoes[1]);
            }
            if(acaoEscolhida == 2){
            campeoes[0]->realizarAcao(acaoEscolhida, *campeoes[1]);
            }
        }

        if(campeoes[1]->getVida() > 0 && campeoes[1]->getHabilitado()){
            cout << "\nÉ a vez do(a) " << campeoes[1]->getNomeCampeao()<< '\n';
            cout <<"Vida atual: " << campeoes[0]->getNomeCampeao() << ": " << campeoes[0]->getVida() << '\n';
            cout <<"Vida atual: " << campeoes[1]->getNomeCampeao() << ": " << campeoes[1]->getVida() << '\n';
            cout << "Selecione uma ação!!!" << '\n';
            cout << "1 - Atacar, 2 - Defender, 3 - Efeito: ";
            cin >> acaoEscolhida; acaoEscolhida -= 1;

            if(acaoEscolhida == 0){
            campeoes[0]->sofrerDano(campeoes[1]->realizarAcao(acaoEscolhida, *campeoes[1]));
            }
            if(acaoEscolhida == 1){
            campeoes[1]->realizarAcao(acaoEscolhida, *campeoes[1]);
            }
            if(acaoEscolhida == 2){
            campeoes[1]->realizarAcao(acaoEscolhida, *campeoes[1]);
            }
        }
    }
    cout << "O vencedor é: ";
    campeoes[0]->getVida() > 0? (cout << campeoes[0]->getNomeCampeao()) : (cout << campeoes[1]->getNomeCampeao());
}