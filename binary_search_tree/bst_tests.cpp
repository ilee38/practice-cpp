/**
 * Test file for the BinarySearchTree class
 * */
#include <iostream>
#include "binary_search_tree.h"

int main(){
  BinarySearchTree bst = BinarySearchTree();
  std::cout<<"created bst object\n";
  BinarySearchTree::BSTNode *root = nullptr;
  std::cout<<"created empty root node\n";
  root = bst.insert(root, 15);
  std::cout<<"created node with value 15\n";
  root = bst.insert(root, 10);
  std::cout<<"created node with value 10\n";
  root = bst.insert(root, 20);
  std::cout<<"created node with value 20\n";
  root = bst.insert(root, 8);
  std::cout<<"created node with value 8\n";
  root = bst.insert(root, 12);
  std::cout<<"created node with value 12\n";
  root = bst.insert(root, 17);
  std::cout<<"created node with value 17\n";
  root = bst.insert(root, 25);
  std::cout<<"created node with value 25\n";
  root = bst.insert(root, 6);
  std::cout<<"created node with value 6\n";
  root = bst.insert(root, 11);
  std::cout<<"created node with value 11\n";
  root = bst.insert(root, 16);
  std::cout<<"created node with value 16\n";
  root = bst.insert(root, 27);
  std::cout<<"created node with value 27\n";
  std::cout<< "Current number of nodes: " <<bst.getNodeCount() <<"\n";
  std::cout<< "Is current tree a BST?\n";
  if(bst.isBST(root)){
    std::cout<<"yes\n";
  }else{
    std::cout<<"no\n";
  }
  std::cout<< "Printing node values in order...\n";
  bst.printValues(root);
  std::cout<<std::endl;
  std::cout<<"The minimum value in the BST is: " <<bst.getMin(root)->value <<"\n";
  std::cout<<"The maximum value in the BST is: " <<bst.getMax(root)->value <<"\n";
  std::cout<<"Tree's height is: " <<bst.getHeight(root) <<"\n";
  std::cout<< "Check if 17 is in tree: \n";
  if(bst.isInTree(root, 17)){
    std::cout<< "found it!\n";
  }else{
    std::cout<< "value not found in tree.\n";
  }
  std::cout<< "get successor of 25: " <<bst.getSuccessor(root, 25)->value <<"\n";
  std::cout<< "get successor of 17: " <<bst.getSuccessor(root, 17)->value <<"\n";
  std::cout<< "deleting 6...\n";
  bst.deleteValue(root, 6);
  bst.printValues(root);
  std::cout<<std::endl;
  std::cout<< "deleting 12...\n";
  bst.deleteValue(root, 12);
  bst.printValues(root);
  std::cout<<std::endl;
  std::cout<< "deleting 20...\n";
  bst.deleteValue(root, 20);
  bst.printValues(root);
  std::cout<<std::endl;
}