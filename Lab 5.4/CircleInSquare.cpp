#include "CircleInSquare.h"

CircleInSquare::CircleInSquare()
{
}
// наследование
CircleInSquare::CircleInSquare(int x, int y, int a) : Square(x, y, a), Circle(x, y, a / 2),Position(x, y)
{
}

CircleInSquare::~CircleInSquare()
{
}
