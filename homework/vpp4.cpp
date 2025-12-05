#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Car
{
	string color;
	string brand;
	string number;
};

Car* FillCarData()
{
	Car* car = new Car;
	cout << "Enter car color: ";
	getline(cin, car->color);
	cout << "Enter car brand: ";
	getline(cin, car->brand);
	cout << "Enter car number: ";
	getline(cin, car->number);
	return car;
}

void PrintCarData(const Car* car)
{
	cout << "Car Color: " << car->color << endl;
	cout << "Car Brand: " << car->brand << endl;
	cout << "Car Number: " << car->number << endl;
}

Car* EditCar(Car* car)
{
	cout << "Editing car data. Leave blank to keep current value." << endl;
	cout << "Current color: " << car->color << ". New color: ";
	string input;
	getline(cin, input);
	if (!input.empty()) car->color = input;
	cout << "Current brand: " << car->brand << ". New brand: ";
	getline(cin, input);
	if (!input.empty()) car->brand = input;
	cout << "Current number: " << car->number << ". New number: ";
	getline(cin, input);
	if (!input.empty()) car->number = input;
	return car;
}

void PrintAllCars(Car** cars, int count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << "Car " << (i + 1) << ":" << endl;
		PrintCarData(cars[i]);
	}
}

Car* FindCarByNumber(Car** cars, int count, const string& number)
{
	for (int i = 0; i < count; ++i)
	{
		if (cars[i]->number == number)
		{
			return cars[i];
		}
	}
	return nullptr;
}

int main()
{
    // --- Part 1: Test with a single car ---
    cout << "--- SINGLE CAR TEST ---" << endl;
    Car* singleCar = FillCarData();
    cout << "\nYou entered:\n";
    PrintCarData(singleCar);

    cout << "\nEditing the single car:\n";
    EditCar(singleCar);
    cout << "\nAfter editing:\n";
    PrintCarData(singleCar);

    delete singleCar;

    // --- Part 2: Array of 10 cars ---
    const int SIZE = 10;
    Car* carArray[SIZE];

    cout << "\n--- ARRAY OF 10 CARS ---" << endl;
    for (int i = 0; i < SIZE; ++i)
    {
        cout << "\nCar " << (i + 1) << ":" << endl;
        carArray[i] = FillCarData();
    }

    cout << "\nAll cars entered:\n";
    PrintAllCars(carArray, SIZE);

    cout << "\nEnter a car number to search: ";
    string searchNumber;
    getline(cin, searchNumber);

    Car* foundCar = FindCarByNumber(carArray, SIZE, searchNumber);
    if (foundCar)
    {
        cout << "\nCar found:\n";
        PrintCarData(foundCar);

        cout << "\nEditing found car:\n";
        EditCar(foundCar);
    }
    else
    {
        cout << "Car not found.\n";
    }

    cout << "\nAll cars after editing:\n";
    PrintAllCars(carArray, SIZE);

    for (int i = 0; i < SIZE; ++i)
    {
        delete carArray[i];
    }
}

