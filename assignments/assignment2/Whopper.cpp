#include "Whopper.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

Whopper::Whopper()
: sign(0)
{
    
}
Whopper Whopper::operator>>(string word)
{
    vector<int> a;
    vector<int> b;
    for(unsigned int i = 0; i < word.size(); i++)
    {
        if(i == 0)
        {
            sign = word.at(i);
            if(sign == 45)
            {
                i++;
                sign = -1;
            }
        }
        else
        {
            a.push_back(word.at(i));
        }
    }
    if(sign == 49) // = 1
    {
        sign = 1;
    }
    else if(sign == 48) // = 0
    {
        sign = 0;
    }
    for(unsigned int i = 0; i < a.size(); i++)
    {
        if(a.at(i) == 48)
        {
            a.at(i) = 0;
        }
        if(a.at(i) == 49)
        {
            a.at(i) = 1;
        }
        if(a.at(i) == 50)
        {
            a.at(i) = 2;
        }
        if(a.at(i) == 51)
        {
            a.at(i) = 3;
        }
        if(a.at(i) == 52)
        {
            a.at(i) = 4;
        }
        if(a.at(i) == 53)
        {
            a.at(i) = 5;
        }
        if(a.at(i) == 54)
        {
            a.at(i) = 6;
        }
        if(a.at(i) == 55)
        {
            a.at(i) = 7;
        }
        if(a.at(i) == 56)
        {
            a.at(i) = 8;
        }
        if(a.at(i) == 57)
        {
            a.at(i) = 9;
        }
    }
    vector<int> reverse;
    for(int i = a.size() - 1; i >= 0; i--)
    {
        reverse.push_back(a.at(i));
    }
    int checked = 0;
    for(int i = reverse.size() - 1; i >= 0; i--)
    {
        if((reverse.at(i) == 0) && (checked == 0))
        {
            reverse.pop_back();
        }
        else if(reverse.at(i) > 0)
        {
            checked++;
        }
    }
    vector<int> back;
    for(int i = reverse.size() - 1; i >= 0; i--)
    {
        back.push_back(reverse.at(i));
    }
    a = back;
    int o = a.size();
    for(int i = a.size() - 1; i >= 0; i--)
    {
       if((o % 2) == 0)
       {
          if(i != 0)
          {
              if((a.at(i) != 0) && (a.at(i - 1) != 0))
              {
                  b.push_back(a.at(i) + (a.at(i - 1) * 10));
                  i--;
              }
              else if((a.at(i - 1) != 0) && (a.at(i) == 0))
              {
                  b.push_back((a.at(i) + a.at(i - 1)) * 10);
                  i--;
              }
              else 
              {
                  b.push_back(a.at(i));
              }
          }
          else
          {
             b.push_back(a.at(i));
          }
       }
       else if(i > 0)
       {
          if((a.at(i) != 0) && (a.at(i - 1) != 0))
          {
              b.push_back(a.at(i) + (a.at(i - 1) * 10));
              i--;
          }
          else if((a.at(i - 1) != 0) && (a.at(i) == 0))
          {
              b.push_back((a.at(i) + a.at(i - 1)) * 10);
              i--;
          }
          else if(i != 0)
          {
              b.push_back(a.at(i));
          }
       }
       else if(i == 0)
       {
           b.push_back(a.at(i));
       }
    }
    for(int i = b.size() - 1; i >= 0; i--)
    {
        v.push_back(b.at(i));
    }
    return *this;
}  
Whopper Whopper::operator<<(string word)
{
    cout << sign << ' ';
    if(sign == 0)
    {
        cout << 0 << endl;
        return *this;
    }
    vector<int> spilt;
    for(unsigned int i = 0; i < v.size(); i++)
    {
        spilt.push_back(v.at(i));
    }
    vector<int> spilta;
    int checkera = 0;
    for(unsigned int i = 0; i < spilt.size(); i++)
    {
         if(spilt.at(i) > 9)
        {
            int counter = 0;
            int b = spilt.at(i) % 10;
            int c = spilt.at(i) - b;
            while(c != 0)
            {
                c -= 10;
                counter++;
            }
            spilta.push_back(counter);
            spilta.push_back(b);
        }
        else
        {
            spilta.push_back(spilt.at(i));
        }
        checkera++;
    }
    string as = word;
    vector<int> reverse;
    if(checkera == 0)
    {
       for(int i = v.size() - 1; i >= 0; i--)
       {
          reverse.push_back(v.at(i));
       }
    }
    else
    {
       for(int i = spilta.size() - 1; i >= 0; i--)
       {
          reverse.push_back(spilta.at(i));
       }
    }
    int checked = 0;
    for(int i = reverse.size() - 1; i >= 0; i--)
    {
        if((reverse.at(i) == 0) && (checked == 0))
        {
            reverse.pop_back();
        }
        else if(reverse.at(i) > 0)
        {
            checked++;
        }
    }
    vector<int> back;
    for(int i = reverse.size() - 1; i >= 0; i--)
    {
        back.push_back(reverse.at(i));
    }
    if(back.size() % 2 == 0)
    {
        for(unsigned int i = 0; i < back.size(); i++)
        {
            cout << back.at(i) << back.at(i + 1) << ' ';
            i++;
        }
    }
    else
    {
        cout << back.at(0) << ' ';
        for(unsigned int i = 1; i < back.size(); i++)
        {
            cout << back.at(i) << back.at(i + 1) << ' ';
            i++;
        }
    }
    cout << endl;
    return *this;
}
bool operator==(Whopper &A, Whopper &B)
{
    if(A.sign == 1 && ((B.sign == 0) || (B.sign == -1)))
    {
        return false;
    }
    else if(A.sign == -1 && ((B.sign == 0) || (B.sign == 1)))
    {
        return false;
    }
    else if((A.sign == 0) && (B.sign == 1))
    {
        return false;
    }
    else if((A.sign == 0) && (B.sign == -1))
    {
        return true;
    }
    vector<int> a;
    for(unsigned int i = 0; i < A.v.size(); i++)
    {
        if(A.v.at(i) > 9)
        {
            int counter = 0;
            int b = A.v.at(i) % 10;
            int c = A.v.at(i) - b;
            while(c != 0)
            {
                c -= 10;
                counter++;
            }
            a.push_back(counter);
            a.push_back(b);
        }
        else
        {
            a.push_back(A.v.at(i));
        }
    }
    vector<int> d;
    for(unsigned int i = 0; i < B.v.size(); i++)
    {
        if(B.v.at(i) > 9)
        {
            int counter = 0;
            int b = B.v.at(i) % 10;
            int c = B.v.at(i) - b;
            while(c != 0)
            {
                c -= 10;
                counter++;
            }
            d.push_back(counter);
            d.push_back(b);
        }
        else
        {
            d.push_back(B.v.at(i));
        }
    }
    int size1 = a.size();
    int size2 = d.size();
    if((size1 > size2) || (size1 < size2))
    {
        return false;
    }
    else
    {
        for(unsigned int i = 0; i < a.size(); i++)
        {
            if(a.at(i) != d.at(i))
            {
                return false;
            }
        }
    }
    return true;
}
bool operator>(Whopper &A, Whopper &B)
{
    if(A.sign == 1 && ((B.sign == 0) || (B.sign == -1)))
    {
        return true;
    }
    else if(A.sign == -1 && ((B.sign == 0) || (B.sign == 1)))
    {
        return false;
    }
    else if(A.sign == 0 && (B.sign == 1))
    {
        return false;
    }
    else if(A.sign == 0 && (B.sign == -1))
    {
        return true;
    }
    vector<int> a;
    for(unsigned int i = 0; i < A.v.size(); i++)
    {
        if(A.v.at(i) > 9)
        {
            int counter = 0;
            int b = A.v.at(i) % 10;
            int c = A.v.at(i) - b;
            while(c != 0)
            {
                c -= 10;
                counter++;
            }
            a.push_back(counter);
            a.push_back(b);
        }
        else
        {
            a.push_back(A.v.at(i));
        }
    }
    vector<int> d;
    for(unsigned int i = 0; i < B.v.size(); i++)
    {
        if(B.v.at(i) > 9)
        {
            int counter = 0;
            int b = B.v.at(i) % 10;
            int c = B.v.at(i) - b;
            while(c != 0)
            {
                c -= 10;
                counter++;
            }
            d.push_back(counter);
            d.push_back(b);
        }
        else
        {
            d.push_back(B.v.at(i));
        }
    }
    int size1 = a.size();
    int size2 = d.size();
    if(size1 > size2)
    {
        return true;
    }
    else if(size1 < size2)
    {
        return false;
    }
    else
    {
        for(unsigned int i = 0; i < a.size(); i++)
        {
            if(a.at(i) > d.at(i))
            {
                return true;
            }
        }
    }
    return false;
}
Whopper Whopper::operator+(Whopper &B)
{
    Whopper C;
    if((this->sign == 0) && (B.sign == 0))
    {
        C.sign = 0;
        C.v.push_back(0);
        return C;
    }
    if((this->sign == 1) && (B.sign == 0))
    {
        C.sign = 1;
        C.v = this->v;
        return C;
    }
    if((this->sign == 0) && (B.sign == 1))
    {
        C.sign = 1;
        C.v = B.v;
        return C;
    }
    if((this->sign == 0) && (B.sign == -1))
    {
        C.sign = -1;
        C.v = B.v;
        return C;
    }
    if((this->sign == -1) && (B.sign == 0))
    {
        C.sign = -1;
        C.v = this->v;
        return C;
    }
    if(((this->sign == 1) && (B.sign == 1)) || ((this->sign == -1) && (B.sign == -1)))
    {
       if((this->sign == 1) && (B.sign == 1))
       {
           C.sign = 1;
       }
       else
       {
           C.sign = -1;
       }
       vector<int> y;
       for(unsigned int i = 0; i < this->v.size(); i++)
       {
            if(this->v.at(i) > 9)
            {
                int counter = 0;
                int b = this->v.at(i) % 10;
                int c = this->v.at(i) - b;
                while(c != 0)
                {
                    c -= 10;
                    counter++;
                }
                y.push_back(counter);
                y.push_back(b);
            }
            else
            {
                y.push_back(this->v.at(i));
            }
        }
        vector<int> p;
        for(unsigned int i = 0; i < B.v.size(); i++)
        {
            if(B.v.at(i) > 9)
            {
                int counter = 0;
                int b = B.v.at(i) % 10;
                int c = B.v.at(i) - b;
                while(c != 0)
                {
                    c -= 10;
                    counter++;
                }
                p.push_back(counter);
                p.push_back(b);
            }
            else
            {
                p.push_back(B.v.at(i));
            }
        }
       int a = y.size();
       int b = p.size();
       int c = 0;
       int d = 0;
       int e = 1;
       if(a > b)
       {
           while(p.size() != y.size())
           {
               p.insert(p.begin(),0);
           }
       }
       else if(a < b)
       {
           while(y.size() != p.size())
           {
               y.insert(y.begin(),0);
           }
       }
       for(int i = y.size() - 1; i >= 0; i--)
       {
           e = 0;
           c = (y.at(i) + p.at(i));
           d = c;
           if(c > 9)
           {
               d = c - 10;
               e = 1;
           }
           C.v.insert(C.v.begin(),d);
           if(i != 0) 
           {
              y.at(i - 1) = y.at(i - 1) + e;   
           }
           else if((i == 0) && (e == 1))
           {
               C.v.insert(C.v.begin(), e);
           }
       }
       return C;
    }
    if(((this->sign == 1) && (B.sign == -1)) || ((this->sign == -1) && (B.sign == 1)))
    {
        vector<int> g;
        vector<int> h;
       if((this->sign == 1) && (B.sign == -1))
       {
           B.sign = 1;
           if(*this == B)
           {
               C.sign = 0;
               C.v.push_back((0));
               return C;
           }
           else if(*this > B)
           {
                C.sign = 1;
                g = this->v;
                h = B.v;
           }
           else 
           {
               C.sign = -1;
               g = B.v;
               h = this->v;
           }
           B.sign = -1;
       }
       if((this->sign == -1) && (B.sign == 1))
       {
          this->sign = 1;
          if(*this == B)
          {
              C.sign = 0;
              C.v.push_back((0));
              return C;
          }
          else if(*this > B)
          {
               C.sign = -1;
               g = this->v;
               h = B.v;
          }
          else 
          {
              C.sign = 1;
              g = B.v;
              h = this->v;
          }
          this->sign = -1;
       }
       vector<int> l;
       for(unsigned int i = 0; i < g.size(); i++)
       {
          if(g.at(i) > 9)
          {
              int counter = 0;
              int b = g.at(i) % 10;
              int c = g.at(i) - b;
              while(c != 0)
              {
                  c -= 10;
                  counter++;
              }
              l.push_back(counter);
              l.push_back(b);
           }
           else
           {
              l.push_back(g.at(i));
           }
       }
       vector<int> k;
       for(unsigned int i = 0; i < h.size(); i++)
       {
           if(h.at(i) > 9)
           {
              int counter = 0;
              int b = h.at(i) % 10;
              int c = h.at(i) - b;
              while(c != 0)
              {
                  c -= 10;
                  counter++;
              }
              k.push_back(counter);
              k.push_back(b);
           }
           else
           {
              k.push_back(h.at(i));
           }
        }
        int a = l.size();
        int b = k.size();
        int c = 0;
        int d = 0;
        if(a > b)
        {
           while(k.size() != l.size())
           {
               k.insert(k.begin(),0);
           }
        }
        else if(a < b)
        {
           while(l.size() != k.size())
           {
               l.insert(l.begin(),0);
           }
        } 
       for(int i = l.size() - 1; i >= 0; i--)
       {
           if(l.at(i) < k.at(i))
           {
               l.at(i) += 10;
               if(i != 0)
               {
                  if(l.at(i - 1) != 0)
                  {
                      l.at(i - 1) -= 1;   
                  }
                  else 
                  {
                      if(l.at(i - 1) == 0)
                      {
                        int check = 0;
                        for(int j = i - 1; check == 0; j--)
                        {
                            if(l.at(j) == 0)
                            {
                                l.at(j) = 9;
                            }
                            if(l.at(j) > 0)
                            {
                                l.at(j) -= 1; 
                                check++;
                            }
                        } 
                      }
                  }
               }
           }
           c = (l.at(i) - k.at(i));
           d = c;
           C.v.insert(C.v.begin(),d);
         }
         return C;
    }
    return C;
}
Whopper Whopper::operator-(Whopper &B)
{
    vector<int> g;
    vector<int> h;
    Whopper C;
    if((this->sign == 0) && (B.sign == 0))
    {
        C.sign = 0;
        C.v.push_back(0);
        return C;
    }
    if((this->sign == 1) && (B.sign == 0))
    {
        C.sign = 1;
        C.v = this->v;
        return C;
    }
    if((this->sign == 0) && (B.sign == 1))
    {
        C.sign = -1;
        C.v = B.v;
        return C;
    }
    if((this->sign == 0) && (B.sign == -1))
    {
        C.sign = 1;
        C.v = B.v;
        return C;
    }
    if((this->sign == -1) && (B.sign == 0))
    {
        C.sign = -1;
        C.v = this->v;
        return C;
    }
    
    if((this->sign == 1) && (B.sign == 1)) 
    {
        if(*this > B)
        {
            C.sign = 1;
            g = this->v;
            h = B.v;
        }
        else if(*this == B)
        {
            C.sign = 0;
            C.v.push_back(0);
            return C;
        }
        else
        {
            C.sign = -1;
            g = B.v;
            h = this->v;
        }
        vector<int> l;
        for(unsigned int i = 0; i < g.size(); i++)
        {
          if(g.at(i) > 9)
          {
              int counter = 0;
              int b = g.at(i) % 10;
              int c = g.at(i) - b;
              while(c != 0)
              {
                  c -= 10;
                  counter++;
              }
              l.push_back(counter);
              l.push_back(b);
           }
           else
           {
              l.push_back(g.at(i));
           }
        }
        vector<int> k;
        for(unsigned int i = 0; i < h.size(); i++)
        {
           if(h.at(i) > 9)
           {
              int counter = 0;
              int b = h.at(i) % 10;
              int c = h.at(i) - b;
              while(c != 0)
              {
                  c -= 10;
                  counter++;
              }
              k.push_back(counter);
              k.push_back(b);
           }
           else
           {
              k.push_back(h.at(i));
           }
        }
        int a = l.size();
        int b = k.size();
        int c = 0;
        int d = 0;
        if(a > b)
        {
           while(k.size() != l.size())
           {
               k.insert(k.begin(),0);
           }
        }
        else if(a < b)
        {
           while(l.size() != k.size())
           {
               l.insert(l.begin(),0);
           }
        } 
        for(int i = l.size() - 1; i >= 0; i--)
       {
           if(l.at(i) < k.at(i))
           {
               l.at(i) += 10;
               if(i != 0)
               {
                  if(l.at(i - 1) != 0)
                  {
                      l.at(i - 1) -= 1;   
                  }
                  else 
                  {
                      if(l.at(i - 1) == 0)
                      {
                        int check = 0;
                        for(int j = i - 1; check == 0; j--)
                        {
                            if(l.at(j) == 0)
                            {
                                l.at(j) = 9;
                            }
                            if(l.at(j) > 0)
                            {
                                l.at(j) -= 1; 
                                check++;
                            }
                        } 
                      }
                  }
               }
           }
           c = (l.at(i) - k.at(i));
           d = c;
           C.v.insert(C.v.begin(),d);
         }
         return C;
    }
    if((this->sign == -1) && (B.sign == -1))
    {
        this->sign = 1;
        B.sign = 1;
        if(*this > B)
        {
            C.sign = -1;
            g = this->v;
            h = B.v;
        }
        else if(*this == B)
        {
            C.sign =0;
            C.v.push_back(0);
            return C;
        }
        else
        {
            C.sign = 1;
            g = B.v;
            h = this->v;
        }
        vector<int> l;
        for(unsigned int i = 0; i < g.size(); i++)
        {
          if(g.at(i) > 9)
          {
              int counter = 0;
              int b = g.at(i) % 10;
              int c = g.at(i) - b;
              while(c != 0)
              {
                  c -= 10;
                  counter++;
              }
              l.push_back(counter);
              l.push_back(b);
           }
           else
           {
              l.push_back(g.at(i));
           }
        }
        vector<int> k;
        for(unsigned int i = 0; i < h.size(); i++)
        {
           if(h.at(i) > 9)
           {
              int counter = 0;
              int b = h.at(i) % 10;
              int c = h.at(i) - b;
              while(c != 0)
              {
                  c -= 10;
                  counter++;
              }
              k.push_back(counter);
              k.push_back(b);
           }
           else
           {
              k.push_back(h.at(i));
           }
        }
        int a = l.size();
        int b = k.size();
        int c = 0;
        int d = 0;
        if(a > b)
        {
           while(k.size() != l.size())
           {
               k.insert(k.begin(),0);
           }
        }
        else if(a < b)
        {
           while(l.size() != k.size())
           {
               l.insert(l.begin(),0);
           }
        } 
        for(int i = l.size() - 1; i >= 0; i--)
       {
           if(l.at(i) < k.at(i))
           {
               l.at(i) += 10;
               if(i != 0)
               {
                  if(l.at(i - 1) != 0)
                  {
                      l.at(i - 1) -= 1;   
                  }
                  else 
                  {
                      if(l.at(i - 1) == 0)
                      {
                        int check = 0;
                        for(int j = i - 1; check == 0; j--)
                        {
                            if(l.at(j) == 0)
                            {
                                l.at(j) = 9;
                            }
                            if(l.at(j) > 0)
                            {
                                l.at(j) -= 1; 
                                check++;
                            }
                        } 
                      }
                  }
               }
           }
           c = (l.at(i) - k.at(i));
           d = c;
           C.v.insert(C.v.begin(),d);
         }
         return C;
    }
    if((this->sign == 1) && (B.sign == -1)) 
    {
        B.sign = 1;
        C = *this + B;
        B.sign = -1;
        return C;
    }
    if((this->sign == -1) && (B.sign == 1))
    {
        B.sign = -1;
        C = *this + B;
        B.sign = 1;
        return C;
    }
    return C;
}
Whopper Whopper::operator*(Whopper &B)
{
    Whopper C;
    Whopper A;
    A.sign = 1;
    C.sign = 1;
    vector<int> total;
    if(B.sign == 0)
    {
        C.v.push_back(0);
        C.sign = 0;
        return C;
    }
    if(this->sign == 0)
    {
        C.v.push_back(0);
        C.sign = 0;
        return C;
    }
    if(((this->sign == 1) &&(B.sign == 1)) || ((this->sign == -1) && (B.sign == -1)))
    {
        C.sign = 1;
    }
    if(((this->sign == -1) && (B.sign == 1)) || ((this->sign == 1) && (B.sign == -1)))
    {
        C.sign = -1;
    }
    long iteration = 0;
    long x = 0;
    long z = 0;
    int countercheck = 0;
    vector<int> hold;
    for(int i = this->v.size() - 1; i >= 0; i--)
    {
        total.clear();
        for(int j = B.v.size() - 1; j >= 0; j--)
        {
          z = pow(100,iteration);
          x = (this->v.at(i) * B.v.at(j)) * z;
          total = storevector(total,x);
          iteration++;
        }
        if(countercheck != 0)
        {
            for(int i = 0; i < countercheck; i++)
            {
                total.push_back(0);
                total.push_back(0);
            }
        }
        countercheck++;
        A.v = total;
        C = C + A;
        iteration = 0;
    }
    return C;
}
vector<int> Whopper::storevector(vector<int> total,long x)
{
    Whopper A;
    Whopper B;
    Whopper C;
    string c;
    stringstream mystream;
    mystream << x;
    c = mystream.str();
    vector<int> a;
    for(unsigned int i = 0; i < c.size(); i++)
    {
        a.push_back(c.at(i));
    }
    for(unsigned int i = 0; i < a.size(); i++)
    {
        if(a.at(i) == 48)
        {
            a.at(i) = 0;
        }
        if(a.at(i) == 49)
        {
            a.at(i) = 1;
        }
        if(a.at(i) == 50)
        {
            a.at(i) = 2;
        }
        if(a.at(i) == 51)
        {
            a.at(i) = 3;
        }
        if(a.at(i) == 52)
        {
            a.at(i) = 4;
        }
        if(a.at(i) == 53)
        {
            a.at(i) = 5;
        }
        if(a.at(i) == 54)
        {
            a.at(i) = 6;
        }
        if(a.at(i) == 55)
        {
            a.at(i) = 7;
        }
        if(a.at(i) == 56)
        {
            a.at(i) = 8;
        }
        if(a.at(i) == 57)
        {
            a.at(i) = 9;
        }
    }
    A.v = a;
    A.sign = 1;
    B.v = total;
    if(B.v.empty())
    {
        B.sign = 0;
    }
    else
    {
        B.sign = 1;
    }
    C = A + B;
    total.clear();
    for(unsigned int i = 0; i < C.v.size(); i++)
    {
        total.push_back(C.v.at(i));
    }
    return total;
}










