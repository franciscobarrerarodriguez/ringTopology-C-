#include "../h/Node.h"

using namespace std;

Node::Node(string ip, int serverPort, int clientPort){
  this->ip = ip;
  this->serverPort = serverPort;
  this->clientPort = clientPort;

  /* Creacion de dos Queue, una en sentido izquierda a derecha,
  la otra de derecha izquierda*/
  this->leftSimpleQueue = new priority_queue<string>();
  this->rightSimpleQueue = new priority_queue<string>();

  this->server = new Server(this->serverPort);

  this->server->setLeftPriorityQueue(this->leftSimpleQueue);
  this->server->setRightPriorityQueue(this->rightSimpleQueue);

  this->serverActions = new ServerActions(this->server);
  this->serverThread = new GenericThread(this->serverActions);
  this->serverThread->createThread();

  this->client = new Client(this->ip, this->clientPort);

  this->client->setLeftPriorityQueue(this->leftSimpleQueue);
  this->client->setRightPriorityQueue(this->rightSimpleQueue);

  this->clientActions = new ClientActions(this->client);
  this->clientThread = new GenericThread(this->clientActions);
  this->clientThread->createThread();

  this->messageActions = new MessageActions(this->client);
  this->messageThread = new GenericThread(this->messageActions);
  this->messageThread->createThread();
  
  /* No permite que el programa se termine de ejecutar*/
  while(true);
}

/* Recordar estos hilos que nos faltan */
//void Node::threadThree(){}
//void Node::threadFour(){}

/* Getters & Setters */
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
