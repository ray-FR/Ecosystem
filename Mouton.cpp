#include "Mouton.hpp"

Mouton::Mouton(){
    lifespan = 50;
    time_to_eat_before_dying = 5;
    S = rand() % 2;
    reproduced = 0;
}

void Mouton::eat(std::shared_ptr<Pion> P){
    if (auto a = std::dynamic_pointer_cast<Herbe>(P)){
        std::cout << ": Le mouton a mangé de l'herbe de la case ";


        time_to_eat_before_dying += 5;
    }
    else {
        std::cout << ": Le mouton est allé à la case ";
    }
}