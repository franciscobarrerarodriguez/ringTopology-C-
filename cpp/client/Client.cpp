#include "../../h/client/Client.h"
// #include <unistd.h>

using namespace std;

Client::Client(string ip, int port){
	this->ip = ip;
	this->port = port;
	this->socket_server = socket(PF_INET, SOCK_STREAM,0);
	this->state = 0;
	this->created = false;
};

int Client::initializeClient(){
	if (this->socket_server == INVALID_SOCKET){
		return -1;
	} else{
		this->server_address.sin_family = AF_INET;
		this->server_address.sin_addr.s_addr = inet_addr(this->getIp().c_str());
		this->server_address.sin_port = htons(this->getPort());
		memset(&this->server_address.sin_zero, 0, sizeof(this->server_address.sin_zero));
		return 0;
	}
};

int Client::connectClient(){
	if (connect(this->socket_server, (struct sockaddr *)&this->server_address, sizeof(this->server_address)) == INVALID_SOCKET){
		return -1;
	}else{
		return 0;
	}
};

int Client::sendMessage(){

if(this->leftSimpleQueue->isEmpty() == true){
	std::cout << "/*  esta vacia */" << std::endl;
}else{
	std::cout << "/* no esta vacia */" << std::endl;
}
//http://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault
// Message aux = this->leftSimpleQueue->push();
// aux.setIp("fdsgsdf");
//cout << auxgetIp() << endl;
	// Message auxiliar = this->leftSimpleQueue->push();
	// cout << auxiliar.getIp() << endl;
	// 1. Parse a JSON string into DOM.
	// const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	// Document d;
	// d.Parse(json);
	// // 2. Modify it by DOM.
	// Value& s = d["stars"];
	// s.SetInt(s.GetInt() + 1);
	// // 3. Stringify the DOM
	// StringBuffer buffer;
	// Writer<StringBuffer> writer(buffer);
	// d.Accept(writer);
	// // Output {"project":"rapidjson","stars":11}
	// cout << buffer.GetString() << endl;
	// return 0;
	// int s = 0;
	// if(this->created == false){
	// 	const char *msg = NULL;
	// 	string message = "Hola maldito computador";
	// 	msg = message.c_str();
	// 	int s = send(this->socket_server, msg, strlen(msg), 0);
	// 	if(s == INVALID_SOCKET){
	// 		return INVALID_SOCKET;
	// 	}else{
	// 		this->created = true;
	// 		return s;
	// 	}
	// }
	return 1;
};

void Client::create(){
	this->leftSimpleQueue->pop(this->message = new Message("hola soy un gordito"));
	this->created = true;
}

/* Getters & Setters */
void Client::setPort(int port){
	this->port = port;
};

int Client::getPort(){
	return this->port;
};

void Client::setIp(string ip){
	this->ip = ip;
};

string Client::getIp(){
	return this->ip;
};

void Client::setSocket_server(int socket_server){
	this->socket_server = socket_server;
};

int Client::getSocket_server(){
	return this->socket_server;
};

void Client::setState(int state){
	this->state = state;
};

int Client::getState(){
	return this->state;
};

void Client::setMessage(Message *message){
	this->message = message;
};

Message Client::getMessage(){
	return *this->message;
};

void Client::setLeftSimpleQueue(SimpleQueue *simpleQueue){
	this->leftSimpleQueue = simpleQueue;
};

SimpleQueue Client::getLeftSimpleQueue(){
	return *this->leftSimpleQueue;
};

void Client::setRightSimpleQueue(SimpleQueue *simpleQueue){
	this->rightSimpleQueue = simpleQueue;
};

SimpleQueue Client::getRightSimpleQueue(){
	return *this->rightSimpleQueue;
};

void Client::setCreated(bool created){
	this->created = created;
};
bool Client::isCreated(){
	return this->created;
};
