#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    int val = gcd(abs(frac._numerator), abs(frac._denominator));
    frac._numerator /= val;
    frac._denominator /= val;

    if(frac._denominator < 0){
        frac._numerator = -frac._numerator;
        frac._denominator = -frac._denominator;
    }
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
    return false;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    return os;
}