#include "../../h/stack/NodeStack.h"

template <class T>
NodeStack<T>::NodeStack(T *information){
  this.information= information;
  this.next = NULL;
  this.previous = NULL;
}

template <class T>
NodeStack<T>::NodeStack(T *information, NodeStack<T> *next){
  this.information = information;
  this.next = next;
  this.previous = NULL;
}

template <class T>
NodeStack<T>::NodeStack(T *information, NodeStack<T> *next, NodeStack<T> *previous){
  this.information = information;
  this.next = next;
  this.previous = previous;
}

template<class T>
T* NodeStack<T>::getInformation(){
  return information;
}

template<class T>
void NodeStack<T>::setInformation(T* information){
  this.information = information;
}

template<class T>
NodeStack<T>* NodeStack<T>::getNext(){
  return next;
}

template<class T>
void NodeStack<T>::setNext(NodeStack<T> *next){
  this.next = next;
}

template<class T>
NodeStack<T>* NodeStack<T>::getPrevious(){
  return previous;
}

template<class T>
void NodeStack<T>::setPrevious(NodeStack<T> *previous){
  this.previous = previous;
}
