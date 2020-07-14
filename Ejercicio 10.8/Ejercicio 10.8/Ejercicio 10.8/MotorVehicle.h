#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H
#include <iostream>
#include<sstream>
#include <string>
using namespace std;

class MotorVehicle
{
	friend ostream& operator << (ostream& output, const MotorVehicle& p);
protected:
	string Make;
	string FuelType;
	string Color;
	int YearOfManufacture;
	int EngineCapacity;
public:
	MotorVehicle(const string m, const string f, const string c, const int y, const int e)
	{
		Make = m;
		FuelType = f;
		Color = c;
		YearOfManufacture = y;
		EngineCapacity = e;
	}
	const string getMake() const
	{
		return Make;
	}
	const string getFuelType() const
	{
		return FuelType;
	}
	const string getColor() const
	{
		return Color;
	}
	const int getYearOfManufacture() const
	{
		return YearOfManufacture;
	}
	const int getEngineCapacity() const
	{
		return EngineCapacity;
	}

//Sobrecarga de Operadores
	// A)
	bool operator ==(const MotorVehicle& p)const ;

	// b)
	bool operator !=(const MotorVehicle& p)const;

	// C)
	bool operator > (const MotorVehicle& p)const;

};
#endif