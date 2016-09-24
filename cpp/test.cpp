#include<iostream>
#include "../h/Node.h"

int main(){
string ip ="192.168.43.243";
int port = 1233;

Node *nodes = new Node();
nodes->setPort(port);
nodes->setIp(ip);

cout << ip << endl;
cout << port << endl;



return 0;
}
