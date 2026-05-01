#ifndef LOUP_HPP
#define LOUP_HPP
#include "Animal.hpp"
#include "Mouton.hpp"

class Loup: public Animal{
public:
    Loup();
    void eat(Pion& P) override;
}; 



#endif