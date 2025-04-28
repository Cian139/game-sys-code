<<<<<<< HEAD
#ifndef LIGHT_H
#define LIGHT_H

#include "Vector3.h"

class Light {
private:
    Vector3 position;

public:
    // The  constructors
    Light(); // Default constructor
    Light(const Vector3& pos); // Constructor with position

    // The print Light details
    void print() const;

    // The getter
    Vector3 getPosition() const;

    // The setter
    void setPosition(const Vector3& pos);
};

#endif // Light_H
=======
#pragma once
>>>>>>> bdea61c6ae87bddeec293423fa8e171ceb502842
