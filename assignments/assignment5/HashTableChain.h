#ifndef HASHTABLECHAIN_H
#define HASHTABLECHAIN_H

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Data
{
   int count; 
   int size;
};


int nextPrime1(int n);
int hash1(const string & key);
int hash1(int key);

// SeparateChaining Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hash( string str ) --> Global method to hash strings

template <typename HashedObj>
class HashTableChain
{
    public:
    explicit HashTableChain()
      : currentSize(0)
      { 
          theLists.resize(1); 
          makeEmpty();
      }
    bool contains(const HashedObj & x) const
    {
        const list<HashedObj> & whichList = theLists[myhash(x)];
        return find(whichList.begin( ), whichList.end(), x) != whichList.end();
    }
    void makeEmpty()
    {
        for(int i = 0; i < theLists.size(); i++)
        {
            theLists[i].clear();
        }
    }
    void toPrintChain(vector<Data> &a)
    {
        int match = 0;
        for(int i = 0; i < theLists.size(); i++)
        {
          for(int j = 0; j < a.size(); j++)
          {
              if(a.at(j).size == theLists.at(i).size())
              {
                  a.at(j).count++;
                  match++;
              }
          }
          if(match == 0)
          {
                Data temp;
                temp.size = theLists.at(i).size();
                temp.count = 1;
                a.push_back(temp);
          }
          match = 0;
        }
    }
    bool insert(const HashedObj & x)
    {
        list<HashedObj> & whichList = theLists[myhash(x)];
        if(find(whichList.begin(), whichList.end(), x) != whichList.end())
        {
            return false;
        }
        whichList.push_back(x);
        if(++currentSize > theLists.size())
        {
            rehash();
        }
        return true;
    }
    bool remove(const HashedObj & x)
    {
        list<HashedObj> & whichList = theLists[myhash(x)];
        typename list<HashedObj>::iterator itr = find(whichList.begin(), whichList.end(), x);
        if(itr == whichList.end())
        {
            return false;
        }
        whichList.erase(itr);
        --currentSize;
        return true;
    }
  private:
    vector<list<HashedObj> > theLists;  
    int currentSize;
    void rehash()
    {
        vector<list<HashedObj> > oldLists = theLists;
        theLists.resize(nextPrime1(2 * theLists.size()));
        for(int j = 0; j < theLists.size(); j++)
        {
            theLists[j].clear();
        }
        currentSize = 0;
        for(int i = 0; i < oldLists.size(); i++)
        {
            typename list<HashedObj>::iterator itr = oldLists[i].begin();
            while(itr != oldLists[i].end())
            {
                insert(*itr++);
            }
        }
    }
    int myhash(const HashedObj & x) const
    {
        int hashVal = hash1(x);
        hashVal %= theLists.size();
        if(hashVal < 0)
        {
            hashVal += theLists.size();
        }
        return hashVal;
    }
};
#endif