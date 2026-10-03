#include <iostream>
#include <Windows.h>
#include "Lorry.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "===========================================" << endl;
    cout << "  1. ДЕМОНСТРАЦIЯ ВКЛАДЕНОГО КЛАСУ Car" << endl;
    cout << "===========================================" << endl;

    Lorry::Car car1;
    car1.Init("Audi", 4, 190.0);
    cout << "Створено car1 через Init():" << endl;
    car1.Display();

    cout << "\nЗмiна параметрiв car1:" << endl;
    car1.ChangePower(220.5);
    car1.ReassignBrand("Audi RS");
    cout << "Оновлений car1: " << car1.toString() << endl;
    cout << "Окрема перевiрка гетера потужностi: " << car1.GetPower() << " к.с." << endl;

    cout << "\n--- Масив об'єктiв вкладеного класу Car ---" << endl;
    const int CAR_SIZE = 2;
    Lorry::Car carArray[CAR_SIZE];
    carArray[0].Init("BMW", 6, 250.0);
    carArray[1].Init("Mercedes", 4, 180.0);

    for (int i = 0; i < CAR_SIZE; i++)
    {
        cout << "Car [" << (i + 1) << "]: ";
        carArray[i].Display();
    }

    cout << "\n===========================================" << endl;
    cout << "  2. ДЕМОНСТРАЦIЯ КЛАСУ-КОНТЕЙНЕРА Lorry" << endl;
    cout << "===========================================" << endl;

    Lorry lorry1;
    lorry1.Init("Volvo", 6, 450.0, 20.0);
    cout << "Створено lorry1 через Init():" << endl;
    lorry1.Display();

    cout << "\nЗмiна марки та вантажопiдйомностi для lorry1:" << endl;
    lorry1.ReassignBrand("Scania");
    lorry1.ChangeCapacity(25.0);
    cout << "Оновлений lorry1 (виклик toString()): " << lorry1.toString() << endl;

    cout << "\nВведення даних для lorry2 через Read():" << endl;
    Lorry lorry2;
    lorry2.Read();
    cout << "\nВведений об'єкт lorry2:" << endl;
    lorry2.Display();

    cout << "\n===========================================" << endl;
    cout << "   МАСИВ ОБ'ЄКТIВ LORRY" << endl;
    cout << "===========================================" << endl;
    const int SIZE = 2;
    Lorry fleet[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "\n--- Заповнення вантажiвки #" << (i + 1) << " ---" << endl;
        fleet[i].Read();
    }

    cout << "\n--- Список усiх вантажiвок у автопарку ---" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "[" << (i + 1) << "] ";
        fleet[i].Display();
    }

    return 0;
}