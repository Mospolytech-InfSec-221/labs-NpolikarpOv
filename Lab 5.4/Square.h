#pragma once
#include <iostream>
#include "Position.h"
class Square: public virtual Position{ // ромбовидное наследование (кристалл смерти)
private:
	int a;
public:
	Square();
	Square(int, int, int);
	~Square();
	void set_a(int);
	void print_a();
	int length_square();
	int area_square();
};