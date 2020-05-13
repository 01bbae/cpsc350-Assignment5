#include "IO.h"

IO::IO(){
  //default constructor
  bool facultybool = false;
  bool studentbool = false;
  if (FILE *file = fopen("facultyTable.txt", "r")) {
     fclose(file);
     facultybool = true;
  }
  if (FILE *file = fopen("studentTable.txt", "r")) {
     fclose(file);
     studentbool = true;
  }

  int id;
  string name;
  string level;
  //student
  string major;
  double gpa;
  int facultyid;
  //faculty
  string department;


  studentBST = new BST<Student*>();
  facultyBST = new BST<Faculty*>();
  undo = new GenStack<Transaction*>();

  if(facultybool && studentbool){
    //both
    facultyfile.open("facultyTable.txt");
    while(!facultyfile.eof()){
      facultyfile >> id;
      facultyfile >> name;
      facultyfile >> level;
      facultyfile >> department;

      facultyBST->insert(id,new Faculty(id,name,level,department));
    }

    studentfile.open("studentTable.txt");
    while(!studentfile.eof()){
      studentfile >> id;
      studentfile >> name;
      studentfile >> level;
      studentfile >> major;
      studentfile >> gpa;
      studentfile >> facultyid;

      studentBST->insert(id,new Student(id,name,level,major,gpa,facultyid));
    }
  }else if(facultybool){
    //only faculty
    facultyfile.open("facultyTable.txt");
    while(!facultyfile.eof()){
      facultyfile >> id;
      facultyfile >> name;
      facultyfile >> level;
      facultyfile >> department;

      facultyBST->insert(id,new Faculty(id,name,level,department));
    }

  }else if(studentbool){
    //only student
    while(!studentfile.eof()){
      studentfile >> id;
      studentfile >> name;
      studentfile >> level;
      studentfile >> major;
      studentfile >> gpa;
      studentfile >> facultyid;

      studentBST->insert(id,new Student(id,name,level,major,gpa,facultyid));
    }
  }


}

IO::~IO(){
  //delete
}

void IO::prompt(){
  int input;
  cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
  cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
  cout << "3. Find and display student information given the students id" << endl;
  cout << "4. Find and display faculty information given the faculty id" << endl;
  cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
  cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
  cout << "7. Add a new student" << endl;
  cout << "8. Delete a student given the id" << endl;
  cout << "9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member given the id." << endl;
  cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
  cout << "12. Remove an advisee from a faculty member given the ids" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;
  cin >> input;
  int id;
  string name;
  string level;
  string major;
  double gpa;
  int faculty;
  string department;
  int studentid;
  int facultyid;
  switch (input) {
    case 1:
      printStudents(studentBST->root);
      break;
    case 2:
      printFaculty(facultyBST->root);
      break;
    case 3:
      cout << "enter ID: " << endl;
      cin >> id;
      getStudent(id);
      break;
    case 4:
      cout << "enter ID: " << endl;
      cin >> id;
      getFaculty(id);
      break;
    case 5:
      cout << "enter ID: " << endl;
      cin >> id;
      getAdvisor(id);
      break;
    case 6:
      cout << "enter ID: " << endl;
      cin >> id;
      getAdvisee(id);
      break;
    case 7:
      cout << "enter ID: " << endl;
      cin >> id;
      cout << "enter name: " << endl;
      cin >> name;
      cout << "enter level: " << endl;
      cin >> level;
      cout << "enter major: " << endl;
      cin >> major;
      cout << "enter gpa: " << endl;
      cin >> gpa;
      cout << "enter faculty ID: " << endl;
      cin >> faculty;

      addStudent(id, name, level, major, gpa, faculty);
      break;
    case 8:
      cout << "enter ID: " << endl;
      cin >> id;
      deleteStudent(id);
      break;
    case 9:
      cout << "enter ID: " << endl;
      cin >> id;
      cout << "enter name: " << endl;
      cin >> name;
      cout << "enter level: " << endl;
      cin >> level;
      cout << "enter department: " << endl;
      cin >> department;
      addFaculty(id, name, level, department);
      break;
    case 10:
      cout << "enter ID: " << endl;
      cin >> id;
      deleteFaculty(id);
      break;
    case 11:
      cout << "enter student ID: " << endl;
      cin >> studentid;
      cout << "enter faculty ID: " << endl;
      cin >> facultyid;
      changeAdvisor(studentid, facultyid);
      break;
    case 12:
      //removeAdvisee(int studentid, int facultyid);
      break;
    case 13:
      rollback();
      break;
    case 14:
      break;
    default:
      cout << "invalid number... terminating program" << endl;
      break;
  }
}

void IO::printStudents(TreeNode<Student*>* node){
  if(node != NULL){
    printStudents(node->left);
    cout << node->value->getID() << ", ";
    cout << node->value->getName() << ", ";
    cout << node->value->getLevel() << ", ";
    cout << node->value->getMajor() << ", ";
    cout << node->value->getGPA() << ", ";
    cout << node->value->getFaculty() << endl;
    printStudents(node->right);
  }
}

void IO::printFaculty(TreeNode<Faculty*>* node){
  if(node != NULL){
    printFaculty(node->left);
    cout << node->value->getID() << ", ";
    cout << node->value->getName() << ", ";
    cout << node->value->getLevel() << ", ";
    cout << node->value->getDepartment() << endl;
    printFaculty(node->right);
  }
}

void IO::getStudent(int id){
  if(studentBST->searchNode(id)){
    TreeNode<Student*>* node = studentBST->root;
    while(node->key != id){
      if(id > node->key){
        node = node->right;
      }else if(id < node->key){
        node = node->left;
      }
    }
    cout << "ID: " << node->value->getID() << endl;
    cout << "Name: " << node->value->getName() << endl;
    cout << "Level: " << node->value->getLevel() << endl;
    cout << "Major: " << node->value->getMajor() << endl;
    cout << "GPA: " << node->value->getGPA() << endl;
    cout << "ID of Faculty Advisor" << node->value->getFaculty() << endl;
  }else{
    cout << "No student found" << endl;
  }
}

void IO::getFaculty(int id){
  if(facultyBST->searchNode(id)){
    TreeNode<Faculty*>* node = facultyBST->root;
    while(node->key != id){
      if(id > node->key){
        node = node->right;
      }else if(id < node->key){
        node = node->left;
      }
    }
    cout << "ID: " << node->value->getID() << endl;
    cout << "Name: " << node->value->getName() << endl;
    cout << "Level: " << node->value->getLevel() << endl;
    cout << "Department: " << node->value->getDepartment() << endl;
  }else{
    cout << "No faculty found" << endl;
  }
}

void IO::getAdvisor(int id){
  if(studentBST->searchNode(id)){
    TreeNode<Student*>* node = studentBST->root;
    while(node->key != id){
      if(id > node->key){
        node = node->right;
      }else if(id < node->key){
        node = node->left;
      }
    }
    getFaculty(node->value->getFaculty());
  }else{
    cout << "No student found" << endl;
  }
}

void IO::getAdvisee(int id){
  //code
}

void IO::addStudent(int id, string name, string level, string major, double gpa, int faculty){
  if(!studentBST->searchNode(id)){
    studentBST->insert(id, new Student(id, name, level, major, gpa, faculty));
    undo->push(new Transaction("addStudent", *studentBST, *facultyBST));
  }else{
    cout << "Student with ID \"" << id << "\" already exists" << endl;
  }
}

int IO::deleteStudent(int id){
  if(studentBST->searchNode(id)){
    studentBST->deleteNode(id);
    removeAdvisee(id);
    undo->push(new Transaction("deleteStudent", *studentBST, *facultyBST));
    return id;
  }else{
    cout << "Student with ID \"" << id << "\" did not exist" << endl;
    return -1;
  }
}

void IO::addFaculty(int id, string name, string level, string department){
  if(!facultyBST->searchNode(id)){
    facultyBST->insert(id, new Faculty(id, name, level, department));
    undo->push(new Transaction("addFaculty", *studentBST, *facultyBST));
  }else{
    cout << "Faculty with ID \"" << id << "\" already exists" << endl;
  }
}

int IO::deleteFaculty(int id){
  if(facultyBST->searchNode(id)){
    facultyBST->deleteNode(id);
    //TreeNode* curr = studentBST->root
    undo->push(new Transaction("deleteFaculty", *studentBST, *facultyBST));
    return id;
  }else{
    cout << "Faculty with ID \"" << id << "\" did not exist" << endl;
    return -1;
  }
}

void IO::changeAdvisor(int studentid, int facultyid){
  if(studentBST->searchNode(studentid)){
    TreeNode<Student*>* node = studentBST->root;
    while(node->key != studentid){
      if(studentid > node->key){
        node = node->right;
      }else if(studentid < node->key){
        node = node->left;
      }
    }

    node->value->setFaculty(facultyid);
    undo->push(new Transaction("changeAdvisor", *studentBST, *facultyBST));
  }
}

int IO::removeAdvisee(int studentid){
  //code
  return -1;
}

void IO::rollback(){
  this->studentBST = &(undo->peek()->studentBST);
  this->facultyBST = &(undo->peek()->facultyBST);
  cout << "undo " << undo->pop()->message << endl;
}
