#ifndef PION_HPP
#define PION_HPP
#include <iostream>

class Pion{
protected:
    int add_salt;
public:
    virtual void play_turn(Pion& P) = 0;    
};

#endif