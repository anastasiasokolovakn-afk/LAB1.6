#pragma once
#include <string>

using namespace std;

class Lorry
{
public:
	class Car {
	private: 
		string brand = "";
		int cylinders = 0;
		double power = 0.0;
	public:
		string GetBrand() const;
		int GetCylinders() const;
		double GetPower() const;

		bool SetBrand(string value);
		bool SetCylinders(int value);
		bool SetPower(double value);

		bool Init(string brand, int cylinders, double power);
		void Display() const;
		void Read();
		string toString() const;

		bool ChangePower(double newPower);
		bool ReassignBrand(string newBrand);
	};
private:
	Car car;         
	double capacity;
public:
	Car GetCar() const;
	double GetCapacity() const;
	bool SetCar(Car value);
	bool SetCapacity(double value);

	bool Init(string brand, int cylinders, double power, double capacity);
	void Read();
	void Display() const;
	string toString() const;

	bool ReassignBrand(string newBrand);
	bool ChangeCapacity(double newCapacity);

};

