#pragma once

#include <iostream>
#include <string>


class Light 
{
public:
    Light(int id) : id(id) {};

    void on() {
        std::cout << "Light " << std::to_string(id) << " is on" << std::endl;
    }
    void off() {
        std::cout << "Light " << std::to_string(id) << " is off" << std::endl;
    }

protected:
    int id;
};