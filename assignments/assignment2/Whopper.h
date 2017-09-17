#ifndef WHOPPER_H
#define WHOPPER_H
#include <iostream>
#include <vector>
using namespace std;

class Whopper
{
   private:
   vector<int> v;
   int sign;
   
   public:
   Whopper();
   Whopper operator>>(string word);
   Whopper operator<<(string word);
   friend bool operator==(Whopper &A, Whopper &B);
   friend bool operator>(Whopper &A, Whopper &B);
   Whopper operator+(Whopper &);
   Whopper operator-(Whopper &);
   Whopper operator*(Whopper &);
   vector<int> storevector(vector<int> total,long x);
};
#endif















