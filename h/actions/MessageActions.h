#ifndef MESSAGE_ACTIONS_H_
#define MESSAGE_ACTIONS_H_

#include "../thread/IRunnable.h"
#include "../client/Client.h"

#include<iostream>

using namespace std;

class MessageActions:public IRunnable{

public:

  MessageActions(Client *);

  void addMessage();

  void run();

private:
  Client *client;
  bool state;
};
#endif /* MESSAGE_ACTIONS_H_ */
