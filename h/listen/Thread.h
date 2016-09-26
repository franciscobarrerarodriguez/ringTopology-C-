#include <iostream>
#include <pthread.h>
#include "../iRunnable.h"

using namespace std;

class Thread{

public:

  pthread_t pthreadId;
  IRunnable *iRunnable;
  void createThreadListen();
  static void *function(void *p){
    ((Thread *)p)->iRunnable->run();
    return 0;
  }
  Thread(IRunnable *);
};
