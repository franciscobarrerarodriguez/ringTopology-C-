#include "../../../h/actions/right/write.h"

Write::Write(Server *server){
  this->server = server;
  this->state = true;
};

void Write::write(){
  /*Aqui wait */
  this->server->msleep(5000);
  if(this->server->getRightQueue().empty() == false){
    if(this->server->writeRight() != INVALID_SOCKET){
      cout << "/* Mensaje enviado. */" << endl;
    }else{
      cout << "/* Mensaje no enviado */" << endl;
    }
  }else{
    cout << "/* Queue esta vacia. */" << endl;
  }
};

void Write::run() {
  while(this->state == true){
    this->write();
  }
};
