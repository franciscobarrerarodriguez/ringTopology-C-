#include "actions/ServerActions.h"
#include "actions/ClientActions.h"
#include "actions/MessageActions.h"
#include "thread/GenericThread.h"
//#include "queue/SimpleQueue.h"
#include <queue>
#include<iostream>
#include<string.h>

using namespace std;

class Node {

public:

	Node(string, int serverPort, int clientPort);
	~Node();

	void setServerPort(int);
	int getServerPort();

	void setClientPort(int);
	int getClientPort();

	void setIp(string ip);
	string getIp();

private:

	int serverPort;
	int clientPort;

	string ip;

	ServerActions *serverActions;
	ClientActions *clientActions;
	MessageActions *messageActions;

	GenericThread *serverThread;
	GenericThread *clientThread;
	GenericThread *messageThread;

	Client *client;
	Server *server;

	/* Stack de izquierda a derecha */
	queue<string> *leftSimpleQueue;
	queue<string> *rightSimpleQueue;
};
