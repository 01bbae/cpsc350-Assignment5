#include "Person.h"

Person::Person(){
  //default
}

Person::Person(int id, string name, string level){
  this->id = id;
  this->name = name;
  this->level = level;
}

Person::~Person(){
  //delete
}
