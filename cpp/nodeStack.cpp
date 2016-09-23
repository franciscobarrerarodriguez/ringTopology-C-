#include "../h/nodeStack.h"
#include <iostream>
template <class T>
nodeStack<T>::nodeStack(T *information){
this.information= information;
this.next = NULL;
this.previous = NULL;
}

template <class T>
nodeStack<T>::nodeStack(T *information, nodeStack<T> *next){
this.information = information;
this.next = next;
this.previous = NULL;
}

template <class T>
nodeStack<T>::nodeStack(T *information, nodeStack<T> *next, nodeStack<T> *previous){
this.information = information;
this.next = next;
this.previous = previous;
}

template<class T>
T* nodeStack<T>::getInformation(){
return information;
}

template<class T>
void nodeStack<T>::setInformation(T* information){
this.information = information;
}

template<class T>
nodeStack<T>* nodeStack<T>::getNext(){
return next;
}

template<class T>
void nodeStack<T>::setNext(nodeStack<T> *next){
this.next = next;
}

template<class T>
nodeStack<T>* nodeStack<T>::getPrevious(){
return previous;
}

template<class T>
void nodeStack<T>::setPrevious(nodeStack<T> *previous){
this.previous = previous;
}
