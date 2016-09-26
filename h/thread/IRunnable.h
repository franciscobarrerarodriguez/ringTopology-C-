#ifndef IRUNNABLE_H_
#define IRUNNABLE_H_

class IRunnable {

public:

	IRunnable();

	virtual ~IRunnable();
	virtual void run() = 0;

	bool isStart() ;
	void setStart(bool start) ;

private :

	bool start;
};
#endif /* IRUNNABLE_H_ */
