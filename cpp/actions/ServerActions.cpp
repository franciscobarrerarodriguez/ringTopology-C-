#include "../../h/actions/ServerActions.h"

using namespace std;

ServerActions::ServerActions(Server *server){
  this->server = server;
  this->state = true;
};

void ServerActions::initServer() {
  if(this->server->initializeServer() != INVALID_SOCKET){
    cout << "/* Servidor iniciado . . . */" << endl;
    this->server->setState(1);
  }else{
    cout << "/* Servidor no iniciado. */" << endl;
  }
};

void ServerActions::listenClient(){
  if(this->server->listenClient() != INVALID_SOCKET){
    cout << "/* Esperando por un cliente . . . */" << endl;
    this->server->setState(2);
  }else{
    cout << "/* Bind falló. */" << endl;
  }
};

void ServerActions::acceptClient(){
  if(this->server->acceptClient() != INVALID_SOCKET){
    cout << "/* Cliente aceptado . . . */" << endl;
    this->write = new Write(this->server);
    this->writeThread = new GenericThread(this->write);
    this->writeThread->createThread();
    this->server->setState(3);
  }else{
    cout << "/* Cliente no aceptado. */" << endl;
  }
};

void ServerActions::waitForAMessage() {
  if(this->server->receiveMessage() == INVALID_SOCKET){
    cout << "/* No se pudo recibir el mensaje. */" << endl;
  }
};

void ServerActions::run(){
  while (this->state == true) {
    switch (this->server->getState()) {
      case 0:
      this->initServer();
      break;
      case 1:
      this->listenClient();
      break;
      case 2:
      this->acceptClient();
      break;
      case 3:
      this->waitForAMessage();
    }
  }
};
