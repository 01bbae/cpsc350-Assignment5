#include "Transaction.h"

Transaction::Transaction(){
  //default
}

Transaction::Transaction(string message, BST<Student*> studentBST, BST<Faculty*> facultyBST){
  this->message = message;
  this->studentBST = studentBST;
  this->facultyBST = facultyBST;
}
