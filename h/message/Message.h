#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <time.h>
#include<iostream>
#include<string>

using namespace std;

struct Message{

public:

	Message(string);
	string getIp();
	void setIp(string ip);

private:

	string ip;
	time_t arrivalHour;
	time_t endHour;

};
#endif /* MESSAGE_H_ */
