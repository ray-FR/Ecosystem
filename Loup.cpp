#include "Loup.hpp"


Loup::Loup(){
    lifespan = 60;
    time_to_eat_before_dying = 10;
    S = rand() % 2;
    reproduced = 0;
}

void Loup::eat(Pion& P){
    std::cout << "im a wolf" << std::endl;
    if (dynamic_cast<Mouton*>(&P) != nullptr){
        time_to_eat_before_dying += 10;
        P.set_salt(2);
        
    }
}


    
