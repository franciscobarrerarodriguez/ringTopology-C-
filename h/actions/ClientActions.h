#include "../thread/IRunnable.h"
#include "../client/Client.h"
#include "../thread/GenericThread.h"
#include "../actions/MessageActions.h"

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

  MessageActions *messageActions;

  /* Hilo de mensaje. */
  GenericThread *messageThread;
};
