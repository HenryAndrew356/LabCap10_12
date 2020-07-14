#include <iostream>
#include "HugeInteger.h"
using namespace std;
int main() {
	HugeInteger n0{ 25 };
	HugeInteger n1{ 7654321 }; // Aplicacion de HugeInteger(long = 0);
	HugeInteger n2{ 84492408 }; // Aplicacion de HugeInteger(long = 0);
	HugeInteger n3{ "99999999999999999999999999999" }; // Aplicacion de HugeInteger(const std::string&);
	HugeInteger n4{ "1" };// Aplicacion de HugeInteger(const std::string&);
	HugeInteger n5; // Aplicacion de HugeInteger(long = 0);
	cout << "n1 is " << n1 << "\nn2 is " << n2 << "\nn3 is " << n3 << "\nn4 is " << n4 << "\nn5 is " << n5 << "\n\n";
	n5 = n1 + n2;// Aplicacion de HugeInteger operator+(const HugeInteger&) const;
	cout << n1 << " + " << n2 << " = " << n5 << "\n\n"; // Aplicacion de | ostream& operator<<(std::ostream&, const HugeInteger&);
	cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";//Aplica sobrecarga de operador de salida y Adicion entre HugeInteger
	n5 = n1 + 9; // Aplicacion de HugeInteger operator+(int) const;
	cout << n1 << " + " << 9 << " = " << n5 << "\n\n"; // Aplica sobrec de operad. de salida
	n5 = n2 + "10000"; //Aplicacion de HugeInteger operator+(const std::string&) const;
	cout << n2 << " + " << "10000" << " = " << n5 <<"\n";
	cout <<"La multiplicacion de n2=" << n2 << " * n0=" << n0 << " es " << (n2 * n0) << endl;
	cout <<"La division de n2="<<n2 << " / n0="<<n0<<" es " <<(n2 / n0) << endl;
	cout <<"Es n0 Igual que n1 1=SI , 0=NO -->"<< (n0 == n1)<<"<--" << endl;
}