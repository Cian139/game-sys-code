#include "Light.h"
#include <iostream>

Light::Light() : position() {}

Light::Light(const Vector3& pos)
    : position(pos)
{

}

void Light::print() const 
{
    std::cout << "Light:\n"
        << "  Position: " << position.toString() << "\n";
}


Vector3 Light::getPosition() const 
{
    return position;
}


void Light::setPosition(const Vector3& pos) 
{
    position = pos;
}

