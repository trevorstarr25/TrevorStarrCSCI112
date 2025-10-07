#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    if(denominator == 0){
        cout << "Enter numerator: ";
        cin >> _numerator;
        do {
            cout << "Enter denominator: ";
            cin >> _denominator;
            if(_denominator == 0)
                cout << "Denominator cannot be 0." << endl;
        } while(_denominator == 0);
    } else {
        _numerator = numerator;
        _denominator = denominator;
    }

    simplify();
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    Fraction result(
        _numerator * frac._denominator + frac._numerator * _denominator,
        _denominator * frac._denominator
    );
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    Fraction result(
        _numerator * frac._denominator - frac._numerator * _denominator,
        _denominator * frac._denominator
    );
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    Fraction result(
        _numerator * frac._numerator,
        _denominator * frac._denominator
    );
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    Fraction result(
        _numerator * frac._denominator,
        _denominator * frac._numerator
    );
    if(result._denominator == 0){
        cout << "Error: division by 0" << endl;
        result._denominator = 1;
    }
    result.simplify();
    return result;
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    int val = gcd(abs(frac._numerator), abs(frac._denominator));
    if(val != 0){
        frac._numerator /= val;
        frac._denominator /= val;
    }

    if(frac._denominator < 0){
        frac._numerator = -frac._numerator;
        frac._denominator = -frac._denominator;
    }

    return frac;
}

void fractions::Fraction::simplify()
{
    *this = simplify(*this);
}

int fractions::Fraction::gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    Fraction f1 = simplify(*this);
    Fraction f2 = simplify(frac);
    return f1._numerator == f2._numerator && f1._denominator == f2._denominator;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    os << frac._numerator << "/" << frac._denominator;
    return os;
}