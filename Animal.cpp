#include "Animal.hpp"

int Animal::time_before_dying(){
    if (time_to_eat_before_dying == 0 || lifespan == 0){
        add_salt = 1;
        return 1;
    }
    
    time_to_eat_before_dying--;
    return 0;
    
}

void Animal::repro(std::shared_ptr<Animal> P){
    std::cout << "yes" << std::endl;
    if(typeid(this) == typeid(P) && this->S != P->S){
        std::cout << ": L'animal de cette case c'est reproduit avec celui de la case ";
        if(S == 1){
            reproduced = 2;
            P->reproduced = 1;
        }
        else{
            reproduced = 1;
            P->reproduced = 2;
        }

    }
}

void Animal::play_turn(std::shared_ptr<Pion> P){
    if (time_before_dying())
        return;
    if(typeid(*this) != typeid(P))
        eat(P);
    else
        repro(std::dynamic_pointer_cast<Animal>(P));
    moved = 1;

}

int Animal::get_reproduced_status(){
    return reproduced;
}


void Animal::reset_moved(){
    moved = 0;
}

void Animal::reset_reproduced_status(){
    reproduced = 0;
}
int Animal::get_moved(){
    return moved;
}