#ifndef LISTEN_H_
#define LISTEN_H_

#include "../../thread/IRunnable.h"
#include "../../client/Client.h"
#include "../../thread/GenericThread.h"

#include<iostream>

using namespace std;

class Listen:public IRunnable{

public:

  Listen(Client *);

  void listen();

  void run();

private:

  Client *client;

  bool state;
};
#endif /* LISTEN_H_ */
