#include <iostream>
#include "lab13.h"

//дописать метод, который будет выделять целую часть от числа
int main() {

	Rational a(0, 0);
	Rational b(0, 1);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	Rational c = a + b;
	std::cout << "a + b: " << c << std::endl;

	Rational e = a - b;
	std::cout << "a - b: " << c << std::endl;

	c += a;
	std::cout << "c + a: " << c << std::endl;

	c -= e;
	std::cout << "c - e: " << c << std::endl;

	bool f = a == b;
	std::cout << "a == b: " << f << std::endl;

	bool g = a != b;
	std::cout << "a != b: " << g << std::endl;

	bool h = a > b;
	std::cout << "a > b: " << h << std::endl;

	bool j = a < b;
	std::cout << "a < b: " << j << std::endl;

	bool k = a >= b;
	std::cout << "a >= b: " << k << std::endl;

	bool l = a <= b;
	std::cout << "a <= b: " << l << std::endl;

	Rational d = a * b;
	std::cout << "a * b: " << d << std::endl;

	d /= b; 
	std::cout << "d /= b: " << d << std::endl;

	d *= b;
	std::cout << "d *= b: " << d << std::endl;

	Rational r = a / b;
	std::cout << "a / b: " << r << std::endl;

	Rational n(10, 1);
	std::cout << "Integer part of n is: " << n.get_integer_part() << std::endl;

	return 0;
}