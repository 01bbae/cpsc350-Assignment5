class Student : public Person{
public:
  typedef Person super;
  Student();
  Student(int id, string name, string level, string major, double gpa, int faculty):super(int id, string name, string level){
    this->major = major;
    this->gpa = gpa;
    this->faculty = faculty;
  }
  ~Student();
  string getMajor();
  double getGPA();
  LinkedList* getFaculty();
  void setMajor(string major);
  void setGPA(double gpa);
  void setFaculty(LinkedList* faculty);

private:
  string major;
  double gpa;
  LinkedList* faculty; //replace with list
};
