#include "Mouton.hpp"

Mouton::Mouton(){
    lifespan = 50;
    time_to_eat_before_dying = 5;
    S = rand() % 1;
    reproduced = 0;
}

void Mouton::eat(Pion& P){
    if (dynamic_cast<Herbe*>(&P) != nullptr){
        time_to_eat_before_dying += 5;
    }
}