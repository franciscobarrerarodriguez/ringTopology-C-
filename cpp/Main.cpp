#include<iostream>
#include "../h/Node.h"

int main(){

  //string ip ="192.168.43.243";
  //int serverPort = 1233;
  //int clientPort = 1234;
  string ip;
  int serverPort;
  int clientPort;

  cout<<"Ingresar ip a la que se va a conectar: "<<endl;
  cin>>ip;
  std::cout << "Ingresar puerto para el servidor: " << std::endl;
  cin>>serverPort;
  std::cout << "Ingresar puerto del cliente: " << std::endl;
  cin>>clientPort;

  Node *node = new Node(ip, serverPort, clientPort);
  //  cout << node->getIp() << endl;
  //  cout << node->getServerPort() << endl;
  //  cout << node->getClientPort() << endl;

  return 0;
}
