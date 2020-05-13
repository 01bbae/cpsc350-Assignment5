#ifndef STUDENT_H
#define STUDENT_H
#include "Faculty.h"
#include "Person.h"

using namespace std;

class Student : public Person{
public:
  typedef Person super;
  Student();
  Student(int id, string name, string level, string major, double gpa, int faculty):super(id, name, level){
    this->major = major;
    this->gpa = gpa;
    this->faculty = faculty;
  }
  ~Student();
  string getMajor();
  double getGPA();
  int getFaculty();
  void setMajor(string major);
  void setGPA(double gpa);
  void setFaculty(int faculty);
private:
  string major;
  double gpa;
  int faculty;
};

#endif
