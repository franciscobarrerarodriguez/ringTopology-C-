#include "../../h/thread/GenericThread.h"

GenericThread::GenericThread(IRunnable *ir){
	this->iRunnable = ir;
};

void GenericThread::createThread(){
	pthread_create(&pthreadId, NULL, &GenericThread::function, this);
};
