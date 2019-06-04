#ifndef BARCO_HPP
#define BARCO_HPP

#include <string>

using namespace std;

class Barco{
    protected:
        int casas;
        int vida;
        char nome;
    public:
        virtual ~Barco();
};

#endif
