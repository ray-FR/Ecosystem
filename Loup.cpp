#include "Loup.hpp"


Loup::Loup(){
    lifespan = 60;
    time_to_eat_before_dying = 10;
    S = rand() % 2;
    reproduced = 0;
}

void Loup::eat(std::shared_ptr<Pion> P){
    if (auto a = std::dynamic_pointer_cast<Mouton>(P)){
        if(a->get_salt() == 1)
            return;

        std::cout << ": Le loup a mangé le mouton de la case ";
        
        time_to_eat_before_dying += 10;        
    }
    else {
        std::cout << ": Le loup est allé à la case ";
    }
}


    
