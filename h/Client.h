#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <ifaddrs.h>
#include <time.h>
#include <iostream>

#define INVALID_SOCKET -1

using namespace std;

class Client{

public:

	int port;
	int socket_server;

	string ip;

	struct sockaddr_in server_address;

	Client();
	~Client();

	int initializeClient();

	void send();
	void connect();
	void closeConnectionClient();

	void setPort(int port);
	int getPort();

	void setIp(string ip);
	string getIp();
	void setSocket_server(int socket_server);
	int getSocket_server();

private:


};
