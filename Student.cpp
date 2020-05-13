#include "Student.h"

Student::Student(){
  //default
}

Student::~Student(){
  //delete
}

string Student::getMajor(){
  return major;
}

double Student::getGPA(){
  return gpa;
}

int Student::getFaculty(){
  return faculty;
}

void Student::setMajor(string major){
  this->major = major;
}

void Student::setGPA(double gpa){
  this->gpa = gpa;
}

void Student::setFaculty(int faculty){
  this->faculty = faculty;
}
