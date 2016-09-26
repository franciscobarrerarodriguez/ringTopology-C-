//Borrar esto despues
#include "client/Client.h"
// #include "server/Server.h"
#include "actions/ServerActions.h"
#include "thread/GenericThread.h"

#include<iostream>
#include<string.h>

using namespace std;

class Node {

public:

	Node(string, int);
	~Node();

	//void accept();
	//void listen();
	//void send();
	//void connect();
	//void threadOne();
	//void threadTwo();
	//void threadThree();
	//void threadFour();
	int getPort();
	void setPort(int port);
	string getIp();
	void setIp(string ip);
	// void setClient(Client *client);
	// Client getClient();
	//void show();
	//private:
	//stack stackLeft;
	//stack stackRight;

private:

	int port;
	string ip;
	ServerActions *serverActions;
	GenericThread *threadOne;
	Client *client;
	Server *server;
};
