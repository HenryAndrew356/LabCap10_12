#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <array>
#include <iostream>
#include <string>
#include <math.h>

class HugeInteger 
{
	friend std::ostream& operator<<(std::ostream&, const HugeInteger&);
public:
	static const int digits{ 40 }; // maximum digits in a HugeInteger
	HugeInteger(unsigned long int = 0); // conversion/default constructor
	HugeInteger(const std::string&); // conversion constructor

//SOBRECARGA DEL OPERADOR --> ADICION/SUMA

	// addition operator; HugeInteger + HugeInteger
	HugeInteger operator+(const HugeInteger&) const;

	// addition operator; HugeInteger + int
	HugeInteger operator+(int) const;

	// addition operator;
	// HugeInteger + string that represents large integer value
	HugeInteger operator+(const std::string&) const;


//SOBRECARGA DEL OPERADOR --> MULTIPLICACIÓN
	HugeInteger operator*(const HugeInteger&) const;
	HugeInteger operator*(int) const;
	HugeInteger operator*(const std::string&) const;

//SOBRECARGA DEL OPERADOR --> DIVISIÓN
	HugeInteger operator/(const HugeInteger&) const;
	HugeInteger operator/(int) const;
	HugeInteger operator/(const std::string&) const;

//SOBRECARGA DEL OPERADOR --> IGUALDAD
	bool operator==(const HugeInteger&) const;
	bool operator==(int) const;
	bool operator==(const std::string&) const;

private:
	std::array<short, digits> integer{}; // default init to 0s
};

#endif