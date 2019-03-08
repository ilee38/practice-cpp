/*
 * Implmentation of BinarySearchTree class
*/
#include <iostream>
#include <queue>
#include <stdexcept>
#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree(){
  rootPtr = nullptr;
  height_ = 0;
  nodeCount_ = 0;
}


BinarySearchTree::~BinarySearchTree(){
  deleteTree();
}


BinarySearchTree::BSTNode* BinarySearchTree::_createNewNode(int val){
  BSTNode* newNode = new BSTNode;
  newNode->value = val;
  newNode->left = nullptr;
  newNode->right = nullptr;
  newNode->parent = nullptr;
  return newNode;
}


/*
 * Inserts new node in the tree
*/
void BinarySearchTree::insert(int val){
  BSTNode *newElement = _createNewNode(val);
  if(rootPtr == nullptr){
    rootPtr = newElement;
  }else{
    BSTNode *current = rootPtr;
    while(current != nullptr){
      if(newElement->value < current->value){
        current = current->left;
      }
      if(newElement->value > current->value){
        current = current->right;
      }
    }
    current = newElement;
    nodeCount_++;
  }
}


/*
* Prints the values in the tree from min to max
* by doing a DFS in-order traversal of the tree
*/
void BinarySearchTree::printValues(BSTNode *root) const{
  if(root == nullptr){ return; }
  printValues(root->left);
  std::cout<<root->value <<"\n";
  printValues(root->right);
}


/*
 * Delete each node in the tree from heap memory
*/
void BinarySearchTree::deleteTree(BSTNode *root){
  if(root == nullptr){ return; }
  if(root->left != nullptr){
    deleteTree(root->left);
  }
  if(root->right != nullptr){
    deleteTree(root->right);
  }
  delete root;
}


/**
 * Returns true/false if the value is in the tree
*/
bool BinarySearchTree::isInTree(BSTNode *node, int value) const{
  if(node == nullptr){return false;}
  if(node->value == value){
    return true;
  }
  if(value < node->value){isInTree(node->left, value);}
  if(value > node->value){isInTree(node->right, value);}
}


/**
 * Returns the height of a node, defined as the number of edges on the
 * longest path from the node to a leaf node. Single node height is 1.
*/
int BinarySearchTree::getHeight(BSTNode *node) const{
  if(node == nullptr){
    return -1;        //return -1 because we are counting edges, not nodes
  }
  int heightLeftTree = getHeight(node->left);
  int heightRightTree = getHeight(node->right);
  return std::max(heightLeftTree, heightRightTree) + 1;   //add 1 because we're counting edges
}


/**
 * Returns the minimum value stored in the tree
*/
int BinarySearchTree::getMin(BSTNode *node) const{
  if(node == nullptr){
    throw std::invalid_argument("Error: Tree is empty");
  }
  if(node->left == nullptr){
    return node->value;
  }
  return getMin(node->left);
}


/**
 * Returns the maximum value stored in the tree
*/
int BinarySearchTree::getMax(BSTNode *node) const{
  if(node == nullptr){
    throw std::invalid_argument("Error: Tree is empty");
  }
  if(node->right == nullptr){
    return node->value;
  }
  return getMax(node->right);
}


/**
 * Returns true/false wether the tree is a Binary Search Tree.
 * Performs Breadth-First Search to visit all elements and checks
 * that each value meets the constraints of a BST.
*/
bool BinarySearchTree::isBST(BSTNode *root) const{
  if(root == nullptr){
    throw std::invalid_argument("Error: Tree is empty");
  }
  std::queue<BSTNode*> Q;
  Q.push(root);
  if(root->left != nullptr){
    if(root->value > root->left->value){
      Q.push(root->left);
    }else{
      return false;
    }
  }
  if(root->right != nullptr){
    if(root->value < root->right->value){
      Q.push(root->right);
    }else{
      return false;
    }
  }
  Q.pop();
  if(Q.empty()){
    return true;
  }
  BSTNode *next = Q.front();
  return isBST(next);
}