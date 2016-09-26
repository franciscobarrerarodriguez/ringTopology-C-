#include<iostream>
#include "../h/Node.h"

int main(){

  string ip ="192.168.43.243";
  int port = 1233;

  Node *node = new Node(ip, port);
  cout << node->getIp() << endl;
  cout << node->getPort() << endl;

  return 0;
}
