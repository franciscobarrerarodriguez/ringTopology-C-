#include "../../h/queue/SimpleQueue.h"

SimpleQueue::SimpleQueue() {
  list = new SimpleList();
}

SimpleQueue::SimpleQueue(int capacity) {
  list = new SimpleList();
  this->capacity = capacity;
}

SimpleQueue::SimpleQueue(const SimpleQueue& orig) {
}

SimpleQueue::~SimpleQueue() {
}

void SimpleQueue::pop(Message *info) {
  if (capacity > list->getSize()) {
    list->addLast(info);
  }
}

Message SimpleQueue::push() {
  Message *aux = list->getInfo(0);
  list->erase(0);
  return *aux;
}

Message SimpleQueue::top() {
  return *list->getInfo(0);
}

bool SimpleQueue::isEmpty() {
  if (list->isEmpty()) {
    return true;
  }
  return false;
}

bool SimpleQueue::isFull() {
  if (list->getSize() == capacity) {
    return true;
  }
  return false;
}
