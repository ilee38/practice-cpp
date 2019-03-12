/*
 * Class definition for a Binary Search Tree
*/
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <queue>
#include <iostream>

class BinarySearchTree{

  public:
    struct BSTNode{
      int value;
      BSTNode *left;
      BSTNode *right;
    };

    BinarySearchTree();
    BSTNode* insert(BSTNode*, int);
    void printValues(BSTNode*) const;       //prints values from min to max
    void deleteTree(BSTNode*);
    bool isInTree(BSTNode*, int) const;
    int getHeight(BSTNode*) const;
    BSTNode* getMin(BSTNode*) const;
    BSTNode* getMax(BSTNode*) const;
    bool isBST(BSTNode*) const;
    BSTNode* deleteValue(BSTNode*, int);
    BSTNode* getSuccessor(BSTNode*, int) const;

  private:
    BSTNode* _createNewNode(int);
    bool __isBST__(BSTNode*, std::queue<BSTNode*>) const;

    BSTNode *rootPtr;    //pointer to the root node
};
#endif
