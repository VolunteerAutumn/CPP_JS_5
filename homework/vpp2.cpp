#include <iostream>
using namespace std;

struct Car
{
	double length;
	double clearance;
	double fuel_capacity; // in liters
	double wheel_diameter;
	int gearbox_type; // 1 = mechanical, 0 = automatic
};

Car* SearchCarByParameters(
Car arr[],
int size,
double length,
double clearance,
double fuel_capacity,
double wheel_diameter,
int gearbox_type
)
{
	for (int i = 0; i < size; i++)
	{
		if (length != -1 && arr[i].length != length)
		{
			continue;
		}
		if (clearance != -1 && arr[i].clearance != clearance)
		{
			continue;
		}
		if (fuel_capacity != -1 && arr[i].fuel_capacity != fuel_capacity)
		{
			continue;
		}
		if (wheel_diameter != -1 && arr[i].wheel_diameter != wheel_diameter)
		{
			continue;
		}
		if (gearbox_type != -1 && arr[i].gearbox_type != gearbox_type)
		{
			continue;
		}
		return &arr[i];
	}

	return nullptr;
}

int main()
{
	Car cars[] = {
		{4.5, 0.2, 50.0, 0.6, 1},
		{4.2, 0.18, 45.0, 0.55, 0},
		{4.8, 0.22, 60.0, 0.65, 1},
	};

	int size = sizeof(cars) / sizeof(cars[0]);
	Car* foundCar = SearchCarByParameters(cars, size, 4.5, -1, -1, -1, -1);
	if (foundCar)
	{
		cout << "Car found: Length = " << foundCar->length
			 << ", Clearance = " << foundCar->clearance
			 << ", Fuel Capacity = " << foundCar->fuel_capacity
			 << ", Wheel Diameter = " << foundCar->wheel_diameter
			 << ", Gearbox Type = " << foundCar->gearbox_type << endl;
	}
	else
	{
		cout << "No car found with the specified parameters." << endl;
	}
}

