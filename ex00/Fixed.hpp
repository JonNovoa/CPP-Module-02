#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixedPointValue;
	static const int fractionalBits = 8;

public:
	Fixed(void);
	Fixed(Fixed const & other);
	Fixed& operator=(Fixed const & other);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif