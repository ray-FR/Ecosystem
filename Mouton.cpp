#include "Mouton.hpp"

Mouton::Mouton(){
    srand(time(NULL));
    lifespan = 50;
    time_to_eat_before_dying = 5;
    S = rand() % 2;
    reproduced = 0;
}

void Mouton::eat(std::shared_ptr<Pion> P){
    if (auto a = std::dynamic_pointer_cast<Mouton>(P)){
        time_to_eat_before_dying += 5;
        P->set_salt(2);
    }
}