#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

#define INVALID_SOCKET -1

using namespace std;

/*class Client*/
class Client{

public:

	Client();
	~Client();

	int initializeClient();
	int connectClient();

	// void send();
	// void closeConnectionClient();

	void setPort(int port);
	int getPort();

	void setIp(string ip);
	string getIp();

	void setSocket_server(int socket_server);
	int getSocket_server();

private:

	int port;
	int socket_server;

	string ip;

	struct sockaddr_in server_address;
};
