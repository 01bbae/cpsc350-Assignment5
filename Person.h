#include <iostream>

class Person{
public:
  Person();
  Person(int id, string name, string level);
  ~Person();
  int getID();
  string getName();
  string getLevel();
  void setID(int id);
  void setName(string name);
  void setLevel(string level);
private:
  int id;
  string name;
  string level;
};
