#ifndef PION_HPP
#define PION_HPP
#include <iostream>
#include <memory>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

class Pion{
protected:
    int add_salt;
public:
    void set_salt(int c);
    int get_salt();
    virtual ~Pion() = default;   
};

#endif