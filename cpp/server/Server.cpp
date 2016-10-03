#include "../../h/server/Server.h"

Server::Server(int port){
  this->port = port;
  this->ip = socket(AF_INET, SOCK_DGRAM, 0);
  this->iFREQ.ifr_addr.sa_family = AF_INET;
  strncpy(this->iFREQ.ifr_name, "eth0", IFNAMSIZ-1);
  ioctl(this->ip, SIOCGIFADDR, &this->iFREQ);
  close(this->ip);
  this->address=(inet_ntoa(((struct sockaddr_in *)&this->iFREQ.ifr_addr)->sin_addr));
  //*********************************************************************************
  this->flag = true;
  this->state = 0;
};

int Server::initializeServer(){
  this->socket_server = socket(PF_INET, SOCK_STREAM, 0);
  if (this->socket_server == INVALID_SOCKET){
    return -1;
  }else{
    this->server_address.sin_family=AF_INET;
    this->server_address.sin_addr.s_addr=inet_addr(this->address.c_str());
    this->server_address.sin_port=htons(this->port);
    return 0;
  }
};

int Server::listenClient(){
  if(bind(this->socket_server, (sockaddr *)&this->server_address,(socklen_t)sizeof(this->server_address)) < 0){
    return -1;
  }else{
    // Máximo 1 puerto de conexion.
    listen(this->socket_server ,1);
    return 0;
  }
};

int Server::acceptClient(){
  unsigned int lenght = sizeof(this->client);
  this->socket_conn = accept(this->socket_server, (struct sockaddr*)&this->client, &lenght);
  if(this->socket_conn == INVALID_SOCKET){
    return -1;
  }else{
    return this->socket_conn;
  }
};

int Server::receiveMessage(){
  char message[10000] = "";
  int recieve = recv(this->socket_conn, message, sizeof(message), 0);
  if(recieve == -1){
    cout << "/* No se recibio mensaje */" << endl;
  }else{
    if(message[0]){
      cout << message << endl;
    }
  }
  return recieve;
};

/* Getters & Setters */
void Server::setFlag(bool flag){
  this->flag = flag;
};

bool Server::getFlag(){
  return this->flag;
};

void Server::setState(int state){
  this->state = state;
};

int Server::getState(){
  return this->state;
};

void Server::setLeftPriorityQueue(priority_queue<Message*> *priority_queue){
  this->leftSimpleQueue = priority_queue;
};

priority_queue<Message*> Server::getLeftPriorityQueue(){
  return *this->leftSimpleQueue;
};

void Server::setRightPriorityQueue(priority_queue<Message*> *priority_queue){
  this->rightSimpleQueue = priority_queue;
};

priority_queue<Message*> Server::getRightPriorityQueue(){
  return *this->rightSimpleQueue;
};
