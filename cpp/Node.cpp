#include "../h/Node.h"
//#include "ot/io/DataOutputStream.h"
//#include "ot/io/DataInputStream.h"
// #include <string.h>
// #include "string.h"
//#include <pthread.h>
//#include <sys/types.h>
//#include <sys/socket.h>

using namespace std;

Node::Node(string ip, int port){
  this->ip = ip;
  this->port = port;
  this->server = new Server(this->port);
  this->listen = new Listen();
  // if(this->server->initializeServer() == INVALID_SOCKET){
  //   cout<<"Servidor no iniciado"<<endl;
  // }else{
  //   cout << "Servidor iniciado" << endl;
  //   if(this->server->listenClient() == INVALID_SOCKET){
  //     cout << "Bind fallo" << endl;
  //   }else{
  //     std::cout << "Bind funcionando, esperando cliente . . ." << std::endl;
  //     while(this->server->getFlag() == true){
	// 			if(this->server->acceptClient() == INVALID_SOCKET){
	// 					this->server->setFlag(false);
	// 					while (true);
	// 			}else{
	// 				cout<<"Cliente aceptado"<<endl;
	// 			}
	// 		}
  //   }
  // }
}


//void Node::show(){

//}
//void Node::accept(){

//}

//void Node::listen(){

//}

//void Node::send(){

//}

//void Node::connect(){

//}

//void Node::threadOne(){}

//void Node::threadTwo(){}

//void Node::threadThree(){}

//void Node::threadFour(){}

void Node::setPort(int port){
  this->port = port;
};

int Node::getPort(){
  return  this->port;
};

void Node::setIp(string ip){
  this->ip = ip;
};

string Node::getIp(){
  return this->ip;
};

// void Node::setClient(Client *client){
// this->client = client;
// };

// Client Node::getClient(){
// return this->*client;
// };
