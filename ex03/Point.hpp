#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	Point(void);
	Point(float const x, float const y);
	Point(Point const & other);
	Point& operator=(Point const & other);
	~Point(void);

	Fixed getX(void) const;
	Fixed getY(void) const;
};

#endif