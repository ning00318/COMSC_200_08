#include <iostream>
#include <string>
#include "Polynomial.h"
using namespace std;

// Default constructor
Polynomial::Polynomial()
{
}

Polynomial::~Polynomial()
{
}

void Polynomial::set()
{
    
}

string Polynomial::get() const
{

}

void Polynomial::enterTerms()
{
    int terms, coefficient, exponent;
    cout << "Enter number of polynomial terms: ";
    cin >> terms;
    for (int i = 0; i < terms; i++)
    {
        cout << "\nEnter coefficient: ";
        cin >> coefficient;        
        cout << "Enter exponent: ";
        cin >> exponent;
        coefficients.push_back(coefficient);
        exponents.push_back(exponent);
    }
    cout << endl;
}

// FIXME
void Polynomial::printPolynomial() const
{
    // The last term will be printed out first.
    if (coefficients[coefficients.size() - 1] != 0)
    {
        cout << coefficients[coefficients.size() - 1];
        if (exponents[exponents.size() - 1] != 0)
        {
            cout << "x";
            if (exponents[exponents.size() - 1] > 1)
                cout << "^" << exponents[exponents.size() - 1];
        }
        cout << "+";
    }

    // Print out all the terms except the last term.
    for (int i = 0; i < coefficients.size() - 1; i++)
    {
        if (coefficients[i] != 0)
        {
            cout << coefficients[i];
            if (exponents[i] != 0)
            {
                cout << "x";
                if (exponents[i] > 1)
                    cout << "^" << exponents[i];
            }
        }
        else
            continue;
        if (i + 1 != coefficients.size() - 1)
            cout << "+";
    }    
}

Polynomial Polynomial::operator+(const Polynomial& poly2) const
{
    Polynomial result;
    result.coefficients = coefficients;
    result.exponents = exponents;
    int resultSize = result.coefficients.size();
    int poly2Size = poly2.coefficients.size();

    for (int i = 0; i < poly2Size; i++)
    {
        bool ifFound = false;
        for (int j = 0; j < resultSize; j++)
        {
            if (poly2.exponents[i] == result.exponents[j])  // if (0 == 0, 1, 2, ...)
            {
                result.coefficients[j] += poly2.coefficients[i];
                ifFound = true;
            }
        }
        if (ifFound == false)
        {
            result.coefficients.push_back(poly2.coefficients[i]);
            result.exponents.push_back(poly2.exponents[i]);
        }
    }
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& poly2) const
{

}

Polynomial &Polynomial::operator=(const Polynomial& poly2)
{

}

Polynomial &Polynomial::operator+=(const Polynomial& poly2)
{

}

Polynomial &Polynomial::operator-=(const Polynomial& poly2)
{

}