#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <string>
#include <vector>

class Polynomial
{
public:
    Polynomial();
    ~Polynomial();
    void enterTerms();
    void printPolynomial() const;

    // Comment: Overload the addition and subtraction operators will create a new Polynomial object
    //          and return the results (by value), which means that both objects' values will not be changed (const).
    Polynomial operator+(const Polynomial&) const;
    Polynomial operator-(const Polynomial&) const; 
/*
    // Comment: Overload =, +=, and -= operators do not create a new Polynomial object but modify the value of the current object based on another one
    //          and return the new value to the current object (by reference), which means that the calling object's value will change but another one's remain unchanged.
    Polynomial &operator=(const Polynomial&);
    Polynomial &operator+=(const Polynomial&);
    Polynomial &operator-=(const Polynomial&);
*/
private:
    std::vector<int> coefficients;
    std::vector<int> exponents;
};

#endif