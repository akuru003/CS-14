#include <iostream>
#include "Bst.h"
#include "Fraction.h"
#include <cstdlib>
#include <vector>
using namespace std;

void BinarySearchTree::insert(int d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    
    // is this a new tree?
    if(isEmpty()) 
    {
        root = t;
    }
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(t->data > curr->data) curr = curr->right;
            else curr = curr->left;
        }

        if(t->data < parent->data)
           parent->left = t;
        else if(t->data == parent->data)
        {
            if(rand() < RAND_MAX/2)
            {
                parent->left = t;
            }
            else
            {
                parent->right = t;
            }

        }
        else
           parent->right = t;
    }
}
void BinarySearchTree::print_inorder(vector<int> &t)
{
  inorder(root,t);
}
void BinarySearchTree::inorder(tree_node* p,vector<int> &t)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left,t);
        t.push_back(p->data);
        if(p->right) inorder(p->right,t);
    }
    else return;
}
void BinarySearchTree::insertFraction(Fraction d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->num = d.n;
    t->denom = d.d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    int numa = t->num;
    int numb = t->denom;
    t->data1 = ((static_cast<double>(numa)) / (static_cast<double>(numb)));
    // is this a new tree?
    if(isEmpty()) 
    {
        root = t;
    }
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(t->data1 > curr->data1) curr = curr->right;
            else curr = curr->left;
        }
        if(t->data1 < parent->data1)
           parent->left = t;
        else if(t->data1 == parent->data1)
        {
            if(rand() < RAND_MAX/2)
            {
                parent->left = t;
            }
            else
            {
                parent->right = t;
            }
        }
        else
           parent->right = t;
    }
}
void BinarySearchTree::print_inorderFraction(vector<int> &t)
{
  inorderFraction(root,t);
}
void BinarySearchTree::inorderFraction(tree_node* p, vector<int> &t)
{
    if(p != NULL)
    {
        if(p->left) inorderFraction(p->left,t);
        t.push_back(p->num);
        t.push_back(p->denom);
        if(p->right) inorderFraction(p->right,t);
    }
    else return;
}







