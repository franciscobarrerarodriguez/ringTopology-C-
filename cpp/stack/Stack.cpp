#include "../../h/stack/Stack.h"

template <class T>
Stack<T>::Stack(){
	this.top = NULL;
}

template <class T>
bool Stack<T>::isEmpty(){
	return this.top == NULL;
}

template <class T>
void Stack<T>::push(T *information){
	this.top = new NodeStack<T>(information, this.top);
}

template <class T>
T *Stack<T>::pop(){
	if(this.top == NULL){
		return NULL;
	}else{
		T aux = this.top.getInformation();
		this.top = this.top.getNext();
		return aux;
	}

}
