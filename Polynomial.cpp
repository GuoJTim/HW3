#ifndef Poly_CPP
#define Poly_CPP
#include "ChainIterator.h"
#include "CircularList.h"
#include "Polynomial.h"

bool comp(Term a, Term b) {
	return a.exp < b.exp;
}



std::ostream& operator<<(std::ostream& os, Polynomial& p) {
	os << generatePolyFormat(p);
	return os;
}


std::istream& operator>>(std::istream& is, Polynomial* poly) {
	Term temp;
	float coef;
	int exp;
	is >> coef >> exp;
	poly->poly.InsertSort(new ChainNode<Term>(temp.Set(coef, exp)),&comp);

	return is;
}

Polynomial::Polynomial() {
	//sentinel is in the circular list
	poly = CircularList<Term>();
}
Polynomial Polynomial::operator+(Polynomial& b) {
	Term temp;
	CircularList<Term>::ChainIterator ai = poly.begin(), bi = b.poly.begin();
	Polynomial c;
	while (ai != poly.end() && bi != b.poly.end()) {
		if (ai->exp == bi->exp) {
			float sum = ai->coef + bi->coef;
			if (sum) c.poly.InsertTail(temp.Set(sum, ai->exp));
			ai++;
			bi++;
		}
		else if (ai->exp < bi->exp) {
			c.poly.InsertTail(temp.Set(bi->coef, bi->exp));
			bi++;
		}
		else {
			c.poly.InsertTail(temp.Set(ai->coef, ai->exp));
			ai++;
		}
	}
	while (ai != poly.end()) {
		c.poly.InsertTail(temp.Set(ai->coef, ai->exp));
		ai++;
	}
	while (bi != b.poly.end()) {
		c.poly.InsertTail(temp.Set(bi->coef, bi->exp));
		bi++;
	}
	return c;
}

Polynomial Polynomial::operator-(Polynomial& b) {
	Term temp;
	CircularList<Term>::ChainIterator ai = poly.begin(), bi = b.poly.begin();
	Polynomial c;
	while (ai != poly.end() && bi != b.poly.end()) {
		if (ai->exp == bi->exp) {
			float sum = ai->coef - bi->coef;
			if (sum) c.poly.InsertTail(temp.Set(sum, ai->exp));
			ai++;
			bi++;
		}
		else if (ai->exp < bi->exp) {
			c.poly.InsertTail(temp.Set(-1 * bi->coef, bi->exp));
			bi++;
		}
		else {
			c.poly.InsertTail(temp.Set(ai->coef, ai->exp));
			ai++;
		}
	}
	while (ai != poly.end()) {
		c.poly.InsertTail(temp.Set(ai->coef, ai->exp));
		ai++;
	}
	while (bi != b.poly.end()) {
		c.poly.InsertTail(temp.Set(-1 * bi->coef, bi->exp));
		bi++;
	}
	return c;
}
Polynomial Polynomial::operator*(Polynomial& b) {
	Term temp;
	CircularList<Term>::ChainIterator ai, bi;
	Polynomial c;
	std::map<int, float> tempTermArray; //map find logn same as binary search
	// exp -> coef and which is sorted
	for (ai = poly.begin(); ai != poly.end(); ai++) {
		for (bi = b.poly.begin(); bi != b.poly.end(); bi++) {
			int exp = ai->exp + bi->exp;
			float coef = ai->coef * bi->coef;
			if (tempTermArray.find(exp) == tempTermArray.end()) {
				tempTermArray[exp] = coef;
			}
			else tempTermArray[exp] += coef;
		}
	}
	for (std::map<int, float>::reverse_iterator it = tempTermArray.rbegin(); it != tempTermArray.rend(); it++) {
		c.poly.InsertTail(temp.Set(it->second, it->first));
	}

	return c;
}
/*
pointer
*/

Polynomial* Polynomial::operator+(Polynomial* b) {
	Term temp;
	CircularList<Term>::ChainIterator ai = poly.begin(), bi = b->poly.begin();
	Polynomial *c = new Polynomial();
	while (ai != poly.end() && bi != b->poly.end()) {
		if (ai->exp == bi->exp) {
			float sum = ai->coef + bi->coef;
			if (sum) c->poly.InsertTail(temp.Set(sum, ai->exp));
			ai++;
			bi++;
		}
		else if (ai->exp < bi->exp) {
			c->poly.InsertTail(temp.Set(bi->coef, bi->exp));
			bi++;
		}
		else {
			c->poly.InsertTail(temp.Set(ai->coef, ai->exp));
			ai++;
		}
	}
	while (ai != poly.end()) {
		c->poly.InsertTail(temp.Set(ai->coef, ai->exp));
		ai++;
	}
	while (bi != b->poly.end()) {
		c->poly.InsertTail(temp.Set(bi->coef, bi->exp));
		bi++;
	}
	return c;
}

Polynomial* Polynomial::operator-(Polynomial* b) {
	Term temp;
	CircularList<Term>::ChainIterator ai = poly.begin(), bi = b->poly.begin();
	Polynomial *c = new Polynomial();
	while (ai != poly.end() && bi != b->poly.end()) {
		if (ai->exp == bi->exp) {
			float sum = ai->coef - bi->coef;
			if (sum) c->poly.InsertTail(temp.Set(sum, ai->exp));
			ai++;
			bi++;
		}
		else if (ai->exp < bi->exp) {
			c->poly.InsertTail(temp.Set(-1 * bi->coef, bi->exp));
			bi++;
		}
		else {
			c->poly.InsertTail(temp.Set(ai->coef, ai->exp));
			ai++;
		}
	}
	while (ai != poly.end()) {
		c->poly.InsertTail(temp.Set(ai->coef, ai->exp));
		ai++;
	}
	while (bi != b->poly.end()) {
		c->poly.InsertTail(temp.Set(-1 * bi->coef, bi->exp));
		bi++;
	}
	return c;
}
Polynomial* Polynomial::operator*(Polynomial* b) {
	Term temp;
	CircularList<Term>::ChainIterator ai, bi;
	Polynomial *c = new Polynomial();
	std::map<int, float> tempTermArray; //map find logn same as binary search
	// exp -> coef and which is sorted
	for (ai = poly.begin(); ai != poly.end(); ai++) {
		for (bi = b->poly.begin(); bi != b->poly.end(); bi++) {
			int exp = ai->exp + bi->exp;
			float coef = ai->coef * bi->coef;
			if (tempTermArray.find(exp) == tempTermArray.end()) {
				tempTermArray[exp] = coef;
			}
			else tempTermArray[exp] += coef;
		}
	}
	for (std::map<int, float>::reverse_iterator it = tempTermArray.rbegin(); it != tempTermArray.rend(); it++) {
		c->poly.InsertTail(temp.Set(it->second, it->first));
	}

	return c;
}

/*
*/




Polynomial Polynomial::operator=(const Polynomial& b) {
	//do copy
	Polynomial np;
	np.poly = CircularList<Term>(b.poly);
	return np;
}

float Polynomial::Evaluate(float f) {
	float result = 0.0;
	for (CircularList<Term>::ChainIterator it = poly.begin(); it != poly.end(); it++) {
		result += it->coef * pow(f, it->exp);
	}
	return result;
}

Polynomial::~Polynomial() {
	
}



Polynomial* generateFromString(std::string s) {
	//x^n...+1
	Polynomial *result = new Polynomial();//new 
	Term tempTerm;
	std::string temp = "";
	float coef = 0;
	int exp = 0;
	bool nextMinus = false;
	for (int i = 0; i < s.length(); i++) {
		if (isspace(s[i])) continue;
		if (s[i] == 'x') {
			if (i < s.length() && s[i + 1] != '^') {
				exp = 1;
				continue;
			}
			else i++; // change to next char ^
			std::string temp_exp;
			bool minus = false;
			if (s[i + 1] == '-') {
				minus = true;
				i++;
			}
			while (i < s.length() && s[i + 1] != '+' && s[i + 1] != '-') {
				i++;
				temp_exp += s[i];
			}
			exp = stoi(temp_exp);
			if (minus) exp *= -1;
		}
		else if (s[i] == '+' || s[i] == '-') {
			if (!temp.empty())coef = stof(temp);
			else if (exp != 0) coef = 1;
			temp.clear();

			result->poly.InsertSort(new ChainNode<Term>(tempTerm.Set(coef * (nextMinus ? -1 : 1), exp)),&comp);

			coef = 0;
			exp = 0;
			if (s[i] == '-') nextMinus = true;
			else nextMinus = false;
		}
		else temp += s[i];
	}
	if (!temp.empty()) coef = stof(temp);
	else if (exp != 0) coef = 1;

	if (coef != 0) {
		result->poly.InsertSort(new ChainNode<Term>(tempTerm.Set(coef * (nextMinus ? -1 : 1), exp)), &comp);
	}
	return result;
}

std::string generatePolyFormat(Polynomial& poly) {
	std::string s;
	for (CircularList<Term>::ChainIterator it = poly.poly.begin(); it != poly.poly.end(); it++) {
		std::stringstream ss;
		std::string coef, exp;
		ss << it->coef; ss >> coef;
		ss.clear();
		ss << it->exp; ss >> exp;
		if (it != poly.poly.begin() && it->coef > 0) s += "+";
		if (it->coef == -1 && it->exp != 0) s += "-";
		s += ((it->coef == 1 || it->coef == -1) && it->exp != 0 ? "" : coef) + (it->exp != 0 ? (it->exp == 1 ? "x" : "x^" + exp) : "");
	}
	return s;
}

#endif