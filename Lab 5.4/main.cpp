#include <iostream>
#include "CircleInSquare.h"
#include "Circle.h"
#include "Position.h"
int main() {
	setlocale(LC_ALL, "RUSSIAN");
	CircleInSquare a(5, 6, 10);
	std::cout << "Area of circle: " << a.area_circle() << std::endl;
	std::cout << "Length of circle: " << a.length_circle() << std::endl;
	std::cout << "Area of square: " << a.area_square() << std::endl;
	std::cout << "Length of square: " << a.length_square() << std::endl;
	a.print_coords();
	std::cout << std::endl;
	a.print_a();
	std::cout << std::endl;
	a.print_radius();
	std::cout << std::endl;
	a.set_coords(30, 30);
	a.print_coords();
}