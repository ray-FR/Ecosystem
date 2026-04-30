#ifndef MOUTON_HPP
#define MOUTON_HPP
#include "Animal.hpp"
class Mouton: public Animal{
public:
    Mouton();
    void eat(Pion P) override;
}; 




#endif