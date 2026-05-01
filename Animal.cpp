#include "Animal.hpp"

void Animal::time_before_dying(){
    if (time_to_eat_before_dying == 0){
        add_salt = 1;
    }
    else{
        time_to_eat_before_dying--;
    }
}

void Animal::repro(Animal& P){
    if(typeid(this) == typeid(P) && this->S != P.S){
        if(S == 1){
            reproduced = 2;
            P.reproduced = 1;
        }
        else{
            reproduced = 1;
            P.reproduced = 2;
        }

    }
}

void Animal::play_turn(Pion& P){
    time_before_dying();
    if(typeid(this) != typeid(P))
        eat(P);
    else
        repro(*(dynamic_cast<Animal*>(&P)));

}