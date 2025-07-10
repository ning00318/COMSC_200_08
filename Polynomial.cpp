#include <iostream>
#include <string>
#include "Polynomial.h"
using namespace std;

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

Polynomial Polynomial::operator+(const Polynomial&) const
{

}

Polynomial Polynomial::operator-(const Polynomial&) const
{

}

Polynomial &Polynomial::operator=(const Polynomial&)
{

}

Polynomial &Polynomial::operator+=(const Polynomial&)
{

}

Polynomial &Polynomial::operator-=(const Polynomial&)
{

}