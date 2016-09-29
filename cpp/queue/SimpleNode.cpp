#include "../../h/queue/SimpleNode.h"

#include <stddef.h>

SimpleNode::SimpleNode() {
}

SimpleNode::SimpleNode(Message *info){
    setInfo(info);
    setNext(NULL);
}

SimpleNode::SimpleNode(const SimpleNode& orig) {
}

SimpleNode::~SimpleNode() {
}

void SimpleNode::setInfo(Message *info){
    this->info = info;
}

Message *SimpleNode::getInfo(){
    return this->info;
}

void SimpleNode::setNext(SimpleNode *next){
    this->next = next;
}

SimpleNode *SimpleNode::getNext(){
    return this->next;
}

//template <class T> SimpleNode *SimpleNode<T>::getNext(){
//    return this->next;
//}
