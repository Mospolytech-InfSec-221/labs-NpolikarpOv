#include "Position.h"

Position::Position()
{
	this->x_coord = 0;
	this->y_coord = 0;
}

Position::Position(int x, int y)
{
	this->x_coord = x;
	this->y_coord = y;
}

Position::~Position()
{
}

void Position::set_coords(int x, int y)
{
	this->x_coord = x;
	this->y_coord = y;
}

void Position::print_coords()
{
	std::cout << "���������� x: " << x_coord << " ���������� y: " << y_coord;
}
