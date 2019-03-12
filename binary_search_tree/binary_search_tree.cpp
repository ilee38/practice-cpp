/*
 * Implmentation of BinarySearchTree class
*/
#include <iostream>
#include <queue>
#include <stdexcept>
#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree(){
  rootPtr = nullptr;
  nodeCount_ = 0;
}


BinarySearchTree::~BinarySearchTree(){
  deleteTree(rootPtr);
}


BinarySearchTree::BSTNode* BinarySearchTree::_createNewNode(int val){
  BSTNode* newNode = new BSTNode;
  newNode->value = val;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}


/*
 * Inserts new node in the tree. Returns a pointer to the root node
 * of the tree.
*/
BinarySearchTree::BSTNode* BinarySearchTree::insert(BSTNode *node, int val){

  if(node == nullptr){
    node = _createNewNode(val);
    return node;
  }
  if(val < node->value){
    node->left = insert(node->left, val);
  }else if(val > node->value){
    node->right = insert(node->right, val);
  }
  nodeCount_++;
  return node;
}


/*
* Prints the values in the tree from min to max
* by doing a DFS in-order traversal of the tree
*/
void BinarySearchTree::printValues(BSTNode *root) const{
  if(root == nullptr){ return; }
  printValues(root->left);
  std::cout<<root->value <<" ";
  printValues(root->right);
  std::cout<<std::endl;
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
 * Returns true/false if the value is in the tree.
 * Starts from the root of the tree.
*/
bool BinarySearchTree::isInTree(BSTNode *root, int value) const{
  if(root == nullptr){return false;}
  if(root->value == value){
    return true;
  }
  if(value < root->value){isInTree(root->left, value);}
  if(value > root->value){isInTree(root->right, value);}
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
 * Returns the node with the minimum value stored in the tree
*/
BinarySearchTree::BSTNode* BinarySearchTree::getMin(BSTNode *node) const{
  if(node == nullptr){
    throw std::invalid_argument("Error: Tree is empty");
  }
  if(node->left == nullptr){
    return node;
  }
  return getMin(node->left);
}


/**
 * Returns the node with the maximum value stored in the tree
*/
BinarySearchTree::BSTNode* BinarySearchTree::getMax(BSTNode *node) const{
  if(node == nullptr){
    throw std::invalid_argument("Error: Tree is empty");
  }
  if(node->right == nullptr){
    return node;
  }
  return getMax(node->right);
}


/**
 * Called by isBST(), performs Breadth-First Search to visit all elements in the
 * tree and checks that each value meets the constraints of a BST. The function
 * stops as soon as a value does not meet the properties of a BST and returns false.
*/
bool BinarySearchTree::__isBST__(BSTNode *root, std::queue<BSTNode*> Q) const{
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
  if(Q.empty()){
    return true;
  }
  BSTNode *next = Q.front();
  Q.pop();
  return __isBST__(next, Q);
}


/**
 * Returns true/false wether the tree is a Binary Search Tree.
 * Uses helper function __isBST__()
*/
bool BinarySearchTree::isBST(BSTNode *root) const{
  if(root == nullptr){
    throw std::invalid_argument("Error: Tree is empty");
  }
  std::queue<BSTNode*> Q;
  return __isBST__(root, Q);
}


BinarySearchTree::BSTNode* BinarySearchTree::deleteValue(BSTNode *root, int value){
  //find the node in the tree
  if(root == nullptr){return root;}
  if(value < root->value) root->left = deleteValue(root->left, value);
  else if(value > root->value) root->right = deleteValue(root->right, value);
  else{     //value has been found!
    //case 1 - no children (delete the node and set the parent's reference to it to nullptr)
    if(root->left == nullptr && root->right == nullptr){
      delete root;
      root = nullptr;
      nodeCount_--;
      return root;
    }
    //case 2 - only 1 child
    else if(root->right == nullptr){
      BSTNode *temp = root;
      root = root->left;
      delete temp;
      nodeCount_--;
      return root;
    }
    else if(root->left == nullptr){
      BSTNode *temp = root;
      root = root->right;
      delete temp;
      nodeCount_--;
      return root;
    }
    //case 3 - two children (replace node with its predecessor, i.e. max node on left sub-tree)
    //                      (find predecessor, exchange values, then delete the predecessor)
    else{
      BSTNode *predecessor = getMax(root->left);
      root->value = predecessor->value;
      root->left = deleteValue(predecessor, predecessor->value);
      nodeCount_--;
      return root;
    }
  }
}


/**
 * Returns the node with the succesor of the given value or nullptr if there's no successor.
 * If the node has a right sub-tree, the successor is the min value of the node's right sub-tree
 * Otherwise, we need to find the deepest ancestor of which this node is on its left sub-tree
*/
BinarySearchTree::BSTNode* BinarySearchTree::getSuccessor(BSTNode* root, int value) const{
  if(root == nullptr || (root->left == nullptr && root->right == nullptr)){return root;}
  //find the target node
  BSTNode *current = root;
  while(current != nullptr){
    if(value == current->value)break;
    else if(value < current->value){
      current = current->left;
    }else if(value > current->value){
      current = current->right;
    }
  }
  //case 1: the node has a right sub-tree
  if(current->right != nullptr){
    return getMin(current->right);
  }
  //case 2: the node has no right sub-tree
  else{
    BSTNode *succesor = nullptr;
    BSTNode *ancestor = root;
    while(ancestor != current){
      if(current->value < ancestor->value){
        succesor = ancestor;      //so far this is the deepest node of which current is on its left
        ancestor = ancestor->left;  //but keep looking
      }else{
        ancestor = ancestor->right;   //the current node was on the right of the ancestor, so advance
      }                               //and keep looking to the left
    }
    return succesor;
  }
}