#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		//Almacena el valor con punto fijo
		int	fixedPointValue;
		//número de bits fraccionarios, Se inicializa a 8, lo que significa 2^8 = 256
		static const int	fractionalBits = 8;

	public:
		// Constructor por defecto
		// Inicializa fixedPointValue a 0 (representa 0.0)
		Fixed(void);
		// Comportamiento: convierte el int a punto fijo (n * 256)
		Fixed(int const n);
		// Comportamiento: convierte el float a punto fijo (f * 256), redondeando
		Fixed(float const f);
		// Constructor copia
		// Parámetro: other (Fixed const &) - objeto Fixed a copiar
		// Comportamiento: copia el valor fixedPointValue de other
		Fixed(Fixed const & other);
		// Operador asignación copia
		// Parámetro: other (Fixed const &) - objeto Fixed a asignar
		// Retorna: referencia a este objeto (*this)
		// Comportamiento: copia el valor de other a este objeto
		Fixed& operator=(Fixed const & other);
		~Fixed(void);
		// Función miembro: convierte a int
		// Retorna: int - el valor como entero (sin parte decimal)
		// Comportamiento: divide fixedPointValue por 256
		int toInt(void) const;
		// Función miembro: convierte a float
		// Comportamiento: divide fixedPointValue por 256.0f
		float toFloat(void)const;
};
// Función amiga (no es miembro de la clase)
// Sobrecarga del operador << para imprimir Fixed
// Parámetro: out (std::ostream &) - stream de salida
// Parámetro: fixed (Fixed const &) - objeto Fixed a imprimir
// Retorna: std::ostream & - el stream (para encadenar operaciones)
// Comportamiento: imprime la representación en float del Fixed
// Ejemplo: std::cout << Fixed(42.42f); imprime "42.4219"
std::ostream& operator<<(std::ostream& out, Fixed const & fixed);







#endif