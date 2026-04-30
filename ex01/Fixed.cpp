#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
// Comportamiento: convierte el int a punto fijo (n * 256)
Fixed::Fixed(int const n) : fixedPointValue(n * (1 << fractionalBits))
{
	std::cout << "Int constructor called" << std::endl;
}
// Comportamiento: convierte el float a punto fijo (f * 256), redondeando
Fixed::Fixed(float const f) : fixedPointValue(round(f * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & other) : fixedPointValue(other.fixedPointValue)
{
		std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const & other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->fixedPointValue = other.fixedPointValue;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
	return (this->fixedPointValue / (1 << fractionalBits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (1 << fractionalBits));
}

std::ostream& operator<<(std::ostream& out, Fixed const & fixed)
{
	out << fixed.toFloat();
	return out;
}