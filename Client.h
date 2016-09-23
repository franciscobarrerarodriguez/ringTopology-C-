#include <iostream>
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

using namespace std;

class Client{

	public:
	int socket_server;
	Client();
	void send();
	void connect();

	void closeConnectionClient();
	struct sockaddr_in server;
	private:


};
