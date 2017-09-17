#include <iostream>
#include "Whopper.h"
#include <vector>
using namespace std;

int main()
{
    string input = "";
    do
    {
        cout << "Please enter the sign than the number followed by the operator you want and than the second sign with the second ";
        cout << "number, signs consist of 1 for postive, 0 for zero, and -1 for negative: " << endl;
        string word = "";
        cin >> word;
        string word2 = "";
        string word3 = "";
        string op = "";
        int checker = 0;
        word2 += word.at(0);
        for(unsigned int i = 1; i < word.size(); i++)
        {
            if((word.at(i) >= 48) && (word.at(i) <= 57) && (checker == 0))
            {
                word2 += word.at(i);
            }
            else if((word.at(i) == 61) || (word.at(i) == 62) || (word.at(i) == 43) || (word.at(i) == 45) || (word.at(i) == 42))
            {
                op += word.at(i);
                checker++;
                if((word.at(i + 1) == 61) || (word.at(i + 1) == 62))
                {
                   op += word.at(i + 1);
                   i++;
                }
                if(word.at(i + 1) == 45)
                {
                    word3 += word.at(i + 1);
                    i++;
                    word3 += word.at(i + 1);
                    i++;
                }
            }
            else
            {
               word3 += word.at(i);
            }
        }  
        Whopper A;
        Whopper B; 
        Whopper C;
        A >> word2; // take in strings 
        B >> word3; 
        if((op.at(0) == '>') && (op.size() == 1))
        {
          if(A > B)
          {
               cout << "First number is greater than the second number!" << endl;
          }
          else
          {
              cout << "First number is not greater than the second number!" << endl;
          }
        }
        if((op.at(0) == '=') && (op.at(1) == '='))
        {
          if(A == B)
          {
               cout << "The numbers are equal!" << endl;
          }
          else
          {
              cout << "The numbers are not equal!" << endl;
          }
        }
        if((op.at(0) == '+') && (op.size() == 1))
        {
             C = A + B;
             C << word;
        }
        if((op.at(0) == '-') && (op.size() == 1))
        {
            C = A - B;
            C << word;
        }
        if((op.at(0) == '*') && (op.size() == 1))
        {
            C = A * B;
            C << word;
        }
        cout << "Do you want to continue? (1 no/exit yes)" << endl;
        cin >> input;
    }
    while(input != "exit");
    return 0;
}

