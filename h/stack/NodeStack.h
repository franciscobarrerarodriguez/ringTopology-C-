#include<iostream>

template <class T>
class NodeStack{

public:

	//	NodeStack(T*);
	NodeStack(T *information);
	NodeStack(T *information, NodeStack<T> *next);
	NodeStack(T *information, NodeStack<T> *next, NodeStack<T> *previous);
	T* getInformation();
	void setInformation(T* information);
	NodeStack<T> *getNext();
	void setNext(NodeStack<T> *next);
	NodeStack<T> *getPrevious();
	void setPrevious(NodeStack<T> *previous);

private:

	T information;
	NodeStack<T>* next;
	NodeStack<T>* previous;
};
