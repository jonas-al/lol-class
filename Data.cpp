#include <iostream>
using std::cout;
#include <ctime>

class Data{
    public:
        Data( ){
            const int BASE_YEAR = 1900;
            time_t timer;
            tm * time;
            std::time(&timer);
            time = localtime(&timer);

            dia = time->tm_mday;
            mes = time->tm_mon+1;
            ano = time->tm_year + BASE_YEAR;
        }
        ~Data( ){}
        void print( ) const{
            cout << dia << '/' << mes << '/' <<ano;
        };

        int getDia() const{
            return dia;
        }

        int getMes() const{
            return mes;
        }

        int getAno() const{
            return ano;
        }
    private:
        int dia;
        int mes;
        int ano;
};