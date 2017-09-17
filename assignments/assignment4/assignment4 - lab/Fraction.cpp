#include "Fraction.h"

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
   return out << f.num() << '/' << f.den() ;
}
bool operator==(Fraction& lhs, Fraction& rhs)
{
    return ((lhs.num() * rhs.den()) == (rhs.num() * lhs.den()));
}
bool operator<(const Fraction& lhs, const Fraction& rhs)
{
    return (lhs.num() * rhs.den() < rhs.num() * lhs.den());
}
bool operator>(const Fraction& lhs, const Fraction& rhs)
{
    return (lhs.num() * rhs.den() > rhs.num() * lhs.den());
}
Fraction operator*(Fraction lhs, const Fraction& rhs)
{
    return lhs *= rhs;
}