#include <string.h>
#include<iostream>

#include "../h/stack.h"

template <class T>
stack<T>::stack(){
this.top = NULL;
}

template <class T>
bool stack<T>::isEmpty(){
	return this.top == NULL;
}

template <class T>
void stack<T>::push(T *information){
	this.top = new nodeStack<T>(information, this.top);
}

template <class T>
T *stack<T>::pop(){
	if(this.top == NULL){
		return NULL;
	}else{
		T aux = this.top.getInformation();
		this.top = this.top.getNext();
		return aux;
	}

}
