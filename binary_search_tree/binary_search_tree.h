/*
 * Class definition for a Binary Search Tree
*/
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <queue>
#include <iostream>

class BinarySearchTree{

  public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int);
    int getNodeCount() const;
    void printValues() const;
    void deleteTree();
    bool isInTree() const;
    int getHeight() const;
    int getMin() const;
    int getMax() const;
    bool isBST() const;
    void deleteValue();
    int getSuccessor();

  private:
    int height_;
    int nodeCount_;
    struct BSTNode_{
      int value;
      BSTNode *left;
      BSTNode *right;
      BSTNode *parent;
    };

};
#endif
