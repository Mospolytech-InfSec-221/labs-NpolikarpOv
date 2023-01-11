#include "Circle.h"

Circle::Circle()
{
	this->radius = 0;
}

Circle::Circle(int x, int y, int rad): Position(x, y)
{
	this->radius = rad;
}

Circle::~Circle()
{
}

void Circle::set_radius(int rad)
{
	this->radius = rad;
}

void Circle::print_radius()
{
	std::cout << "Radius: " << this->radius;
}

double Circle::length_circle()
{
	return 3.14 * 2 * this->radius;
}

double Circle::area_circle()
{
	return 3.14 * this->radius * this->radius;
}
