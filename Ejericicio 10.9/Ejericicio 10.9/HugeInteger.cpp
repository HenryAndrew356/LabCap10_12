#include <cctype> // isdigit function prototype
#include "HugeInteger.h" // HugeInteger class definition
using namespace std;

/*
// default constructor; conversion constructor that converts
// a long integer into a HugeInteger object
// Constructor que convierte un entero en un objeto HugeInteger
*/
HugeInteger::HugeInteger(unsigned long int  value)
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



// A)DESCRIBA CON PRECISION COMO FUNCIONA

// -La clase HugeInteger permite expresar valores con el rango de 40 caracteres.
// -Para lograr eso utiliza un arreglo de datos de tipo short.
// -Desglosa cada caracter y no asigna a un dato empezando por el ultimo en el arreglo.
// -Para realizar operaciones matemáticas se implementan funciones de sobrecarga con una
//  logica interna las cuales permiten tener los resultados requeridos.

// B) Restriciones de la clase:

// -No se pueden expresar valores mayores a 40 caracteres.
// -No se pueden expresar valores con decimales.

// C)SOBRECARGA DEL OPERADOR --> MULTIPLICACIÓN
/*  Intento pero no se logro.
HugeInteger HugeInteger::operator*(const HugeInteger& op2) const
{
	HugeInteger temp; // temporary result
	HugeInteger temp1;
	int carry = 0;
	int u = 1;
	int n = 0;
	for (int i{ digits - 1 }; i >= 39; i--)
	{
		for (int y{ digits - n }; y < 40; y++)
		{
			if (!y == digits)
			{
				temp1.integer[y] = 0;
			}
		}
		for (int u{ digits - 1 }; u >= 0; u--) 
		{
			temp1.integer[u-n] = (integer[u] * op2.integer[i]) + carry;
			if (temp1.integer[u] > 9)
			{
				carry = temp1.integer[u-n] / 10;
				temp1.integer[u-n] %= 10;	
			}
			else
			{
				carry = 0;
			}
		}
		temp = (temp + temp1);
		n++;
	}
	return temp;
}
*/



HugeInteger HugeInteger::operator*(const HugeInteger& op2) const
{
	int k = 0;
	for (int i{ 0 }; i < 40; i++)
	{
		if (integer[i] > 0)
		{
			k = i;
			break;
		}
	}
	unsigned long int Integer = 0;
	unsigned long int b = 0;
	for (int u{ digits - 1 }; u >= k; u--)
	{
		b = integer[u] * pow(10, digits - 1 - u);
		Integer += b;
	}
	cout << Integer << endl;
	int h = 0;
	for (int i{ 0 }; i < 40; i++)
	{
		if (op2.integer[i] > 0)
		{	
			h = i;
			break;
		}
	}
	unsigned long int IntegerOP2 = 0;
	unsigned long int c = 0;
	for (int j{ digits - 1 }; j >= h; j--)
	{
		c = op2.integer[j] * pow(10, digits - 1 - j);
		IntegerOP2 += c;
	}
	cout << IntegerOP2 << endl;
	unsigned long int Final = Integer * IntegerOP2;
	cout << Final << endl;
	HugeInteger temp(Final);
	return temp; // return copy of temporary object
}


// HugeInteger + int
HugeInteger HugeInteger::operator*(int op2) const
{
	return *this * (HugeInteger(op2));
}

// HugeInteger + string that represents large integer value
HugeInteger HugeInteger::operator*(const string& op2) const
{
	return *this * (HugeInteger(op2));
}


//  D)SOBRECARGA DEL OPERADOR --> DIVISION


HugeInteger HugeInteger::operator/(const HugeInteger& op2) const
{
	int k = 0;
	for (int i{ 0 }; i < 40; i++)
	{
		if (integer[i] > 0)
		{
			k = i;
			break;
		}
	}
	long Integer = 0;
	long b = 0;
	for (int u{ digits - 1 }; u >= k; u--)
	{
		b = integer[u] * pow(10, digits - 1 - u);
		Integer += b;
	}
	int h = 0;
	for (int i{ 0 }; i < 40; i++)
	{
		if (op2.integer[i] > 0)
		{
			h = i;
			break;
		}
	}
	long IntegerOP2 = 0;
	long c = 0;
	for (int j{ digits - 1 }; j >= h; j--)
	{
		c = op2.integer[j] * pow(10, digits - 1 - j );
		IntegerOP2 += c;
	}
	long Final = Integer / IntegerOP2;
	HugeInteger temp(Final);
	return temp; // return copy of temporary object
}



// HugeInteger + int
HugeInteger HugeInteger::operator/(int op2) const
{
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this / (HugeInteger(op2));
}

// HugeInteger + string that represents large integer value
HugeInteger HugeInteger::operator/(const string& op2) const
{
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this / (HugeInteger(op2));
}



//  E)SOBRECARGA DEL OPERADOR --> IGUALDAD

bool HugeInteger::operator==(const HugeInteger& op2) const
{
	bool a;
	for (int i{ digits - 1 }; i >= 0; i--)
	{
		if (op2.integer[i] == integer[i])
		{
			a=true;
		}
		if (op2.integer[i] != integer[i])
		{
			a = false;
			break;
		}
	}
	return a;
}



// HugeInteger + int
bool HugeInteger::operator==(int op2) const
{
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this == (HugeInteger(op2));
}

// HugeInteger + string that represents large integer value
bool HugeInteger::operator==(const string& op2) const
{
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this == (HugeInteger(op2));
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