/*
 * Class definition for a Binary Search Tree
*/
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <queue>
#include <iostream>

class BinarySearchTree{

  struct BSTNode{
    int value;
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;
  };

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
    void deleteValue(int);
    int getSuccessor(int);

  private:
    BSTNode _createNewNode(int);
    BSTNode *rootPtr;    //pointer to the root node
    int height_;
    int nodeCount_;
};
#endif
