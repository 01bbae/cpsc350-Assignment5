#include "Student.h"
#include "Faculty.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include "Transaction.h"
#include "GenStack.h"

using namespace std;

class IO{
public:
  IO();
  ~IO();
  void prompt();
  void printStudents(TreeNode<Student*>* node);
  void printFaculty(TreeNode<Faculty*>* node);
  void getStudent(int id);
  void getFaculty(int id);
  void getAdvisor(int id);
  void getAdvisee(int id); //code
  void addStudent(int id, string name, string level, string major, double gpa, int faculty);
  int deleteStudent(int id); //add removal of list from faculty
  void addFaculty(int id, string name, string level, string department);
  int deleteFaculty(int id); //add removal from advisor
  void changeAdvisor(int studentid, int facultyid);
  int removeAdvisee(int studentid); //code
  void rollback();
  ifstream studentfile;
  ifstream facultyfile;

  static BST<Student*>* studentBST;
  static BST<Faculty*>* facultyBST;
  GenStack<Transaction*>* undo;
};
