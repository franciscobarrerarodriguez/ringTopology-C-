#include "actions/ServerActions.h"
#include "actions/ClientActions.h"
#include "thread/GenericThread.h"

#include<iostream>
#include<string.h>

using namespace std;

class Node {

public:

	Node(string, int serverPort, int clientPort);
	~Node();

	//void accept();
	//void listen();
	//void send();
	//void connect();
	//void threadOne();
	//void threadTwo();
	//void threadThree();
	//void threadFour();
	int getServerPort();
	void setServerPort(int);
	int getClientPort();
	void setClientPort(int);
	string getIp();
	void setIp(string ip);
	// void setClient(Client *client);
	// Client getClient();
	//void show();
	//private:
	//stack stackLeft;
	//stack stackRight;

private:

	int serverPort;
	int clientPort;

	string ip;

	ServerActions *serverActions;
	ClientActions *clientActions;

	GenericThread *serverThread;
	GenericThread *clientThread;

	Client *client;
	Server *server;
};
