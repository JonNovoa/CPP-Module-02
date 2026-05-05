#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(float const a, float const b) : x(a), y(b)
{
}

Point::Point(Point const & other) : x(other.getX()), y(other.getY())
{
}

Point& Point::operator=(Point const & other)
{
	(void)other;
	return (*this);
}

Point::~Point(void)
{
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}