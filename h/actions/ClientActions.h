#include "../thread/IRunnable.h"
#include "../client/Client.h"

#include<iostream>

using namespace std;

class ClientActions:public IRunnable{

public:

  ClientActions(Client *);

  void initClient();
  void connectClient();
  void ownMessage();
  void sendMessages();

  void run();

private:
  Client *client;
  bool state;
};
