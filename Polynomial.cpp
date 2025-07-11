#include <iostream>
#include <string>
#include <algorithm>
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

void Polynomial::printPolynomial() const
{   
    cout << "issue occur";
    /*
    Polynomial order;
    order.coefficients = coefficients;
    order.exponents = exponents;
    bool ifDone = false;
    while (ifDone == false)
    {
        int maxExponent = 0;
        int maxExponentIndex = 0;
        int count = 0;
        for (int i = 0; i < order.exponents.size(); i++)
        {
            if (order.exponents[i] > maxExponent)
            {
                maxExponent = order.exponents[i];
                maxExponentIndex = i;
            }
            else if (order.exponents[i] == 0)
            {
                cout << order.coefficients[i];
                order.exponents[i] = -1;
            }
            else if (order.exponents[i] == -1)
            {
                count++;
                if (count == order.exponents.size())
                    ifDone = true;
            }
        }
        if (order.exponents[maxExponentIndex] > 0)
        {
            if (order.coefficients[maxExponentIndex] > 0)
                cout << "+";
            else if (order.coefficients[maxExponentIndex] < 0)
                cout << "-";
            cout << order.coefficients[maxExponentIndex] << "x";

            if (order.exponents[maxExponentIndex] != 1)
                cout << "^" << order.exponents[maxExponentIndex];
            order.exponents[maxExponentIndex] = -1;
        }
    }
    cout << endl;
    */
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