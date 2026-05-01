#include "Loup.hpp"


Loup::Loup(){
    lifespan = 60;
    time_to_eat_before_dying = 10;
    S = rand() % 1;
    reproduced = 0;
}

void Loup::eat(Pion& P){
    if (dynamic_cast<Mouton*>(&P) != nullptr){
        time_to_eat_before_dying += 10;
    }
}


    
