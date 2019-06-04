#ifndef SUBMARINO_HPP
#define SUBMARINO_HPP

#include <string>
#include "barco.hpp"

using namespace std;

class Submarino : public Barco {
    public:
        Submarino();
        ~Submarino();
        int get_casas();
        void set_casas(int casas);
};

#endif
