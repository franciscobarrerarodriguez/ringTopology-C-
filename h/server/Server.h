#include "../message/Message.h"

#include <sys/socket.h>
#include <netdb.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
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

  void setPort(int port);
  int getPort();

  void setSocket_conn(int socket_conn);
  int getSocket_conn();

  void setFlag(bool);
  bool getFlag();

  void setState(int);
  int getState();

  void setLeftPriorityQueue(priority_queue<Message*> *priority_queue);
  priority_queue<Message*> getLeftPriorityQueue();

  void setRightPriorityQueue(priority_queue<Message*> *priority_queue);
  priority_queue<Message*> getRightPriorityQueue();

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
	priority_queue<Message*> *leftSimpleQueue;
	priority_queue<Message*> *rightSimpleQueue;
};
