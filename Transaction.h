#include <iostream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

class Transaction{
public:
  Transaction();
  Transaction(string message, BST<Student*> studentBST, BST<Faculty*> facultyBST);
  ~Transaction();
  string message;
  BST<Student*> studentBST;
  BST<Faculty*> facultyBST;
};
