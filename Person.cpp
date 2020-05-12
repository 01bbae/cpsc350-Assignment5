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

string Person::getID(){
  return id;
}

string Person::getName(){
  return name;
}

string Person::getLevel(){
  return level;
}

void Person::setID(int id){
  this->id = id;
}

void Person::setName(string name){
  this->name = name;
}

void Person::setLevel(string level){
  this->level = level;
}
