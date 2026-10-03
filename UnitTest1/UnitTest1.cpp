#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB1.6/Lorry.h"
#include "../LAB1.6/Lorry.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(LorryCarNestedTests)
    {
    public:
        TEST_METHOD(TestNestedCarInitValid)
        {
            Lorry::Car car;
            bool result = car.Init("Toyota", 4, 150.0);
            Assert::IsTrue(result);
            Assert::AreEqual(std::string("Toyota"), car.GetBrand());
            Assert::AreEqual(4, car.GetCylinders());
            Assert::AreEqual(150.0, car.GetPower());
        }

        TEST_METHOD(TestNestedCarInvalidPower)
        {
            Lorry::Car car;
            bool result = car.Init("Toyota", 4, -50.0);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestNestedCarReassignBrand)
        {
            Lorry::Car car;
            car.Init("Ford", 6, 200.0);
            Assert::IsTrue(car.ReassignBrand("Ford Mustang"));
            Assert::AreEqual(std::string("Ford Mustang"), car.GetBrand());
        }

        TEST_METHOD(TestLorryInitValid)
        {
            Lorry lorry;
            bool result = lorry.Init("MAN", 6, 400.0, 18.5);
            Assert::IsTrue(result);
            Assert::AreEqual(std::string("MAN"), lorry.GetCar().GetBrand());
            Assert::AreEqual(18.5, lorry.GetCapacity());
        }

        TEST_METHOD(TestLorryInvalidCapacity)
        {
            Lorry lorry;
            bool result = lorry.Init("MAN", 6, 400.0, -5.0);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestLorryChangeCapacity)
        {
            Lorry lorry;
            lorry.Init("DAF", 6, 420.0, 20.0);
            Assert::IsTrue(lorry.ChangeCapacity(25.0));
            Assert::AreEqual(25.0, lorry.GetCapacity());
            Assert::IsFalse(lorry.ChangeCapacity(-1.0));
        }
    };
}
