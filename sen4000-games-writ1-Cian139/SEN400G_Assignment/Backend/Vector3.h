#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>
#include <sstream> 

class Vector3
{
private:
    float x, y, z;

public:
  
    Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    // Getters
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    // Setters
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }

    
    std::string toString() const;
};
#endif // Vector3_H