#include "../h/Node.h"
//#include "ot/io/DataOutputStream.h"
//#include "ot/io/DataInputStream.h"
// #include <string.h>
// #include "string.h"
//#include <pthread.h>
//#include <sys/types.h>
//#include <sys/socket.h>

using namespace std;

Node::Node(string ip, int serverPort, int clientPort){
  this->ip = ip;
  this->serverPort = serverPort;
  this->clientPort = clientPort;


  /* Creacion de dos Queue...*/
  this->rightSimpleQueue = new SimpleQueue();
  this->leftSimpleQueue = new SimpleQueue();

  this->server = new Server(this->serverPort);

  this->server->setLeftSimpleQueue(this->leftSimpleQueue);
  this->server->setRightSimpleQueue(this->rightSimpleQueue);

  this->serverActions = new ServerActions(this->server);
  this->serverThread = new GenericThread(this->serverActions);
  this->serverThread->createThread();

  this->client = new Client(this->ip, this->clientPort);

  this->client->setLeftSimpleQueue(this->leftSimpleQueue);
  this->client->setRightSimpleQueue(this->rightSimpleQueue);

  this->clientActions = new ClientActions(this->client);
  this->clientThread = new GenericThread(this->clientActions);
  this->clientThread->createThread();

  /* No permite que el programa se termine de ejecutar*/
  while(true);
}

/* Recordar estos hilos que nos faltan */
//void Node::threadThree(){}
//void Node::threadFour(){}

void Node::setServerPort(int port){
  this->serverPort = port;
};

int Node::getServerPort(){
  return  this->serverPort;
};

void Node::setClientPort(int port){
  this->clientPort = port;
};

int Node::getClientPort(){
  return  this->clientPort;
};

void Node::setIp(string ip){
  this->ip = ip;
};

string Node::getIp(){
  return this->ip;
};
