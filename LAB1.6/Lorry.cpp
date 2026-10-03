#include "Lorry.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string  Lorry::Car::GetBrand() const {
	return brand;
}
int Lorry::Car::GetCylinders() const {
	return cylinders;
}
double  Lorry::Car::GetPower() const {
	return power;
}

bool  Lorry::Car::SetBrand(string value) {
	if (!value.empty()) {
		brand = value;
		return true;
	}
	else {
		cout << "Не вказано бренд" << endl;
		return false;
	}
}
bool  Lorry::Car::SetCylinders(int value) {
	if (value > 0) {
		cylinders = value;
		return true;
	}
	else {
		return false;
	}
}
bool  Lorry::Car::SetPower(double value) {
	if (value > 0) {
		power = value;
		return true;
	}
	else {
		return false;
	}
}

bool  Lorry::Car::Init(string brand, int cylinders, double power) {
	return SetBrand(brand) && SetCylinders(cylinders) && SetPower(power);
}
void  Lorry::Car::Display() const {
	cout << "Машина = " << toString() << endl;
}
void  Lorry::Car::Read() {
	string newBrand;
	int newCylinders;
	double newPower;
	do {
		cout << "Введіть марку машини:             " << endl;
		cin >> newBrand;
		cout << "Введіть цількість цилідрів машини:" << endl;
		cin >> newCylinders;
		cout << "Введіть потужність машини:        " << endl;
		cin >> newPower;
	} while (!Init(newBrand, newCylinders, newPower));
}
string  Lorry::Car::toString() const {
	stringstream sout;
	sout << "(Марка: " << brand << ", Циліндри: " << cylinders << ", Потужність: " << power << ")";
	return sout.str();
}

bool  Lorry::Car::ChangePower(double newPower) {
	return SetPower(newPower);
}
bool  Lorry::Car::ReassignBrand(string newBrand) {
	return SetBrand(newBrand);
}

Lorry::Car Lorry::GetCar() const {
	return car;
}
double  Lorry::GetCapacity() const {
	return capacity;
}
bool  Lorry::SetCar(Car value) {
	car = value;
	return true;
}
bool  Lorry::SetCapacity(double value) {
	if (value > 0) {
		capacity = value;
		return true;
	}
	else {
		cout << "Помилкове значення" << endl;
		return false;
	}
}

bool Lorry::Init(string brand, int cylinders, double power, double capacity) {
	Car tempCar;
	if (tempCar.Init(brand, cylinders, power) && SetCapacity(capacity)) {
		car = tempCar;
		return true;
	}
	return false;
}
void  Lorry::Read() {
	cout << "Введіть дані машини:" << endl;
	car.Read();

	double newCapacity;
	do {
		cout << "Введіть вантажопідйомність (тонн): ";
		cin >> newCapacity;
	} while (!SetCapacity(newCapacity));
}
void  Lorry::Display() const {
	cout << toString() << endl;
}
string  Lorry::toString() const {
	stringstream sout;
	sout << "Вантажівка: " << car.toString() << ", Вантажопідйомність: " << capacity << " т";
	return sout.str();
}

bool  Lorry::ReassignBrand(string newBrand) {
	return car.SetBrand(newBrand);
}
bool  Lorry::ChangeCapacity(double newCapacity) {
	return SetCapacity(newCapacity);
}
