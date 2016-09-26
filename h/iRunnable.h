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
