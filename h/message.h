#include<iostream>
#include<string>

#include "time.h"

using namespace std;

class message{

	public:
	message();
	message(string);
	string getIp();
	void setIp(string ip);

	private:
	string ip;
	time_t arrivalHour;
	time_t endHour;

};
