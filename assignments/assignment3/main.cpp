#include <iostream>
#include <vector> 
#include <fstream>
#include <sstream>
using namespace std;

int maxSubSum1(const vector<int> &a,int &totalTicks,const unsigned int minSeq,int& ansValid)
{
    unsigned int w = 0;
    w = a.size();
    if(minSeq > w)
    {
         ansValid = 0;
         return 0;
    }
    int maxSum = 0;
    for(unsigned int b = 0; b < minSeq; b++)
    {
        maxSum += a.at(b);
        totalTicks++;
    }
    for(unsigned int i = 0; i < a.size(); i++)
    {
        for(unsigned int j = i; j < a.size(); j++)
        {
            int thisSum = 0;
            unsigned int counter = 0;
            for(unsigned int k = i; k <= j; k++)
            {
                thisSum += a.at(k);
                totalTicks++;
                counter++;
                if((thisSum > maxSum) && (counter >= minSeq))
                {
                    maxSum = thisSum;
                }
            }
        }
    }
    return maxSum;
}
int maxSubSum2(const vector<int> &a,int &totalTicks,const unsigned int minSeq,int& ansValid)
{
    unsigned int w = 0;
    w = a.size();
    if(minSeq > w)
    {
         ansValid = 0;
         return 0;
    }
    int maxSum = 0;
    for(unsigned int k = 0; k < minSeq; k++)
    {
        maxSum += a.at(k);
        totalTicks++;
    }
    for(unsigned int i = 0; i < a.size(); i++)
    {
        int thisSum = 0;
        unsigned int counter = 0;
        for(unsigned int j = i; j < a.size(); j++)
        {
            thisSum += a[j];
            totalTicks++;
            counter++;
            if((thisSum > maxSum) && (counter >= minSeq))
            {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}
int max3( int a, int b, int c)
{
    return a > b ? a > c ? a : c : b > c ? b : c;
}
int maxSumRec(const vector<int> &a,int left,int right,int &totalTicks,const unsigned int minSeq)
{
    int maxSum = 0;
    unsigned int val = right - left;
    if(val == minSeq)
    {
        for(int i = left; i <= right; i++)
        {
            maxSum += a.at(i);
        }
        totalTicks++;
        return maxSum;
    }
    else if(left == right)
    {
        if(a[left] > 0)
        {
            totalTicks++;
            return a[left];
        }
        else
        {
            totalTicks++;
            return 0;
        }
    }
    int center = (left + right) / 2;
    int maxLeftSum = maxSumRec(a, left, center,totalTicks,minSeq);
    int maxRightSum = maxSumRec(a, center + 1, right,totalTicks,minSeq);
    int maxLeftBorderSum = 0;
    for(int i = center; i >= left; --i)
    {
        maxLeftBorderSum += a[i];
        totalTicks++;
    }
    int leftBorderSum = 0;
    for(int i = center; i >= left; --i)
    {
        leftBorderSum += a[i];
        totalTicks++;
        if(leftBorderSum > maxLeftBorderSum)
        {
            maxLeftBorderSum = leftBorderSum;
        }
    }
    int maxRightBorderSum = 0;
    for(int i = center; i <= right; i++)
    {
        maxRightBorderSum += a[i];
        totalTicks++;
    }
    int rightBorderSum = 0;
    for(int j = center + 1; j <= right; ++j)
    {
        rightBorderSum += a[j];
       totalTicks++;
        if(rightBorderSum > maxRightBorderSum)
        {
            maxRightBorderSum = rightBorderSum;
        }
    }
    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}
int maxSubSum3(const vector<int> &a,int &totalTicks,const unsigned int minSeq,int& ansValid)
{
    unsigned int w = 0;
    w = a.size();
    if(minSeq > w)
    {
         ansValid = 0;
         return 0;
    }
    return maxSumRec(a, 0, a.size() - 1, totalTicks, minSeq);
}
int maxSubSum4(const vector<int> &a,int &totalTicks,const unsigned int minSeq,int& ansValid)
{
    unsigned int w = 0;
    w = a.size();
    if(minSeq > w)
    {
         ansValid = 0;
         return 0;
    }
    int maxSum = 0;
    int thisSum = 0;
    unsigned int counter = 0;
    for(unsigned int i = 0; i < minSeq; i++)
    {
        maxSum += a.at(i);
        totalTicks++;
    }
    for(unsigned int j = 0; j < a.size(); j++) 
    {                                          
        thisSum += a[j];
        totalTicks++;
        counter++;
        if(maxSum >= 0)
        {
            if((thisSum > maxSum) && (counter >= minSeq))
            {
                maxSum = thisSum;
            }
            else if((thisSum < 0) && (counter >= minSeq))
            {
                thisSum = 0;
            }   
        }
        else
        {
            if((thisSum > maxSum) && (counter >= minSeq))
            {
                maxSum = thisSum;
            }
            if(counter >= minSeq)
            {
                thisSum = 0;
                counter = 0;
            }
        }
    }
    return maxSum;
}
int main(int argc, char **argv)
{
   if(argc != 2)
   {
      cout << "ERROR: Invalid program call." << endl;
      return 1;
   }
   string input1(argv[1]);
   string outputfile1 = "input.out";
   string outputfile2 = "input.csv";
   vector<int> a;
   string d = "";
   int number = 0;
   unsigned int minSeq = 0;
   ifstream in(NULL);  
   ofstream out(NULL);
   ofstream out2(NULL);
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
   out2.open(outputfile2.c_str());
   if(!out2.is_open())
   {
      cout << "Error opening output file 2, ending program!" << endl;
      return 0;;
   }
   while(!in.eof())
   { 
       in >> minSeq;
       getline(in,d); 
       d.clear();
       getline(in,d); 
       istringstream line(d);
       while(line >> number)
       {
           a.push_back(number);
       }
       int ansValid1 = 1;
       int ansValid2 = 1;
       int ansValid3 = 1;
       int ansValid4 = 1;
       int maxSum = 0;
       int totalTicks = 0;
       int tickalgo1 = 0;
       int tickalgo2 = 0;
       int tickalgo3 = 0;
       int tickalgo4 = 0;
       maxSum = maxSubSum1(a,totalTicks,minSeq,ansValid1);
       tickalgo1 = totalTicks;
       out << ansValid1 << ' ';
       out << maxSum << ' ';
       totalTicks = 0;
       maxSum = maxSubSum2(a,totalTicks,minSeq,ansValid2);
       tickalgo2 = totalTicks;
       out << ansValid2 << ' ';
       out << maxSum << ' ';
       totalTicks = 0;
       maxSum = maxSubSum3(a,totalTicks,minSeq,ansValid3);
       tickalgo3 = totalTicks;
       out << ansValid3 << ' ';
       out << maxSum << ' ';
       totalTicks = 0;
       maxSum = maxSubSum4(a,totalTicks,minSeq,ansValid4);
       tickalgo4 = totalTicks;
       out << ansValid4 << ' ';
       out << maxSum << endl;
       totalTicks = 0;
       out2 << a.size() << ' ' << minSeq << ' ' << ansValid1 << ' ' << ansValid2 << ' ' << ansValid3 << ' ' << ansValid4 << ' ' << tickalgo1 << ' ' << tickalgo2 << ' '  << tickalgo3 << ' '  << tickalgo4 << endl;
       a.clear();
   }
   in.close();
   out.close();
   out2.close();
   return 0;
}






