#include<iostream>

#include "nodeStack.h"

template <class T>

class stack{
public:
stack();
bool isEmpty();
void push(T*);
T* pop();

private:
nodeStack<T> *top;

};
