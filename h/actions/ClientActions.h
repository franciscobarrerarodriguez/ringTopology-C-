#include "../thread/IRunnable.h"
#include "../client/Client.h"

#include<iostream>

using namespace std;

class ClientActions:public IRunnable{

public:

  ClientActions(Client *);

  void run();

  void init();

private:
  Client *client;
  bool state;
};
