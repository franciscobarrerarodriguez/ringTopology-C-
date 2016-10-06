#include "../thread/IRunnable.h"
#include "../server/Server.h"

#include<iostream>

using namespace std;

class ServerActions:public IRunnable{

public:

  ServerActions(Server *);

  void run();

  void initServer();
  void listenClient();
  void acceptClient();
  void waitForAMessage();

  void setSocket_conn();
  int getSocket_conn();

private:
  Server *server;
  bool state;
};
