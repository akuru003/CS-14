#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include "HashTableChain.h"
#include <vector>
#include "HashTableProbe.h"
using namespace std;


int main(int argc, char **argv)
{ 
    if(argc != 4)
   {
      cout << "ERROR: Invalid program call." << endl;
      return 1;
   }
   string input = argv[1];
   string input2(argv[2]);
   string input3(argv[3]);  // ./a.out   -1 or -2     -chain or -probe        input file 
   string temp = "";
   string temp2 = "";
   int counter = 0;
   temp2 = input3.at(counter);
   while(temp2 != ".")
   {  
       temp += temp2;
       counter++;
       temp2 = input3.at(counter);
   }
   string outputfile1 = temp + ".out";
   string outputfile2 = temp + ".stats";  // create .out and .stats from input file 
   ifstream in(NULL);  
   ifstream in1(NULL);  
   ofstream out(NULL);
   ofstream out1(NULL);
   in.open(input3.c_str());
   if(!in.is_open())          //input file 
   {
      cout << "Error opening input file, ending program!" << endl;
      return 0;;
   }
   if(input == "-1")           //dictionary
   {
       in1.open("simple.txt");
       if(!in1.is_open())
       {
          cout << "Error opening dictionary file, ending program!" << endl;
          return 0;;
       }
   }
   else
   {
      in1.open("iSpell.txt");
      if(!in1.is_open())
      {
         cout << "Error opening dictionary file, ending program!" << endl;
         return 0;;
      }
   }
   out.open(outputfile1.c_str());
   if(!out.is_open())
   {
      cout << "Error opening output file 1, ending program!" << endl;
      return 0;;
   }
   out1.open(outputfile2.c_str());
   if(!out1.is_open())
   {
      cout << "Error opening output file 2, ending program!" << endl;
      return 0;;
   }
   HashTableChain<string> a;
   HashTableProbe<string> b;
   string temp3 = "";
   if(input2 == "-chain")
   {
      vector<Data> v;
      string takein = "";
      while(!in1.eof())
      { 
          getline(in1,takein); 
          istringstream line(takein);
          while(line >> temp3)
          {
              a.insert(temp3);
          }
          takein.clear();
      }
      a.toPrintChain(v);
      for(unsigned int i = 0; i < v.size(); i++)
      {
         out1 << v.at(i).size << ' ' << v.at(i).count << endl;
      }
   }
   else
   {
      vector<Data1> v1;
      vector<Data1> v;
      string takein = "";
      while(!in1.eof())
      { 
         getline(in1,takein); 
         istringstream line(takein);
         while(line >> temp3)
         {
             b.insert(temp3,v);
         }
         takein.clear();
      }
      for(unsigned int i = 0; i < v.size(); i++)
      {
         int match = 0;
         for(unsigned int j = 0; j < v1.size(); j++)
         {
            if(match == 0)
            {
                if(v1.at(j).collision == v.at(i).count)
                {
                   v1.at(j).count++;
                   match++;
                }   
            }
         }
         if(match == 0)
         {
            Data1 temp;
            temp.collision = v.at(i).count;
            temp.count = 1;
            v1.push_back(temp);
         }  
      }
      for(unsigned int i = 0; i < v1.size(); i++)
      {
         out1 << v1.at(i).collision << ' ' << v1.at(i).count << endl;
      }
   }
   if(input2 == "-chain") // if contains-else output to .out file
   {
      string takein = "";
      while(!in.eof())
      { 
          getline(in,takein); 
          istringstream line(takein);
          while(line >> temp3)
          {
              for(unsigned int i = 0; i < temp3.size(); i++)
              {
                 if((temp3.at(i) == 48) || (temp3.at(i) == 49) || (temp3.at(i) == 50) || (temp3.at(i) == 51) ||  (temp3.at(i) == 52) || (temp3.at(i) == 53) || (temp3.at(i) == 54) ||   (temp3.at(i) == 55) || (temp3.at(i) == 56)  || (temp3.at(i) == 57))                        
                 {
                    temp3.at(i) = ' ';
                 }
                 else
                 {
                   char c = temp3.at(i);
                   temp3.at(i) = tolower(c);  
                 }
              }
              if(a.contains(temp3))
              {
                 // do nothing
              }
              else
              {
                 out << temp3 << endl;
              }
          }
          takein.clear();
        
      }
   }
   else
   {
      string takein = "";
      while(!in.eof())
      { 
          getline(in,takein); 
          istringstream line(takein);
          while(line >> temp3)
          {
             for(unsigned int i = 0; i < temp3.size(); i++)
             {
                if((temp3.at(i) == 48) || (temp3.at(i) == 49) || (temp3.at(i) == 50) || (temp3.at(i) == 51) ||  (temp3.at(i) == 52) || (temp3.at(i) == 53) || (temp3.at(i) == 54) ||   (temp3.at(i) == 55) || (temp3.at(i) == 56) || (temp3.at(i) == 57))
                {
                   temp3.at(i) = ' ';
                }
                else
                {
                  char c = temp3.at(i);
                  temp3.at(i) = tolower(c);  
                }
             }
             if(b.contains(temp3))
             {
                // do nothing
             }
             else
             {
                out << temp3 << endl;
             }
          }
          takein.clear();
      }  
   }
   in.close();
   in1.close();
   out.close();
   out1.close();
   return 0;
}
