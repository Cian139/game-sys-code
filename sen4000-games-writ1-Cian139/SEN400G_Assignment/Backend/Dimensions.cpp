#include "Dimensions.h"

// Default constructor
Dimensions::Dimensions() : width(0), height(0) {}

// Overloaded constructor
Dimensions::Dimensions(unsigned short w, unsigned short h) : width(w), height(h) 
{

}

// Copy constructor
Dimensions::Dimensions(const Dimensions &other) : width(other.width), height(other.height) 
{

}

// Equals operator
Dimensions& Dimensions::operator=(const Dimensions &other)
{
    if (this != &other)
    {
        width = other.width;
        height = other.height;
    }
    return *this;
}

// The getter for width
unsigned short Dimensions::getWidth() const 
{
    return width;
}

// The setter for width
void Dimensions::setWidth(unsigned short w) 
{
    width = w;
}

// The getter for height
unsigned short Dimensions::getHeight() const 
{
    return height;
}

// The setter for height
void Dimensions::setHeight(unsigned short h) 
{
    height = h;
}