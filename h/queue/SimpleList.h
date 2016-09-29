#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include "SimpleNode.h"

class SimpleList {

public:
  SimpleList();
  bool addHead(Message *info);
  void addLast(Message *info);
  bool erase(int position);
  bool isEmpty();
  Message *getInfo(int position);
  SimpleNode *getHead();
  void setHead(SimpleNode *head);
  int getSize();


  SimpleList(const SimpleList& orig);
  virtual ~SimpleList();

private:
  SimpleNode *head;
  int size;
};
#endif /* SIMPLELIST_H */
