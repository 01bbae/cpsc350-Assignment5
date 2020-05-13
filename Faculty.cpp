#include "Faculty.h"

Faculty::Faculty(){
  //default
}

Faculty::~Faculty(){
  //delete
}

string Faculty::getDepartment(){
  return department;
}

// BST<Faculty*>* Faculty::getDatabase(){
//   return database;
// }

void Faculty::setDepartment(string department){
  this->department = department;
}

// void Faculty::setDatabase(BST<Faculty*>* database){
//   this->database = database;
// }

//BST<Faculty*>* Faculty::database;
