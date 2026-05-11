#include "Mouton.hpp"

Mouton::Mouton(){
    lifespan = 50;
    time_to_eat_before_dying = 5;
    S = rand() % 2;
    reproduced = 0;
}

void Mouton::eat(Pion& P){
    std::cout << "im a sheep" << std::endl;
    if (dynamic_cast<Herbe*>(&P) != nullptr){
        time_to_eat_before_dying += 5;
        P.set_salt(2);
    }
}