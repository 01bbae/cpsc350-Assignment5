class Student : public Person{
public:
  typedef Person super;
  Person();
  Person(int id, string name, string level, string major, double gpa, int faculty):super(int id, string name, string level){
    this->major = major;
    this->gpa = gpa;
    this->faculty = faculty;
  }
  string major;
  double gpa;
  int faculty;
};
