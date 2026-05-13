#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "Pion.hpp"

class Animal: public Pion{
protected:
    int lifespan;
    int S;
    int time_to_eat_before_dying;
    int reproduced;
    int moved;

public:
    virtual void eat(std::shared_ptr<Pion> P) = 0;
    int time_before_dying();
    void repro(std::shared_ptr<Animal> P);
    void play_turn(std::shared_ptr<Pion> P);
    int get_reproduced_status();
    void reset_reproduced_status();
    void reset_moved();
    int get_moved();

    

};


#endif