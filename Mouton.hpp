#ifndef MOUTON_HPP
#define MOUTON_HPP
#include "Animal.hpp"
#include "Herbe.hpp"

class Mouton: public Animal{
public:
    Mouton();
    void eat(std::shared_ptr<Pion> P) override;
}; 




#endif