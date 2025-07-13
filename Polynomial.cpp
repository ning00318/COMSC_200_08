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
    Polynomial order;
    order.coefficients = coefficients;
    order.exponents = exponents;
    bool ifFirstTerm = true;

    // Comment 4: Find out the constant value first and print it out.
    //            If there is no constant value as the first term, continue.
    for (int i = 0; i < order.exponents.size(); i++)
    {
        if (order.exponents[i] == 0 && order.coefficients[i] != 0)
        {
            printTerm(order.coefficients[i], order.exponents[i], ifFirstTerm);
            ifFirstTerm = false;
            order.exponents[i] = -1;    // Comment 5: Set it to -1 to indicate that this exponent has been taken.
            break;
        }
    }

    bool ifDone = false;
    int count = 0;

    // Comment 6: After checking if there is a constant value and printing
    //            it out if exists, output the remaining terms that their
    //            exponents are at least 1, and whose coeffients are not 0.
    while (ifDone == false)
    {
        int maxExponentIndex = findMaxExponentIndex(order.exponents);
        
        // Comment 7: Checking if the maximum value of exponent index is -1 first, means
        //            all exponents were taken, then end of loop, otherwise, continue.
        if (maxExponentIndex == -1)
        {
            ifDone = true;
            break;
        }
        
        if (order.coefficients[maxExponentIndex] != 0)
        {
            printTerm(order.coefficients[maxExponentIndex], order.exponents[maxExponentIndex], ifFirstTerm);
            ifFirstTerm = false;
        }
        else
        {
            // Comment 8: Adding a count when there is a term equal to 0, if
            //            all the terms are zero, print out 0 and end of loop.
            count++;
            if (order.coefficients.size() == count)
            {
                cout << "0";
                ifDone = true;
            }
        }

        // Comment 9: Remember to assign the current max exponent to -1 to prevent from printing out the same result again.
        order.exponents[maxExponentIndex] = -1;
    }
    cout << endl;
}

int Polynomial::findMaxExponentIndex(const std::vector<int>& exponents) const
{
    int maxExponent = -1;
    int maxExponentIndex = -1;
    for (int i = 0; i < exponents.size(); i++)
    {
        // Comment 10: If exponent > maxExponent, then assign current exponent to the maxExponent and store its index.
        if (exponents[i] > maxExponent)
        {
            maxExponent = exponents[i];
            maxExponentIndex = i;
        }
    }

    // Comment 11: After finding out the max exponent, return its index
    return maxExponentIndex;
}

void Polynomial::printTerm(int coefficient, int exponent, bool ifFirstTerm) const
{
    // Comment 12: If the printed term is not the first term, check if it's a positive or negative value and output respectively.
    if (ifFirstTerm == false)
        cout << ((coefficient >= 0) ? "+" : "-");
    else if (coefficient < 0)   // Comment 13: Or if the printed term is the first term (means there is no
        cout << "-";            //             constant value), output "-" when its coefficient is less than 0.

    if (coefficient != 0)
    {
        // Comment 14: This is for the constant values, and we are printing out their absolute values
        //             because we have already checked if they are positive or negative coefficients.
        if (exponent == 0)
            cout << abs(coefficient);
        else
        {
            cout << abs(coefficient) << "x";
            if (exponent != 1)
                cout << "^" << exponent;
        }
    }
}

Polynomial Polynomial::operator+(const Polynomial& poly2) const
{
    Polynomial result;  // Create a new Polynomial object
    result.coefficients = coefficients;
    result.exponents = exponents;
    int resultSize = result.coefficients.size();
    int poly2Size = poly2.coefficients.size();

    for (int i = 0; i < poly2Size; i++)
    {
        bool ifFound = false;
        for (int j = 0; j < resultSize; j++)
        {
            // Comment 15: If both terms' exponents are the same, add their coefficients together then store and update the result.
            if (poly2.exponents[i] == result.exponents[j])
            {
                result.coefficients[j] += poly2.coefficients[i];
                ifFound = true;
            }
        }

        // Comment 16: Otherwise, the remaining terms of the other Polynomial will be stored in the result individually.
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
            if (poly2.exponents[i] == result.exponents[j])
            {
                result.coefficients[j] -= poly2.coefficients[i];
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

Polynomial &Polynomial::operator=(const Polynomial& poly2)
{
    int resultSize = coefficients.size();
    int poly2Size = poly2.coefficients.size();

    for (int i = 0; i < poly2Size; i++)
    {
        bool ifFound = false;
        for (int j = 0; j < resultSize; j++)
        {
            if (poly2.exponents[i] == exponents[j])
            {
                coefficients[j] = poly2.coefficients[i];
                ifFound = true;
            }
        }
        if (ifFound == false)
        {
            coefficients.push_back(poly2.coefficients[i]);
            exponents.push_back(poly2.exponents[i]);
        }
    }
    return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial& poly2)
{
    int resultSize = coefficients.size();
    int poly2Size = poly2.coefficients.size();

    for (int i = 0; i < poly2Size; i++)
    {
        bool ifFound = false;
        for (int j = 0; j < resultSize; j++)
        {
            if (poly2.exponents[i] == exponents[j])
            {
                coefficients[j] += poly2.coefficients[i];
                ifFound = true;
            }
        }
        if (ifFound == false)
        {
            coefficients.push_back(poly2.coefficients[i]);
            exponents.push_back(poly2.exponents[i]);
        }
    }
    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial& poly2)
{
    int resultSize = coefficients.size();
    int poly2Size = poly2.coefficients.size();

    for (int i = 0; i < poly2Size; i++)
    {
        bool ifFound = false;
        for (int j = 0; j < resultSize; j++)
        {
            if (poly2.exponents[i] == exponents[j])
            {
                coefficients[j] -= poly2.coefficients[i];
                ifFound = true;
            }
        }
        if (ifFound == false)
        {
            coefficients.push_back(poly2.coefficients[i]);
            exponents.push_back(poly2.exponents[i]);
        }
    }
    return *this;
}