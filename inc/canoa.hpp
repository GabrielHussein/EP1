#ifndef CANOA_HPP
#define CANOA_HPP

#include <string>
#include "barco.hpp"

using namespace std;

class Canoa : public Barco {
    public:
      Canoa();
      ~Canoa();
      int get_casas();
      void set_casas(int casas);
};

#endif
