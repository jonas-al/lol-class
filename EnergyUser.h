#ifndef ENERGYUSER_H
#define ENERGYUSER_H

#include "Melee.h"

class EnergyUser : public Melee{

    public:
        EnergyUser( int, int, int, float, int, float, bool, const string &, int, vector<string>, bool);

        void usarUltimate();
        int usarHabilidade();
        void subirNivel();
        void abate();
        void assistencia();
        void avanco();
        void furtividade();
        void recarregar();
        void assasinar();

    private:
        int energiaInical;
        int energiaRegen;
        int MAXENERGIA = 200;
};

#endif