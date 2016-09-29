#ifndef SIMPLENODE_H
#define SIMPLENODE_H

#include "../message/Message.h"

class SimpleNode {

public:
  SimpleNode();
  SimpleNode(const SimpleNode& orig);
  SimpleNode(Message *info);
  ~SimpleNode();
  void setInfo(Message *info);
  Message *getInfo();
  void setNext(SimpleNode *next);
  SimpleNode *getNext();

private:
  Message *info;
  SimpleNode *next;

};
#endif /* SIMPLENODE_H */
