#include <iostream>
#include "lab13.h"

Rational::Rational() : num(1), denum(1) {}


Rational::Rational(int num, int denum) : num(num), denum(denum) {
	normalize();
}

int Rational::get_num() const { return num;}

int Rational::get_denum() const { return denum; }

void Rational::set_num(int num) { this->num = num; Rational::normalize(); }

void Rational::set_denum(int denum) { this->denum = denum; Rational::normalize(); }

void Rational::normalize() {

	if (denum == 0) {

		std::cout << "Error, you tried to divide by zero!\n";
		exit(1);
	}
	
	int gcd = find_gcd(abs(num), abs(denum));
	num /= gcd;
	denum /= gcd;

	if (denum < 0) {
		num = -num;
		denum = -denum;
	}
}



int Rational::find_gcd(int a, int b) const {

	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;

}

Rational Rational::operator+(const Rational& other) const {

	return Rational(num * other.denum + other.num * denum, denum * other.denum);
}

Rational& Rational::operator+=(const Rational& other) {

	num = num * other.denum + other.num * denum;

	denum *= other.denum;
	normalize();

	return *this;
}

Rational Rational::operator-(const Rational& other) const{

	return Rational(num * other.denum - other.num * denum, denum * other.denum);
}

Rational Rational::operator-=(const Rational& other) {

	num = num * other.denum - other.num * denum;

	denum *= other.denum;
	normalize();

	return *this;
}

Rational& Rational::operator=(const Rational& other) {

	if (this != &other) {
		num = other.num;
		denum = other.denum;
	}
	return *this;
}

bool Rational::operator==(const Rational& other) const {

	return num == other.num && denum == other.denum;
}

bool Rational::operator!=(const Rational& other) const {
	
	return !(*this == other);
}

bool Rational::operator>(const Rational& other) const {

	return num * other.denum > other.num * denum;
}

bool Rational::operator<(const Rational& other) const {

	return num * other.denum < other.num * denum;
}

bool Rational::operator>=(const Rational& other) const {

	return !(*this < other);
}

bool Rational::operator<=(const Rational& other) const {

	return !(*this > other);
}

Rational Rational::operator*(const Rational& other) const {

	return Rational(num * other.num, denum * other.denum);
}

Rational& Rational::operator*=(const Rational& other) {
	
	num *= other.num;
	denum *= other.denum;
	normalize();
	return *this;
}

Rational Rational::operator/(const Rational& other) const {

	if (other.num == 0) {
		std::cout << "Error, you tried to divide by zero\n";
		exit(1);
	}

	return Rational(num * other.denum, denum * other.num);
}

Rational& Rational:: operator/=(const Rational& other) {

	if (other.num == 0) {
		std::cout << "Error, you tried to divide by zero\n";
		exit(1);
	}

	num *= other.denum;
	denum *= other.num;
	normalize();
	return *this;
}

 std::ostream& operator<<(std::ostream& os, const Rational& rational) {

	 int int_part = rational.num / rational.denum;
	 int remainder = rational.num % rational.denum;

	 if (int_part != 0) {

		 os << int_part;
	 }

	 if (remainder != 0) {
		 os << "." << remainder << "/" << rational.denum;
	 }

	 return os;
}

std::istream& operator>>(std::istream is, Rational& rational) {

	char slash;
	is >> rational.num >> slash >> rational.denum;

	if (rational.denum == 0) {
		std::cout << "Error you tried to divide by zero\n";
		exit(1);
	}

	rational.normalize();
	return is;
}

int Rational::get_integer_part() const {

	return num / denum;
}