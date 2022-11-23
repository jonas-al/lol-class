#ifndef MAGE_H
#define MAGE_H

#include <iostream>

#include "Ranged.cpp"

class Mage : public Ranged{

    friend ostream & operator<<( ostream &, const Mage & );

    public:
        Mage( const string &, int, float, int, const string &, const string &, const string &, vector<string> );
        Mage();
        Mage( const Mage & );
        Mage & operator=(const Mage &);
        bool operator==(const Mage &) const;
        bool operator!=(const Mage &) const;
        void operator!();

    private:
        string tipoMagia;
        const float MAXCDREDUCTION = 0.4;
};

#endif