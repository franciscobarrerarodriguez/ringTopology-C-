#include "../../h/listen/Thread.h"

Thread::Thread(IRunnable *ir){
	this->iRunnable = ir;
};

void Thread::createThreadListen(){
	pthread_create(&pthreadId, NULL, &Thread::function, this);
};
