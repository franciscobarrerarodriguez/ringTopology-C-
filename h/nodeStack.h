#include<iostream>

template <class T>
class nodeStack{
	public:

//	NodeStack(T*);
	nodeStack(T *information);
	nodeStack(T *information, nodeStack<T> *next);
	nodeStack(T *information, nodeStack<T> *next, nodeStack<T> *previous);
	T* getInformation();
	void setInformation(T* information);
	nodeStack<T> *getNext();
	void setNext(nodeStack<T> *next);
	nodeStack<T> *getPrevious();
	void setPrevious(nodeStack<T> *previous);

	private:
	T information;
	nodeStack<T>* next;
	nodeStack<T>* previous;

};
