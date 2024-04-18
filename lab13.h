#pragma once
#ifndef lab13_h
#define lab13_h

class Rational {

private:
	int num;
	int denum;

public:
	Rational();
	Rational(int num, int denum);
	void normalize();
	int get_num() const;
	int get_denum() const;
	void set_num(int num);
	void set_denum(int denum);
	Rational operator+(const Rational& other) const;
	Rational& operator+=(const Rational& other);
	Rational operator-(const Rational& other) const;
	Rational operator-=(const Rational& other);
	Rational& operator=(const Rational& other);
	bool operator==(const Rational& other) const;
	bool operator!=(const Rational& other) const;
	bool operator>(const Rational& other) const;
	bool operator<(const Rational& other) const;
	bool operator>=(const Rational& other) const;
	bool operator<=(const Rational& other) const;
	Rational operator*(const Rational& other) const;
	Rational& operator*=(const Rational& other);
	Rational operator/(const Rational& other) const;
	Rational& operator/=(const Rational& other);

	friend std::ostream& operator<<(std::ostream& os, const Rational& rational);
	friend std::istream& operator>>(std::istream is, Rational& rational);

	int get_integer_part() const;
private:
	int find_gcd(int a, int b) const;
};

#endif // lab13_h
