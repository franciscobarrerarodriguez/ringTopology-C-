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
  char json[10000] = "";
  if((recv(this->socket_conn, json, sizeof(json), 0)) != INVALID_SOCKET){
    this->stringStream.str("");
    this->stringStream << json;
    string auxiliarstring = this->stringStream.str();
    this->leftSimpleQueue->push(auxiliarstring);
    /* Limpiar la pantalla para mostrar el mensaje entrante. */
		system("/usr/bin/clear");
    cout << this->leftSimpleQueue->front() << endl;
    return 0;
  }else{
    return INVALID_SOCKET;
  }
};

int Server::writeRight(){
  /* PrepareJson */
	this->stringStream.str("");
	this->stringStream << this->rightSimpleQueue->front();
	string auxiliarstring = this->stringStream.str();
	const char *json = auxiliarstring.c_str();
	if((send(this->socket_conn, json, strlen(json), 0)) != INVALID_SOCKET){
		//	cout << "auxiliarstring: "<< auxiliarstring << endl;
		this->rightSimpleQueue->pop();
		return 0;
	}else{
		return INVALID_SOCKET;
	}
};

void Server::msleep(unsigned long milisec){
	struct timespec req={0};
	time_t sec=(int)(milisec/1000);
	milisec=milisec-(sec*1000);
	req.tv_sec=sec;
	req.tv_nsec=milisec*1000000L;
	while(nanosleep(&req,&req)==-1)
	continue;
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

void Server::setLeftQueue(queue<string> *queue){
  this->leftSimpleQueue = queue;
};

queue<string> Server::getLeftQueue(){
  return *this->leftSimpleQueue;
};

void Server::setRightQueue(queue<string> *queue){
  this->rightSimpleQueue = queue;
};

queue<string> Server::getRightQueue(){
  return *this->rightSimpleQueue;
};
