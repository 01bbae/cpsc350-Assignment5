#include <iostream>
#include "TreeNode.h"

using namespace std;

template <class T>
class BST{
public:
  BST();
  ~BST();
  void insert(int k, T val);
  bool searchNode(int k);
  bool deleteNode(int k);
  bool isEmpty();
  TreeNode<T>* getMax();
  TreeNode<T>* getMin();
  TreeNode<T>* getSuccessor(TreeNode<T>* node);
  void printTree(TreeNode<T>* node);
  TreeNode<T> *root;
};

template<class T>
BST<T>::BST(){
  root = NULL;
}

template<class T>
BST<T>::~BST(){
  delete root;
}

template<class T>
void BST<T>::insert(int k, T val){
  TreeNode<T>* node = new TreeNode<T>(k,val);
  if(root == NULL){
    root = node;
    //if nothing in tree
  }else{
    TreeNode<T>* curr = root;
    TreeNode<T>* parent = root;
    while(true){
      parent = curr;
      if(val < curr->key){
        curr=curr->left;
        if(curr == NULL){
          parent->left = node;
          break;
        }
      }else{
        curr = curr->right;
        if(curr == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

template<class T>
bool BST<T>::searchNode(int k){
  if(isEmpty()){
    return false;
  }else{
    //if tree is not empty
    TreeNode<T>* curr = root;
    while(curr->key!=k){
      if(curr->key < k){
        curr = curr->left;
      }else if(curr->key >k){
        curr = curr->right;
      }else if(curr == NULL){
        return false;
      }
    }
    return true;
  }
}

template<class T>
bool BST<T>::deleteNode(int k){
  if(!searchNode(k)){
    return false;
  }
  //if tree is not empty
  TreeNode<T>* curr = root;
  TreeNode<T>* parent = root;
  bool isLeft;

  //searching for key
  while(curr->key != k){
    parent = curr;
    if(curr->key > k){
      isLeft = true;
      curr= curr->left;
    }else if(curr->key < k){
      isLeft = false;
      curr = curr->right;
    }else if(curr == NULL){
      return false;
    }
  }

  //deleting key
  if(curr->left == NULL && curr->right == NULL){ //no children
    if(root == NULL){
      root = NULL; // ???
    }else if(isLeft){
      parent->left = NULL;
    }else if(!isLeft){
      parent->right = NULL;
    }
  }else if(curr->left == NULL){ //no left children (?)
    if(root = curr){
      root = curr->right;
    }else if(isLeft){
      parent->left = curr->right;
    }else if(!isLeft){
      parent->right = curr->right;
    }
  }else if(curr->right == NULL){ //no right children (?)
    if(root = curr){
      root = curr->left;
    }else if(isLeft){
      parent->left = curr->left;
    }else if(!isLeft){
      parent->right = curr->left;
    }
  }else{ //node has two children
    TreeNode<T>* succ = getSuccessor(curr);
    if(root == succ){ // ???
      root = succ;
    }else if(isLeft){
      curr->left = succ;
    }else if(!isLeft){
      curr->right = succ;
    }
    succ->left = curr->left;

    return true;
  }
}

template<class T>
bool BST<T>::isEmpty(){
  return (root==NULL);
}

template<class T>
TreeNode<T>* BST<T>::getMax(){
  TreeNode<T>* curr = root;
  if(isEmpty()){ //error checking
    return NULL;
  }
  while(curr->right!=NULL){ //iterate to the rightmost node
    curr = curr->right;
  }
  return curr;
}

template<class T>
TreeNode<T>* BST<T>::getMin(){
  TreeNode<T>* curr = root;
  if(isEmpty()){ //error checking
    return NULL;
  }
  while(curr->left!=NULL){ //iterate to the leftmost node
    curr = curr->left;
  }
  return curr;
}

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* node){
  TreeNode<T>* curr = node->right;
  TreeNode<T>* sp = node;
  TreeNode<T>* successor = node;

  while(curr!=NULL){
    sp = successor;
    successor = curr;
    curr = curr->left;
  }

  if(successor!=node->right){
    sp->left = successor->right;
    successor->right = node->right;
  }
  return successor;
}

template<class T>
void BST<T>::printTree(TreeNode<T> *node){
  if(node != NULL){
    printTree(node->left);
    cout << node->value << endl;
    printTree(node->right);
  }
}
