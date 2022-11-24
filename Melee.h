#ifndef MELEE_H
#define MELEE_H

#include <iostream>

#include "Campeao.cpp"

class Melee : public Campeao{

    friend ostream & operator<<( ostream &, const Melee & );

    public:
        Melee( int, float, int, float, bool, string, string, string, vector<string>);
        Melee();
        Melee( const Melee &);

        Melee & operator=(const Melee &);
        bool operator==(const Melee &) const;
        bool operator!=(const Melee &) const;
        void operator!();

    private:
        int armaduraInicial;
        float armaduraNivel;
        int mrInicial;
        float mrNivel;
        bool mana;
};

#endif