#pragma once
#include <iostream>
#include "Circle.h"
#include "Square.h"
class CircleInSquare : public Circle, public Square {
public:
	CircleInSquare();
	CircleInSquare(int, int, int);
	~CircleInSquare();
};