#include <iostream>
#include "bsp.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);

	std::cout << "=== Triangle: A(0,0) B(10,30) C(20,0) ===" << std::endl;

	Point p1(10, 15);
	std::cout << "Point (10, 15): " << (bsp(a, b, c, p1) ? "INSIDE" : "OUTSIDE") << std::endl;

	Point p2(10, 0);
	std::cout << "Point (10, 0) (edge): " << (bsp(a, b, c, p2) ? "INSIDE" : "OUTSIDE") << std::endl;

	Point p3(0, 0);
	std::cout << "Point (0, 0) (vertex): " << (bsp(a, b, c, p3) ? "INSIDE" : "OUTSIDE") << std::endl;

	Point p4(10, 30);
	std::cout << "Point (10, 30) (vertex): " << (bsp(a, b, c, p4) ? "INSIDE" : "OUTSIDE") << std::endl;

	Point p5(5, 10);
	std::cout << "Point (5, 10): " << (bsp(a, b, c, p5) ? "INSIDE" : "OUTSIDE") << std::endl;

	Point p6(15, 5);
	std::cout << "Point (15, 5): " << (bsp(a, b, c, p6) ? "INSIDE" : "OUTSIDE") << std::endl;

	Point p7(10, -5);
	std::cout << "Point (10, -5): " << (bsp(a, b, c, p7) ? "INSIDE" : "OUTSIDE") << std::endl;

	return (0);
}