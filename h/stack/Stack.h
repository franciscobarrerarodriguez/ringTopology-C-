#include "NodeStack.h"

#include <string.h>
#include<iostream>

template <class T>
class Stack{
public:

  Stack();
  bool isEmpty();
  void push(T*);
  T* pop();

private:

  NodeStack<T> *top;
};
