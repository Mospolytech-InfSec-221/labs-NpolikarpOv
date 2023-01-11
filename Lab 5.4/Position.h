#pragma once
#include <iostream>
class Position
{
private:
public:
	int x_coord, y_coord;
	Position();
	Position(int, int);
	~Position();
	void set_coords(int, int);
	void print_coords();
};