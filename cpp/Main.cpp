#include<iostream>
#include "../h/Node.h"

int main(){

  string ip ="192.168.43.243";
  int serverPort = 1233;
  int clientPort = 1234;

  Node *node = new Node(ip, serverPort, clientPort);
  cout << node->getIp() << endl;
  cout << node->getServerPort() << endl;
  cout << node->getClientPort() << endl;

  return 0;
}
