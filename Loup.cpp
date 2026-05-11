#include "Loup.hpp"


Loup::Loup(){
    srand(time(NULL));
    lifespan = 60;
    time_to_eat_before_dying = 10;
    S = rand() % 2;
    reproduced = 0;
}

void Loup::eat(std::shared_ptr<Pion> P){
    if (auto a = std::dynamic_pointer_cast<Mouton>(P)){
        time_to_eat_before_dying += 10;
        P->set_salt(2);
        
    }
}


    
