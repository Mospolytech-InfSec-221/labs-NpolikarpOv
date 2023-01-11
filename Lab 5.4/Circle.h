#pragma once
#include <iostream>
#include "Position.h"
class Circle : public virtual Position { // кристалл смерти
private:
	int radius;
public:
	Circle();
	Circle(int, int, int);
	~Circle();
	void set_radius(int);
	void print_radius();
	double length_circle();
	double area_circle();
};