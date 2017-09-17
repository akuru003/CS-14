#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include "Bst.h"
#include "Fraction.h"
#include <vector>
using namespace std;

void sortInt(list<int> &temp, BinarySearchTree b)
{
     vector<int> val;
     b.print_inorder(val);
     temp.clear();
     for(unsigned int i = 0; i < val.size(); i++)
     {
         temp.push_back(val.at(i));
     }
}
void sortFraction(list<Fraction> &temp, BinarySearchTree b)
{
     vector<int> val;
     b.print_inorderFraction(val);
     temp.clear();
     for(unsigned int i = 0; i < val.size(); i++)
     {
         Fraction a(val[i],val[i + 1]);
         temp.push_back(a);
         i++;
     }
}
int main(int argc, char **argv)
{
   if(argc != 2)
   {
      cout << "ERROR: Invalid program call." << endl;
      return 1;
   }
   string input1(argv[1]);
   string temp = "";
   string temp2 = "";
   int counter = 0;
   temp2 = input1.at(counter);
   while(temp2 != ".")
   {  
       temp += temp2;
       counter++;
       temp2 = input1.at(counter);
   }
   string outputfile1 = temp + ".out";
   list<int> i;
   list<Fraction> f;
   char letter;
   string d = "";
   int number = 0;
   int number2 = 0;
   ifstream in(NULL);  
   ofstream out(NULL);
   in.open(input1.c_str());
   if(!in.is_open())
   {
      cout << "Error opening input file, ending program!" << endl;
      return 0;;
   }
   out.open(outputfile1.c_str());
   if(!out.is_open())
   {
      cout << "Error opening output file 1, ending program!" << endl;
      return 0;;
   }
   while(!in.eof())
   { 
       in >> letter;
       getline(in,d); 
       d.clear();
       getline(in,d); 
       istringstream line(d);
       if(letter == 'i')
       {
          while(line >> number)
          {
              i.push_back(number);
          }
       }
       else
       {
           while(line >> number >> number2)
          {
             Fraction a(number,number2);
             f.push_back(a);
          }
       }
       BinarySearchTree b;
       if(i.size() != 0)
       {
           list<int>::iterator it;
           for(it = i.begin(); it != i.end(); it++) 
           {
               b.insert(*it);
           }
       }
       else
       {
           list<Fraction>::iterator ft;
           for(ft = f.begin(); ft != f.end(); ft++) 
           {
               b.insertFraction(*ft);
           }
       }
       if(i.size() != 0)
       {
          sortInt(i,b);
       }
       else
       {
           sortFraction(f,b);
       }
       out << letter << endl;
       if(i.size() != 0)
       {
           list<int>::iterator it;
           for(it = i.begin(); it != i.end(); it++) 
           {
               out << *it << " ";
           }
           out << endl;
       }
       else
       {
           list<Fraction>::iterator ft;
           for(ft = f.begin(); ft != f.end(); ft++) 
           {
               out << ft->n << '/' << ft->d << " ";
           }
           out << endl;
       }
       
       i.clear();
       f.clear();
   }
   in.close();
   out.close();
   return 0;
}



