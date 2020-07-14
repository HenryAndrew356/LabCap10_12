#include "MotorVehicle.h"

int main()
{
	MotorVehicle a("Hyundai", "Aceite A", "Blanco", 2018, 500);
	MotorVehicle b("Daewoo", "Aceite B", "Blanco", 2013, 50);
	MotorVehicle c("Mitsubishi", "Aceite C", "Blanco", 2014, 5);
	MotorVehicle d("Honda", "Aceite", "Blanco D", 2015, 5000);
	cout << endl;
	cout << "Caracteristicas de vehiculo a: " << endl;
	cout << a << endl;
	cout << endl << endl;
	cout << "Caracteristicas de vehiculo b: " << endl;
	cout << b << endl;
	cout << endl << endl;
	cout << "Caracteristicas de vehiculo c: " << endl;
	cout << c << endl;
	cout << endl << endl;
	cout << "Caracteristicas de vehiculo d: " << endl;
	cout << d << endl;
	cout << endl;
	cout << "¿Es el vehiculo a igual que el b? 1=SI, 2=NO -->" << (a == b) << endl;
	cout << "¿Es el vehiculo a diferente al b? 1=SI, 2=NO -->" << (a != b) << endl;
	cout << "¿Es el vehiculo a mayor que el b? 1=SI, 2=NO -->" << (a > b) << endl;
}