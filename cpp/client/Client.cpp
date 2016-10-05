#include "../../h/client/Client.h"

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

/* http://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault
https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Librer%C3%ADa_Est%C3%A1ndar_de_Plantillas/Colas
http://www.cplusplus.com/reference/queue/queue/pop/
http://www.cplusplus.com/reference/queue/queue/push/ */
int Client::sendMessage(){
	int answer = 0;
	Message *auxiliarMessage = this->leftSimpleQueue->top();
	// PrepareJson
	this->stringStream.clear() ;
	this->stringStream<< "{\"ip\":\""<< auxiliarMessage->getIp() <<"\",\"stars\":10}";
	string auxiliarstring = this->stringStream.str();
	// 1. Parse a JSON string into DOM.
	const char *json = auxiliarstring.c_str();
	answer = send(this->socket_server, json, strlen(json), 0);
	if(answer == INVALID_SOCKET){
		answer = INVALID_SOCKET;
	}else{
		// Cuando se envia el mensaje es removido de Queue.
		this->leftSimpleQueue->pop();
		answer = 0;
		/*Aqui wait */
		this->msleep(5000);
	}
	return answer;
};

void Client::create(){
	cout << "/* Escriba un mensaje : */" << endl;
	string algo;
	cin >> algo;
	this->leftSimpleQueue->push(this->message = new Message(algo));
	this->created = true;
}

int Client::msleep(unsigned long milisec){
	struct timespec req={0};
	time_t sec=(int)(milisec/1000);
	milisec=milisec-(sec*1000);
	req.tv_sec=sec;
	req.tv_nsec=milisec*1000000L;
	while(nanosleep(&req,&req)==-1)
	continue;
	return 1;
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

void Client::setLeftPriorityQueue(priority_queue<Message*> *priority_queue){
	this->leftSimpleQueue = priority_queue;
};

priority_queue<Message*> Client::getLeftPriorityQueue(){
	return *this->leftSimpleQueue;
};

void Client::setRightPriorityQueue(priority_queue<Message*> *priority_queue){
	this->rightSimpleQueue = priority_queue;
};

priority_queue<Message*> Client::getRightPriorityQueue(){
	return *this->rightSimpleQueue;
};

void Client::setCreated(bool created){
	this->created = created;
};
bool Client::isCreated(){
	return this->created;
};
