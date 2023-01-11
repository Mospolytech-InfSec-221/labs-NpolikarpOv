#include "Square.h"

Square::Square()
{
	this->a = 0;
}

Square::Square(int a, int b, int rad): Position(a, b)
{
	this->a = rad;
}

Square::~Square()
{
}

void Square::set_a(int a)
{
	this->a = a;
}

void Square::print_a()
{
	std::cout << "Size of square: " << this->a;
}

int Square::length_square()
{
	return 4 * this->a;
}

int Square::area_square()
{
	return this->a * this->a;
}
