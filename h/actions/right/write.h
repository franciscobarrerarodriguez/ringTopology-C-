#ifndef WRITE_H_
#define WRITE_H_

#include "../../thread/IRunnable.h"
#include "../../server/Server.h"
#include "../../thread/GenericThread.h"

#include<iostream>

using namespace std;

class Write:public IRunnable{

public:

  Write(Server *);

  void write();

  void run();

private:

  Server *server;

  bool state;
};
#endif /* WRITE_H_ */
