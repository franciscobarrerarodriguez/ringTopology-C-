#ifndef GENERIC_THREAD_H_
#define GENERIC_THREAD_H_

#include <iostream>
#include <pthread.h>
#include "IRunnable.h"

using namespace std;

class GenericThread {

public:

  pthread_t pthreadId;
  IRunnable *iRunnable;
  void createThread();
  static void *function(void *p){
    ((GenericThread *)p)->iRunnable->run();
    return 0;
  }
  GenericThread(IRunnable *);
};
#endif /* GENERIC_THREAD_H_ */
