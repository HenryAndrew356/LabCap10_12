#include <cctype> // isdigit function prototype
#include "HugeInteger.h" // HugeInteger class definition
using namespace std;

/*
// default constructor; conversion constructor that converts
// a long integer into a HugeInteger object
// Constructor que convierte un entero en un objeto HugeInteger
*/
HugeInteger::HugeInteger(long value)
{
	// place digits of argument into array
	for (int j{ digits - 1 }; value != 0 && j >= 0; j--)
	{
		integer[j] = value % 10;
		value /= 10;
	}
}
/*
//	Conversion constructor that converts a character string
//	-->	Constructor de conversion que convierte una cadena de caracteres.
//	Representing a large integer into a HugeInteger object
//	-->	Representando un entero grande en un objeto HugeInteger
*/
HugeInteger::HugeInteger(const string & number)
{		// place digits of argument into array
	int length {(int) number.size()};
	for (int j{ digits - length}, k{ 0 }; j < digits; ++j, ++k)
	{
		if (isdigit(number[k])) // ensure that character is a digit
								// Asegurando que el caracter sea un dígito
		{
			integer[j] = number[k] - '0';
		}
	}
}

// SOBRECARGA DE OPERADORES DE SUMA
	
	//	HugeInteger + HugeInteger

HugeInteger HugeInteger::operator+(const HugeInteger& op2) const
{
	HugeInteger temp; // temporary result	
	int carry = 0;
	for (int i{ digits - 1 }; i >= 0; i--)
	{	
		temp.integer[i] = integer[i] + op2.integer[i] + carry;
		// determine whether to carry a 1
		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10; // reduce to 0-9
			carry = 1;
		}
		else // no carry
		{
			carry = 0;
		}
	}
	return temp; // return copy of temporary object
}

	// HugeInteger + int
HugeInteger HugeInteger::operator+(int op2) const
{
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this + HugeInteger(op2);
}

	// HugeInteger + string that represents large integer value
HugeInteger HugeInteger::operator+(const string& op2) const
{
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this + HugeInteger(op2);
}



//a) DESCRIBA CON PRECISION COMO FUNCIONA
//		-La clase HugeInteger permite l
//
//
//b) Restriciones de la clase


//c)SOBRECARGA DEL OPERADOR --> MULTIPLICACIÓN

HugeInteger HugeInteger::operator*(const HugeInteger& op2) const
{
	HugeInteger temp; // temporary result
	HugeInteger temp1;
	int carry = 0;
	int u = 1;
	for (int i{ digits - 1 }; i >= 0; i--)
	{
		for (int u{ digits - 1 }; u >= 0; u--) 
		{
			temp1.integer[u] = integer[u] * op2.integer[i] + carry;
			if (temp1.integer[u] > 9)
			{
				carry = temp1.integer[u] / 10;
				temp1.integer[u] %= 10; // reduce to 0-9	
			}
		}
		temp1 = temp1 * u;
		temp =temp+ temp1 ;
		u *= 10;
	}
	return temp; // return copy of temporary object
}

// HugeInteger + int
HugeInteger HugeInteger::operator*(int op2) const
{
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this * (HugeInteger(op2));
}

// HugeInteger + string that represents large integer value
HugeInteger HugeInteger::operator*(const string& op2) const
{
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this * (HugeInteger(op2));
}




//-------------------------------------------



/*
//	Overloaded output operator
//	      Sobrecarga del operador de salida/salida estandar
*/
ostream& operator<<(ostream& output, const HugeInteger& num)
{
	int i;
	// skip leading zeros
	for (i = 0; (i < HugeInteger::digits) && (0 == num.integer[i]); ++i)
	{}
	if (i == HugeInteger::digits)
	{
		output << 0;
	}
	else
	{
		for (; i < HugeInteger::digits; ++i)
		{
			output << num.integer[i];
		}
	}
	return output;
}