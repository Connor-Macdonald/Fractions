//======================================
// Name: Connor Macodonald
// Student ID: 10170586
// Net ID: 14cm60
//======================================

#include "fractions_14cm60.h"


FractionException::FractionException(const string& message) : message(message) {}
string& FractionException::what() { return message; }


Fraction::Fraction() : Numerator(0), Denominator(1) {}

Fraction::Fraction(int n) : Numerator(n), Denominator(1) {}

Fraction::Fraction(int n, int d){
	if (d == 0) {
		throw FractionException("Cannot have a Denominator of: " + d);
		return;
	}
	else if ((n < 0 && d < 0) || (n > 0 && d > 0)) {
		Numerator = n;
		Denominator = d;
	}
	else {
		Numerator = -n;
		Denominator = -d;
	}
	reduce();
}

int Fraction::numerator() {
	return Numerator;
}

int Fraction::denominator() {
	return Denominator;
}

void Fraction::reduce(){
	int gcd = GCD(abs(Numerator), abs(Denominator));
	Numerator = Numerator / gcd;
	Denominator = Denominator / gcd;
}

int Fraction::GCD(int n, int m) {
	if (m == 0 || n == 0) // So does not try to mod 0
		return 1;
	else if (m <= n && n%m == 0)
		return m;
	else if (n < m)
		return GCD(m, n);
	else
		return GCD(m, n%m);
}

Fraction& Fraction::operator+=(const Fraction & right)
{
	if (Denominator == right.Denominator)
		Numerator += right.Numerator;
	else {
		Numerator = (Numerator * right.Denominator) + (right.Numerator * Denominator);
		Denominator *= right.Denominator;
	}
	reduce();
	return *this;
}

Fraction& Fraction::operator-()
{
	Numerator = -Numerator;
	return *this;
}

Fraction& Fraction::operator++()
{
	Numerator += Denominator;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction clone(Numerator, Denominator);
	Numerator += Denominator;
	return clone;
}

bool operator<(const Fraction & left, const Fraction & right)
{
	return (left.Numerator * (left.Denominator * right.Denominator)) < (right.Numerator * (left.Denominator * right.Denominator));
}

bool operator>(const Fraction & left, const Fraction & right)
{
	return (left.Numerator * (left.Denominator * right.Denominator)) > (right.Numerator * (left.Denominator * right.Denominator));
}

bool operator<=(const Fraction & left, const Fraction & right)
{
	return (left.Numerator * (left.Denominator * right.Denominator)) <= (right.Numerator * (left.Denominator * right.Denominator));
}

bool operator>=(const Fraction & left, const Fraction & right)
{
	return (left.Numerator * (left.Denominator * right.Denominator)) >= (right.Numerator * (left.Denominator * right.Denominator));
}

bool operator==(const Fraction & left, const Fraction & right)
{
	return (left.Numerator * (left.Denominator * right.Denominator)) == (right.Numerator * (left.Denominator * right.Denominator));
}

bool operator!=(const Fraction & left, const Fraction & right)
{
	return (left.Numerator * (left.Denominator * right.Denominator)) != (right.Numerator * (left.Denominator * right.Denominator));
}

Fraction operator+(const Fraction & left, const Fraction & right)
{
	int n, d;
	if (left.Denominator == right.Denominator)
		n = left.Numerator + right.Numerator;
	else {
		n = (left.Numerator * right.Denominator) + (right.Numerator * left.Denominator);
		d = left.Denominator * right.Denominator;
	}
	Fraction newF(n, d);
	newF.reduce();
	return newF;
}

Fraction operator-(const Fraction & left, const Fraction & right)
{
	int n, d;
	if (left.Denominator == right.Denominator)
		n = left.Numerator - right.Numerator;
	else {
		n = (left.Numerator * right.Denominator) - (right.Numerator * left.Denominator);
		d = left.Denominator * right.Denominator;
	}
	Fraction newF(n, d);
	newF.reduce();
	return newF;
}

Fraction operator*(const Fraction & left, const Fraction & right)
{
	Fraction newF(left.Numerator * right.Numerator, left.Denominator * right.Denominator);
	newF.reduce();
	return newF;
}

Fraction operator/(const Fraction & left, const Fraction & right)
{
	Fraction newF(left.Numerator * right.Denominator, left.Denominator * right.Numerator);
	newF.reduce();
	return newF;
}

ostream& operator<<(ostream & out, const Fraction & val)
{
	out << val.Numerator << "/" << val.Denominator;
	return out;
}

istream& operator>>(istream& in, Fraction& val)
{
	string input;
	in >> input;
	size_t pos = input.find("/");
	int n = 0;
	int d = 1;
	if (pos == std::string::npos) {
		n = stoi(input);
	}
	else {
		n = stoi(input.substr(0, pos));
		d = stoi(input.substr(pos + 1));
	}
	Fraction newF(n, d); // Construct to check 0 denominator
	val = newF;
	val.reduce();

	return in;
}
