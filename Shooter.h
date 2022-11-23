#ifndef SHOOTER_H
#define SHOOTER_H

#include <iostream>

#include "Ranged.cpp"

class Shooter : public Ranged{

    friend ostream & operator<<( ostream &, const Shooter & );

    public:
        Shooter( const string &, int, float, int, const string &, const string &, const string &, vector<string> );
        Shooter();
        Shooter( const Shooter & );
        
        Shooter & operator=(const Shooter &);
        bool operator==(const Shooter &) const;
        bool operator!=(const Shooter &) const;
        void operator!();

    private:
        string tipoArma;
        const float MAXCDREDUCTION = 2.5;
};

#endif