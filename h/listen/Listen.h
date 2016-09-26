#include "../iRunnable.h"
#include<iostream>

using namespace std;

class Listen:public IRunnable{

public:

  bool state;

  Listen();

  void run();
  void setSocket_conn();
  int getSocket_conn();
};
