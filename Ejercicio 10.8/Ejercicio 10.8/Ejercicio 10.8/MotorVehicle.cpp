#include "MotorVehicle.h"
// A)
bool MotorVehicle::operator ==(const MotorVehicle &p)const
{
	return (this->Make == p.Make) && (this->FuelType==p.FuelType) && (this->Color==p.Color) && (this->YearOfManufacture==p.YearOfManufacture) && (this->EngineCapacity == p.EngineCapacity);
}

// b)
bool MotorVehicle::operator !=(const MotorVehicle &p)const
{
	return (this->Make != p.Make) || (this->FuelType != p.FuelType) || (this->Color != p.Color) || (this->YearOfManufacture != p.YearOfManufacture) || (this->EngineCapacity != p.EngineCapacity);
}

// C)
bool MotorVehicle::operator > (const MotorVehicle& p)const
{
	bool a;
	if (this->YearOfManufacture < p.YearOfManufacture)
	{
		a = true;
	}
	else a = false;
	return a;
}

// D)
ostream& operator << (ostream& output, const MotorVehicle& p)
{
	output << "Make= " << p.Make << ", FuelType =" << p.FuelType ;
	output <<", Color ="<<p.Color << ", Year Of Mabufacture =" << p.YearOfManufacture << ", EngineCapacity =" << p.EngineCapacity;
	return output;
}