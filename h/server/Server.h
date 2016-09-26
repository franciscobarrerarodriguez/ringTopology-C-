#include <sys/socket.h>
#include <netdb.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <string.h>
#include <iostream>

#define INVALID_SOCKET -1

using namespace std;

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

  void setPort(int port);
  int getPort();

  void setSocket_conn(int socket_conn);
  int getSocket_conn();

  void setFlag(bool);
  bool getFlag();

  void setState(int);
  int getState();

private:

  int ip;
  int port;
  int socket_server;
  int socket_conn;
  /* Estado 0 para configuracion, estado 1 para escuchar. */
  int state;
  bool flag;

  string address;
};
