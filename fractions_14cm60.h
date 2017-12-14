//======================================
// Name: Connor Macodonald
// Student ID: 10170586
// Net ID: 14cm60
//======================================


#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FractionException { // Exception thrown when a invalid fraction is entered ie. denominator of zero
public:
	FractionException(const string& message);
	string& what();

private:
	string message;
};


class Fraction // Fraction Class
{
public:
	Fraction();									// Default Constructor
	Fraction(int);							// Integer Constructor, entered int is numeratorand ennominator is 1
	Fraction(int, int);					// Full fraction constructor

	int numerator();						// Returns Numerator
	int denominator();					// Return Denominator


	void reduce();																// Reduces fraction using GCD. Called after all functions that return a fraction
	int GCD(int n, int m);												// GCD of two numbers
	Fraction& operator+=(const Fraction& right);  // Increment by value operator overloading
	Fraction& operator-();												// Negation overloading
	Fraction& operator++();												//Pre Increment
	Fraction operator++(int); 										//Post Increment


private:
	int Numerator;				// Numerator of fraction
	int Denominator;			// Denominator of fraction

// All below overloading done using freind functions

// All Boolean operator overloading
 friend bool operator<(const Fraction& left, const Fraction& right);
 friend bool operator>(const Fraction& left, const Fraction& right);
 friend bool operator<=(const Fraction& left, const Fraction& right);
 friend bool operator>=(const Fraction& left, const Fraction& right);
 friend bool operator==(const Fraction& left, const Fraction& right);
 friend bool operator!=(const Fraction& left, const Fraction& right);

 friend Fraction operator+(const Fraction& left, const Fraction& right); // Addition overloading
 friend Fraction operator-(const Fraction& left, const Fraction& right); // Subtration
 friend Fraction operator*(const Fraction& left, const Fraction& right); // Multiplication
 friend Fraction operator/(const Fraction& left, const Fraction& right); // Division

 friend ostream& operator<<(ostream& out, const Fraction& val); 	//  cout << overloading
 friend istream& operator>>(istream& in, Fraction& val);					//	cin >> overloading

};
