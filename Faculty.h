#ifndef FACULTY_H
#define FACULTY_H
#include "Person.h"
#include "BST.h"

using namespace std;

class Faculty : public Person{
public:
  typedef Person super;
  Faculty();
  Faculty(int id, string name, string level, string department):super(id, name, level){
    this->department = department;
    //database->insert(id, new Faculty(id,name,level,department));
  }
  ~Faculty();
  string getDepartment();
  //BST<Faculty*>* getDatabase();
  void setDepartment(string department);
  //void setDatabase(BST<Faculty*>* database);
  //static BST<Faculty*>* database;

private:
  string department;
};

#endif
