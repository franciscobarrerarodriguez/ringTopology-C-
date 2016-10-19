#ifndef SERVER_H_
#define SERVER_H_

#include <sys/socket.h>
#include <netdb.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <queue>

// Lib rapidjson ----------------------------------------------------
#include "../lib/rapidjson/include/rapidjson/document.h"
#include "../lib/rapidjson/include/rapidjson/writer.h"
#include "../lib/rapidjson/include/rapidjson/stringbuffer.h"
// Lib rapidjson ----------------------------------------------------

#define INVALID_SOCKET -1

using namespace std;
using namespace rapidjson;

class Server{

public:

  Server(int);
  ~Server();

  struct sockaddr_in server_address;
  struct sockaddr_storage client;
  struct ifreq iFREQ;

  int initializeServer();
  int listenClient();
  int acceptClient();
  int receiveMessage();
  int writeRight();
  void msleep(unsigned long);

  void setPort(int port);
  int getPort();

  void setSocket_conn(int socket_conn);
  int getSocket_conn();

  void setFlag(bool);
  bool getFlag();

  void setState(int);
  int getState();

  void setLeftQueue(queue<string> *queue);
  queue<string> getLeftQueue();

  void setRightQueue(queue<string> *queue);
  queue<string> getRightQueue();

private:

  int ip;
  int port;
  int socket_server;
  int socket_conn;
  /* Estado 0 para configuracion, estado 1 para escuchar. */
  int state;
  bool flag;

  string address;
  /* Stack de izquierda a derecha */
  queue<string> *leftSimpleQueue;
  queue<string> *rightSimpleQueue;

  /* String stream */
  stringstream stringStream;
};
#endif /* SERVER_H_ */
