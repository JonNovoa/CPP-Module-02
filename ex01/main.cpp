#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;

	Fixed const b(10);

	Fixed const c(42.42f);

	// Crea objeto d (copy constructor)
	// Copia el valor de b (2560)
	Fixed const d(b);

	a = Fixed(1234.4321f);

	// Imprime a usando el operador << sobrecargado
	// Llama a toFloat(): 316012 / 256.0f = 1234.425...
	// Pero se redondea a 1234.43 por precisión de float
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	// Imprime los valores como enteros usando toInt()
	// Descarta la parte decimal
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	// Aquí terminan todos los objetos:
	// - d sale de scope → destructor
	// - c sale de scope → destructor
	// - b sale de scope → destructor
	// - a sale de scope → destructor

}