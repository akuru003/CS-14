#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
class Fraction
{
    public:
    int gcd(int a, int b)
    {
       return b==0 ? a : gcd(b,a%b); 
    }
    int n, d;
    Fraction(int a, int b = 1) 
    : n(a), d(b)
    {}
    int num() const 
    {
       return n;
    }
    int den() const 
    {
       return d; 
    }
    Fraction& operator*=(const Fraction& rhs)
    {
        int new_n = n*rhs.n / gcd(n*rhs.n, d*rhs.d);
        d = d*rhs.d / gcd(n*rhs.n, d*rhs.d);
        n = new_n;
        return *this;
    }
    friend bool operator==(Fraction& lhs, Fraction& rhs);
};
#endif