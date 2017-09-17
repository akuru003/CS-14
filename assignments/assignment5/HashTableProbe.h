#ifndef HASHTABLEPROBE_H
#define HASHTABLEPROBE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct Data1
{
   int count; 
   int collision;
};

int nextPrime(int n);
int hash(const string & key);
int hash(int key);
// QuadraticProbing Hash table class
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
class HashTableProbe
{
  public:
    explicit HashTableProbe(int size = 0) // start empty list
    : array(nextPrime(size))
      { 
          makeEmpty(); 
      }
    bool contains(const HashedObj & x) const
    {
        return isActive(findPos1(x));
    }
    void makeEmpty()
    {
        currentSize = 0;
        for(int i = 0; i < array.size(); i++)
        {
            array[i].info = EMPTY;
            array[i].element = "";
        }
    }
    bool insert(const HashedObj & x,vector<Data1> &v)
    {
        int currentPos = findPos(x,v);
        if(isActive(currentPos))
        {
            return false;
        }
        array[currentPos] = HashEntry(x, ACTIVE);
        if(++currentSize > array.size() / 2)
        {
            rehash(v);
        }
        return true;
    }
    bool remove(const HashedObj & x)
    {
        int currentPos = findPos1(x);
        if(!isActive(currentPos))
        {
            return false;
        }
        array[currentPos].info = DELETED;
        array[currentPos].element = "";
        return true;
    }
    enum EntryType 
    {
        ACTIVE, EMPTY, DELETED // 0,1,2
    };

  private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry(const HashedObj & e = HashedObj(), EntryType i = EMPTY)
          : element(e), info(i) 
          {
              // nothing
          }
    };
    vector<HashEntry> array;
    int currentSize;
    bool isActive(int currentPos) const
    { 
          return array[currentPos].info == ACTIVE;
    }
    int findPos(const HashedObj & x,vector<Data1> &v) const
    {
        int offset = 1;
        int currentPos = myhash(x);
        while(array[currentPos].info != EMPTY && array[currentPos].element != x)
        {
            int match = 0;
            for(unsigned int i = 0; i < v.size(); i++)
            {
                if(match == 0)
                {
                    if(v.at(i).collision == currentPos)
                    {
                        v.at(i).count++;
                        match++;
                    }   
                }
            }
            if(match == 0)
            {
                Data1 temp;
                temp.collision = currentPos;
                temp.count = 1;
                v.push_back(temp);
            }
            match = 0;
            currentPos += offset;  
            offset += 2;
            if(currentPos >= array.size())
            {
                currentPos -= array.size();
            }
        }
        return currentPos;
    }
    int findPos1(const HashedObj & x) const
    {
        int offset = 1;
        int currentPos = myhash(x);
        while(array[currentPos].info != EMPTY && array[currentPos].element != x)
        {
            currentPos += offset;  
            offset += 2;
            if(currentPos >= array.size())
            {
                currentPos -= array.size();
            }
        }
        return currentPos;
    }
    void rehash(vector<Data1> &v)
    {
        vector<HashEntry> oldArray = array;
        array.resize(nextPrime(2 * oldArray.size()));
        for(int j = 0; j < array.size(); j++)
        {
            array[j].info = EMPTY;
            array[j].element = "";
        }
        currentSize = 0;
        for(int i = 0; i < oldArray.size(); i++)
        {
            if(oldArray[i].info == ACTIVE)
            {
                insert(oldArray[i].element,v);
            }
        }
    }
    int myhash(const HashedObj & x) const
    {
        int hashVal = hash(x);
        hashVal %= array.size();
        if(hashVal < 0)
        {
            hashVal += array.size();
        }
        return hashVal;
    }
};

#endif