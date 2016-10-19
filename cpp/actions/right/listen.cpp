#include "../../../h/actions/right/listen.h"

Listen::Listen(Client *client){
  this->client = client;
  this->state = true;
};

void Listen::listen(){
  this->client->msleep(5000);
  if(this->client->listenRight() == INVALID_SOCKET){
    cout << "/* No se pudo recibir el mensaje. */" << endl;
  }
};

void Listen::run() {
  while(this->state == true){
    this->listen();
  }
};
