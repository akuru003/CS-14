#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include "Fraction.h"
#include <cstdlib>
#include <vector>
using namespace std;

template<class T>
class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           T data;
        };
        tree_node* root;
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
        bool isEmpty() const 
        {
            return (root == NULL);
        }
        void insert(T x);
        void iterate(tree_node*, vector<T> &t);
        void sort(list<T> &temp, BinarySearchTree b);
};

template<class T>
void BinarySearchTree<T>::insert(T x)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = x;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    if(isEmpty()) 
    {
        root = t;
    }
    else
    {
        tree_node* current;
        current = root;
        while(current)
        {
            parent = current;
            if(t->data > current->data) 
            {
                current = current->right;
            }
            else 
            {
                current = current->left;
            }
        }
        if(t->data < parent->data)
        {
           parent->left = t;
        }
        else if(t->data == parent->data)
        {
            if(rand() < RAND_MAX/2)
            {
                parent->right = t;
            }
            else
            {
                parent->left = t;
            }
        }
        else
        {
           parent->right = t;
        }
    }
}

template<class T>
void BinarySearchTree<T>::iterate(tree_node* p,vector<T> &t)
{
    if(p != NULL)
    {
        if(p->left)
        {
            iterate(p->left,t);
        }
        t.push_back(p->data);
        if(p->right)
        {
            iterate(p->right,t);
        }
    }
    else return;
}

template<class T>
void BinarySearchTree<T>::sort(list<T> &temp, BinarySearchTree b)
{
     vector<T> val;
     b.iterate(root,val);
     temp.clear();
     for(unsigned int i = 0; i < val.size(); i++)
     {
         temp.push_back(val.at(i));
     }
}

template<>
class BinarySearchTree<Fraction>
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int  num;
           int denom;
           double data1;
        };
        tree_node* root;
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
        bool isEmpty() const 
        {
            return (root == NULL);
        }
        void insert(Fraction a)
        {
            tree_node* t = new tree_node;
            tree_node* parent;
            t->num = a.n;
            t->denom = a.d;
            t->left = NULL;
            t->right = NULL;
            parent = NULL;
            int numa =  t->num;
            int numb =  t->denom;
            t->data1 = ((static_cast<double>(numa)) / (static_cast<double>(numb)));
            if(isEmpty()) 
            {
                root = t;
            }
            else
            {
                tree_node* current;
                current = root;
                while(current)
                {
                    parent = current;
                    if(t->data1 > current->data1)
                    {
                        current = current->right;
                    }
                    else 
                    {
                        current = current->left;
                    }
                }
                if(t->data1 < parent->data1)
                {
                   parent->left = t;
                }
                else if(t->data1 == parent->data1)
                {
                    if(rand() < RAND_MAX/2)
                    {
                        parent->right = t;
                    }
                    else
                    {
                        parent->left = t;
                    }
                }
                else
                {
                   parent->right = t;
                }
            }
        }
        void iterate(tree_node* p, vector<int> &t)
        {
            if(p != NULL)
            {
                if(p->left)
                {
                    iterate(p->left,t);
                }
                t.push_back(p->num);
                t.push_back(p->denom);
                if(p->right) 
                {
                    iterate(p->right,t);
                }
            }
            else 
            {
                return;
            }
        }
        void sort(list<Fraction> &temp, BinarySearchTree b)
        {
             vector<int> val;
             b.iterate(root,val);
             temp.clear();
             for(unsigned int i = 0; i < val.size(); i++)
             {
                 Fraction a(val[i],val[i + 1]);
                 temp.push_back(a);
                 i++;
             }
        }
};

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
       BinarySearchTree<int> a;
       BinarySearchTree<Fraction> b;
       if(i.size() != 0)
       {
           list<int>::iterator it;
           for(it = i.begin(); it != i.end(); it++) 
           {
               a.insert(*it);
           }
       }
       else
       {
           list<Fraction>::iterator ft;
           for(ft = f.begin(); ft != f.end(); ft++) 
           {
              b.insert(*ft);
           }
       }
       if(i.size() != 0)
       {
          a.sort(i,a);
       }
       else
       {
          b.sort(f,b);
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