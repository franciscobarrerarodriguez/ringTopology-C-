#ifndef CLIENT_H_
#define CLIENT_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <queue>

// Lib rapidjson ----------------------------------------------------
#include "../lib/rapidjson/include/rapidjson/document.h"
#include "../lib/rapidjson/include/rapidjson/writer.h"
#include "../lib/rapidjson/include/rapidjson/stringbuffer.h"
// Lib rapidjson ----------------------------------------------------

#define INVALID_SOCKET -1

using namespace std;
using namespace rapidjson;

/*class Client*/
class Client{

public:

	Client(string, int);
	~Client();

	int initializeClient();
	int connectClient();
	int sendMessage();
	void create(string);

	void msleep(unsigned long);

	void setPort(int port);
	int getPort();

	void setIp(string ip);
	string getIp();

	void setSocket_server(int socket_server);
	int getSocket_server();

	void setState(int state);
	int getState();

	void setLeftQueue(queue<string> *queue);
	queue<string> getLeftQueue();

	void setRightQueue(queue<string> *queue);
	queue<string> getRightQueue();

	void setCreated(bool created);
	bool isCreated();

private:

	int port;
	int socket_server;

	/* Estado 0 para configuracion, estado 1 para enviar. */
	int state;

	string ip;

	struct sockaddr_in server_address;

	/* Este es el mensaje que se va a enviar */

	/* Stack de izquierda a derecha */
	queue<string> *leftSimpleQueue;
	queue<string> *rightSimpleQueue;

	bool created;

	stringstream stringStream;
};
#endif /* CLIENT_H_ */
