#include <iostream>
using namespace std;

struct ComplexNumber
{
	double real;
	double imaginary;
};

ComplexNumber add(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	result.real = a.real + b.real;
	result.imaginary = a.imaginary + b.imaginary;
	return result;
}

ComplexNumber Subtract(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	result.real = a.real - b.real;
	result.imaginary = a.imaginary - b.imaginary;
	return result;
}

ComplexNumber Multiply(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	result.real = a.real * b.real - a.imaginary * b.imaginary;
	result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
	return result;
}

ComplexNumber Divide(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	double denominator = b.real * b.real + b.imaginary * b.imaginary;
	result.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
	result.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
	return result;
}

void display(ComplexNumber c) {
	cout << c.real << " + " << c.imaginary << "i" << endl;
}

int main() {
	cout << "PROGRAM: Complex Number Operations";

	ComplexNumber num1, num2, result;
	cout << "\nEnter real and imaginary parts of first complex number >>> ";
	cin >> num1.real >> num1.imaginary;
	cout << "Enter real and imaginary parts of second complex number >>> ";
	cin >> num2.real >> num2.imaginary;

	cout << "Enter the operation to perform!\n";
	cout << "1) Addition\n2) Subtraction\n3) Multiplication\n4) Division\n5) Exit\n";

	cout << "First Complex Number: ";
	display(num1);
	cout << "Second Complex Number: ";
	display(num2);

	cout << "Choice >>> ";
	int choice = 0;

	bool going_on = true;

	do {
		cout << "Choice >>> ";
		if (!(cin >> choice)) {
			cout << "Invalid input.\n";
			break;
		}

		switch (choice) {
		case 1:
			result = add(num1, num2);
			cout << "Addition: ";
			display(result);
			break;
		case 2:
			result = Subtract(num1, num2);
			cout << "Subtraction: ";
			display(result);
			break;
		case 3:
			result = Multiply(num1, num2);
			cout << "Multiplication: ";
			display(result);
			break;
		case 4: {
			double denominator = num2.real * num2.real + num2.imaginary * num2.imaginary;
			if (denominator == 0.0) {
				cout << "Error: Division by zero (second complex number has zero magnitude).\n";
			}
			else {
				result = Divide(num1, num2);
				cout << "Division: ";
				display(result);
			}
			break;
		}
		case 5:
			going_on = false;
			cout << "Exiting program.\n";
			break;
		default:
			cout << "Invalid choice.\n";
			break;
		}
	} while (going_on);
}
