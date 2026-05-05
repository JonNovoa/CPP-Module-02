#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointValue(0)
{
}

Fixed::Fixed(int const n) : fixedPointValue(n * (1 << fractionalBits))
{
}

Fixed::Fixed(float const f) : fixedPointValue(roundf(f * (1 << fractionalBits)))
{
}

Fixed::Fixed(Fixed const & other) : fixedPointValue(other.fixedPointValue)
{
}

Fixed& Fixed::operator=(Fixed const & other)
{
	if (this != &other)
		this->fixedPointValue = other.fixedPointValue;
	return (*this);
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

int Fixed::toInt(void) const
{
	return (this->fixedPointValue / (1 << fractionalBits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (1 << fractionalBits));
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->fixedPointValue > other.fixedPointValue);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->fixedPointValue < other.fixedPointValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->fixedPointValue >= other.fixedPointValue);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->fixedPointValue <= other.fixedPointValue);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->fixedPointValue == other.fixedPointValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->fixedPointValue != other.fixedPointValue);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->fixedPointValue + other.fixedPointValue);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->fixedPointValue - other.fixedPointValue);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long long temp = (long long)this->fixedPointValue * (long long)other.fixedPointValue;
	result.setRawBits((int)(temp / (1 << fractionalBits)));
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long long temp = ((long long)this->fixedPointValue << fractionalBits) / (long long)other.fixedPointValue;
	result.setRawBits((int)temp);
	return (result);
}

Fixed& Fixed::operator++(void)
{
	this->fixedPointValue += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixedPointValue += 1;
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	this->fixedPointValue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixedPointValue -= 1;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& out, Fixed const & fixed)
{
	out << fixed.toFloat();
	return (out);
}