#include "../../h/actions/ServerActions.h"

using namespace std;

ServerActions::ServerActions(Server *server){
  this->server = server;
  this->state = true;
};

void ServerActions::init() {
  if(this->server->initializeServer() != INVALID_SOCKET){
    if(this->server->listenClient() != INVALID_SOCKET){
        cout << "/* Esperando por una conexion . . . */" << endl;
      if(this->server->acceptClient() != INVALID_SOCKET){
        cout << "/* Cliente aceptado. */" << endl;
        this->server->setState(1);
      }else{
        cout << "/* Cliente no aceptado. */" << endl;
      }
    }else{
      cout << "/* Bind falló. */" << endl;
    }
  }else{
    cout << "/* Servidor no iniciado. */" << endl;
  }
};

void ServerActions::waitingForAMessage() {
  /* Aqui es donde se reciben los mensajes,
  recibirlos a agregarlos a la pila del servidor.*/
};

void ServerActions::run(){
  while (this->state == true) {
    switch (this->server->getState()) {
      case 0:
      this->init();
      break;
      case 1:
      this->waitingForAMessage();
    }
  }
};
