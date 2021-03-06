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
		return INVALID_SOCKET;
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
		return INVALID_SOCKET;
	}else{
		return 0;
	}
};

/* http://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault
https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Librer%C3%ADa_Est%C3%A1ndar_de_Plantillas/Colas
http://www.cplusplus.com/reference/queue/queue/pop/
http://www.cplusplus.com/reference/queue/queue/push/ */
int Client::sendMessage(){
	/* PrepareJson */
	this->stringStream.str("");
	this->stringStream << this->leftSimpleQueue->front();
	string auxiliarstring = this->stringStream.str();
	const char *json = auxiliarstring.c_str();
	if((send(this->socket_server, json, strlen(json), 0)) != INVALID_SOCKET){
		//	cout << "auxiliarstring: "<< auxiliarstring << endl;
		this->leftSimpleQueue->pop();
		return 0;
	}else{
		return INVALID_SOCKET;
	}
};

int Client::listenRight(){
	char json[10000] = "";
	if((recv(this->socket_server, json, sizeof(json), 0)) != INVALID_SOCKET){
		this->stringStream.str("");
		this->stringStream << json;
		string auxiliarstring = this->stringStream.str();
		this->rightSimpleQueue->push(auxiliarstring);
		/* Limpiar la pantalla para mostrar el mensaje entrante. */
		system("/usr/bin/clear");
		cout << this->rightSimpleQueue->front() << endl;
		return 0;
	}else{
		return INVALID_SOCKET;
	}
}

void Client::create(string option){
	stringstream auxiliarStringStream;
	if((option == "l") || (option == "L") ){
		auxiliarStringStream << "{\"ip\":\"" << this->ownIp() << "\",\"name\""<< this->getUserName() <<"\":\",\"orientation\":l}";
		string own;
		auxiliarStringStream >> own;
		this->leftSimpleQueue->push(own);
	}else if((option == "r") || (option == "R")){
		auxiliarStringStream << "{\"ip\":\"" << this->ownIp() << "\",\"name\""<< this->getUserName() <<"\":\",\"orientation\":r}";
		string own;
		auxiliarStringStream >> own;
		this->rightSimpleQueue->push(own);
	}
	this->created = true;
};

string Client::ownIp(){
	const char* google_dns_server = "8.8.8.8";
	int dns_port = 53;
	struct sockaddr_in serv;
	int sock = socket ( AF_INET, SOCK_DGRAM, 0);
	//Socket could not be created
	if(sock < 0){
		perror("Socket error");
	}
	memset( &serv, 0, sizeof(serv) );
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = inet_addr( google_dns_server );
	serv.sin_port = htons( dns_port );
	int err = connect( sock , (const struct sockaddr*) &serv , sizeof(serv) );
	struct sockaddr_in name;
	socklen_t namelen = sizeof(name);
	err = getsockname(sock, (struct sockaddr*) &name, &namelen);
	char buffer[100];
	const char* p = inet_ntop(AF_INET, &name.sin_addr, buffer, 100);
	if(p != NULL){
		printf("Local ip is : %s \n" , buffer);
	}else{
	//Some error
		printf ("Error number : %d . Error message : %s \n" , errno , strerror(errno));
	}
	close(sock);
	/**----------------------------------*/
	stringstream ss;
	string ownIp;
	ss << buffer;
	ss >> ownIp;
	return ownIp;
};

string Client::getUserName(){
	/* Obtiene el nombre del equipo. */
	char * user_name = getenv("LOGNAME");
	stringstream ss;
	string userNameString;
	ss << user_name;
	ss >> userNameString;
	return userNameString;
};

void Client::msleep(unsigned long milisec){
	struct timespec req={0};
	time_t sec=(int)(milisec/1000);
	milisec=milisec-(sec*1000);
	req.tv_sec=sec;
	req.tv_nsec=milisec*1000000L;
	while(nanosleep(&req,&req)==-1)
	continue;
};

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

void Client::setSocket_conn(int socket_conn){
	this->socket_conn = socket_conn;
};

int Client::getSocket_conn(){
	return this->socket_conn;
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

void Client::setLeftQueue(queue<string> *queue){
	this->leftSimpleQueue = queue;
};

queue<string> Client::getLeftQueue(){
	return *this->leftSimpleQueue;
};

void Client::setRightQueue(queue<string> *queue){
	this->rightSimpleQueue = queue;
};

queue<string> Client::getRightQueue(){
	return *this->rightSimpleQueue;
};

void Client::setCreated(bool created){
	this->created = created;
};
bool Client::isCreated(){
	return this->created;
};
