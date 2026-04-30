#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "Pion.hpp"

class Animal: public Pion{
protected:
    int lifespan;
    int S;
    int time_to_eat_before_dying;

public:
    virtual void eat(Pion P);
    void time_before_dying();
    void repro();

    

};


#endif