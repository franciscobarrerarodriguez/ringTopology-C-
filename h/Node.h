#include "Client.h"

#include<iostream>
#include<string.h>
//#include "stack.h"


using namespace std;

class Node {

	public:

	int port;
	string ip;
	Client *client;
//	Node(string, int);
	Node();
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
	//void show();
	//private:
	//stack stackLeft;
	//stack stackRight;
};
