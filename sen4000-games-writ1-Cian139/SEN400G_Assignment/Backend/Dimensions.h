#ifndef DIMENSIONS_H
#define DIMENSIONS_H



class Dimensions
{
private:
	unsigned short width;
	unsigned short height;

public:
	//  The default constructor
	Dimensions();

	// The overloaded constructor
	Dimensions(unsigned short w, unsigned short h);

	// The copy constructor
	Dimensions(const Dimensions &other);

	// The equals operator
	Dimensions& operator=(const Dimensions &other);

	// The getter for width
	unsigned short getWidth() const;

	// The setter for width
	void setWidth(unsigned short w);

	// The getter for height
	unsigned short getHeight() const;

	// The setter for height
	void setHeight(unsigned short h);
};

#endif // Dimensions_H