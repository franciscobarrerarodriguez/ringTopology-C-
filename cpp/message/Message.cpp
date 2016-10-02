#include "../../h/message/Message.h"

Message::Message(string ip){
  this->ip = ip;
}

string Message::getIp(){
  return this->ip;
};
void Message::setIp(string ip){
  this->ip = ip;
};
