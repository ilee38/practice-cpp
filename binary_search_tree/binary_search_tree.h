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
    int getNodeCount() const{ return nodeCount_; }
    void printValues(BSTNode*) const;       //prints values from min to max
    void deleteTree(BSTNode*);
    bool isInTree(BSTNode*, int) const;
    int getHeight(BSTNode*) const{ return height_; }
    int getMin(BSTNode*) const;
    int getMax(BSTNode*) const;
    bool isBST(BSTNode*) const;
    void deleteValue(int);
    int getSuccessor(int);

  private:
    BSTNode* _createNewNode(int);
    bool __isBST__(BSTNode*, std::queue<BSTNode*>) const;
    BSTNode *rootPtr;    //pointer to the root node
    int height_;
    int nodeCount_;
};
#endif
