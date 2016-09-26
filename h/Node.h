#include "Client.h"
#include "Server.h"
#include "listen/Listen.h"

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
	Listen *listen;
	Thread *threadSever;
	Client *client;
	Server *server;
};
