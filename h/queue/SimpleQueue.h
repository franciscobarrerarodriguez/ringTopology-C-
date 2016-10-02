#ifndef SIMPLEQUEUE_H
#define SIMPLEQUEUE_H

#include "SimpleList.h"

class SimpleQueue {

public:

  SimpleQueue();
  SimpleQueue(int capacity);

  /* Pop to add. */
  void pop(Message *info);
  /* Push to remove. */
  Message push();
  Message top();
  bool isEmpty();
  bool isFull();

  SimpleQueue(const SimpleQueue& orig);
  virtual ~SimpleQueue();

private:

  SimpleList *list;
  int capacity;
};
#endif /* SIMPLEQUEUE_H */
