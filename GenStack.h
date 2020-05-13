#include <iostream>
using namespace std;

template<typename T>
class GenStack
{
  public:
    GenStack(); //default constructor
    GenStack(int maxSize);//overload constructor if we want to pass in a size
    ~GenStack(); //destructor

    //functions
    void push(T data); //push a character onto the stack
    T pop(); //just returns the top element, and remove it.

    //helper functions
    bool isFull(); //check if its full
    bool isEmpty(); //check if its empty
    T peek(); //returns value of top element

    //variables
    int mSize; //max size of my stack
    int top; //variable to keep track of index reprisenting the top of our stack
    T *myArray; // declaring a pointer that will be initialized to a place in memory at run time.
                  //from this we can find any element bc arrays are contiguous

};

//dafault constructor
template<typename T>
GenStack<T>::GenStack()
{
  //init array to heap b/c we allocate this memory dynamically
  myArray = new T[128];
  mSize = 128;
  top = -1;

}

//overload constructor
template<typename T>
GenStack<T>::GenStack(int maxSize)
{
  //init array to heap b/c we allocate this memory dynamically
  myArray = new T[maxSize];
  mSize = maxSize;
  top = -1;

}

template<typename T>
GenStack<T>::~GenStack()
{
  //let you figure this out
  delete myArray;
}

template<typename T>
void GenStack<T>::push(T data)
{
  //ALWAYS check if full before inserting
  if(!isFull()){
    //increment the index where we're at, or the "top" and settng it equal to the data
    myArray[++top] = data;
  }
}

template<typename T>
T GenStack<T>::pop()
{
  //ALWAYS check if emmpty before proceeding
  if(!isEmpty()){
    //return myArray value of the current top, then decrement it after returning to set a new top
    return myArray[top--];
  }

  exit(0); //exception handling
}

template<typename T>
T GenStack<T>::peek()
{
  //check if emmpty before proceeding
  if(!isEmpty()){
    //just returns it but doesn't change the top value or "remove it"
    return myArray[top];
  }
  return '\0'; //null character
}

template<typename T>
bool GenStack<T>::isFull()
{
  return (top==mSize-1);
}

template<typename T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}
