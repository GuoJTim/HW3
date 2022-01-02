#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "CircularList.cpp"
#include "ChainIterator.cpp"
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <sstream>

class Polynomial;


class Term {
	friend Polynomial;
	friend std::ostream& operator<<(std::ostream&, Polynomial&); // out stream
	friend std::istream& operator>>(std::istream&, Polynomial*); // input stream
	friend std::string generatePolyFormat(Polynomial&); // out string format
	friend Polynomial* generateFromString(std::string); // generate Polynomial
	friend std::string generatePolyFormat(Polynomial&); // 
	friend bool comp(Term, Term);
	friend std::string showAvailableList();

	Term Set(float coef, int exp) {
		this->coef = coef;
		this->exp = exp;
		return *this;
	}
private:
	float coef;
	int exp;
};


class Polynomial {
	friend std::ostream& operator<<(std::ostream&, Polynomial&); // out stream
	friend std::istream& operator>>(std::istream&, Polynomial*); // input stream
	friend Polynomial* generateFromString(std::string); // generate Polynomial
	friend std::string generatePolyFormat(Polynomial&); // 
private:
	CircularList<Term> poly;

public:
	Polynomial();
	~Polynomial();
	Polynomial operator+(Polynomial&);
	Polynomial operator-(Polynomial&);
	Polynomial operator*(Polynomial&);

	Polynomial* operator+(Polynomial*);
	Polynomial* operator-(Polynomial*);
	Polynomial* operator*(Polynomial*);

	Polynomial operator=(const Polynomial&);
	float Evaluate(float f);
};
Polynomial* generateFromString(std::string); // define
#endif