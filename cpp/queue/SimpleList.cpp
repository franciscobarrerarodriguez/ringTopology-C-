#include "../../h/queue/SimpleList.h"

SimpleList::SimpleList() {
}

SimpleList::SimpleList(const SimpleList& orig) {
}

SimpleList::~SimpleList() {
}

bool SimpleList::addHead(Message* info){
  SimpleNode *newNode = new SimpleNode(info);
  if (!isEmpty()) {
    newNode->setNext(head);
    size++;
  }
  head = newNode;
  return false;
}

void SimpleList::addLast(Message* info){
  if (isEmpty()) {
    head = new SimpleNode(info);
  } else {
    SimpleNode *auxLast = head;
    while (auxLast->getNext() != NULL){
      auxLast = auxLast->getNext();
    }
    auxLast->setNext(new SimpleNode(info));
    size++;
  }
}

bool SimpleList::erase(int position){
  if (position >= 0 && position < getSize()){
    if (position == 0) {
      head = head->getNext();
    } else {
      SimpleNode *aux = head;
      for (int i = 0; i < position; i++){
        aux = aux->getNext();
      }
      SimpleNode *next = aux->getNext();
      aux->setNext(next->getNext());
    }
  }
  return true;
}

bool SimpleList::isEmpty(){
  return this->head == NULL;
}

Message *SimpleList::getInfo(int position){
  int count = 0;
  if (!isEmpty()){
    if(position == 0) {
      return head->getInfo();
    } else {
      SimpleNode *aux = head;

      while (aux->getNext() != NULL){
        aux = aux->getNext();
        count++;
        if (count == position){
          return aux->getInfo();
        }
      }
    }
  }
  return NULL;
}

SimpleNode *SimpleList::getHead(){
  return head;
}

void SimpleList::setHead(SimpleNode *head){
  this->head = head;
}

int SimpleList::getSize(){
  return size;
}
