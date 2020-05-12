#include "Student.h"

Student::Student(){
  //default
}

Student::~Student(){
  //delete
}

string getMajor(){
  return major;
}

double getGPA(){
  return gpa;
}

LinkedList* getFaculty(){
  return faculty;
}

void setMajor(string major){
  this->major = major;
}

void setGPA(double gpa){
  this->gpa = gpa;
}

void setFaculty(LinkedList* faculty){
  this->faculty = faculty;
}
