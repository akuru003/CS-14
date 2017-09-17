#ifndef BST_H
#define BST_H
#include <iostream>
#include "Fraction.h"
#include <vector>
using namespace std;

class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
           int num;
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
        void insert(int);
        void print_inorder(vector<int> &t);
        void inorder(tree_node*, vector<int> &t);
        void insertFraction(Fraction);
        void print_inorderFraction(vector<int> &t);
        void inorderFraction(tree_node*, vector<int> &t);
};
#endif