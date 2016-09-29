#include "../queue/SimpleQueue.h"
#include "../message/Message.h"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

#define INVALID_SOCKET -1

using namespace std;

/*class Client*/
class Client{

public:

	Client(string, int);
	~Client();

	int initializeClient();
	int connectClient();

	void setPort(int port);
	int getPort();

	void setIp(string ip);
	string getIp();

	void setSocket_server(int socket_server);
	int getSocket_server();

	void setState(int state);
	int getState();

	void setMessage(Message *message);
	Message getMessage();

	void setLeftSimpleQueue(SimpleQueue *simpleQueue);
  SimpleQueue getLeftSimpleQueue();

  void setRightSimpleQueue(SimpleQueue *simpleQueue);
  SimpleQueue getRightSimpleQueue();

private:

	int port;
	int socket_server;

	/* Estado 0 para configuracion, estado 1 para enviar. */
	int state;

	string ip;

	struct sockaddr_in server_address;

	/* Este es el mensaje que se va a enviar */
	Message *message;
	/* Stack de izquierda a derecha */
	SimpleQueue *leftSimpleQueue;
  SimpleQueue *rightSimpleQueue;
};
