#include "HashTableChain.h"
#include <iostream>
using namespace std;


/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime1(int n)
{
    if((n == 2) || (n == 3))
    {
        return true;
    }
    if((n == 1) || (n % 2 == 0))
    {
        return false;
    }
    for(int i = 3; i * i <= n; i += 2)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime1(int n)
{
    if(n % 2 == 0)
    {
        n++;
    }
    for( ; !isPrime1(n); n += 2)
        ;

    return n;
}

/**
 * A hash routine for string objects.
 */
int hash1(const string & key)
{
    // int hashVal = 0;
    // for(unsigned int i = 0; i < key.length(); i++)
    // {
    //     hashVal = 37 * hashVal + key[i];
    // }
    // return hashVal;
    
    int hashVal = 0;
    for(unsigned int i = 0; i < key.size(); i++)
    {
        char ch = key.at(i);
        int highorder = hashVal & 0xf8000000;
        hashVal = hashVal << 5;
        hashVal = hashVal ^ (highorder >> 27);
        hashVal = hashVal ^ ch;
    }
    return hashVal;
}

/**
 * A hash routine for ints.
 */
int hash1(int key)
{
    return key;
}