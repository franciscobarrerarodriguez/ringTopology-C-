#include "../../h/actions/ClientActions.h"

ClientActions::ClientActions(Client *client){
  this->client = client;
  this->state = true;
};

void ClientActions::init(){
  if(this->client->initializeClient() != INVALID_SOCKET){
    cout << "/* Buscando conexion . . .  */" << endl;
    if(this->client->connectClient() != INVALID_SOCKET){
      cout << "/* Cliente conectado. */" << endl;
      this->client->setState(1);
    }else{
      cout << "/* Error conectando. */" << endl;
    }
  }else{
    cout << "/* Cliente no iniciado. */" << endl;
  }
};

void ClientActions::sendingMessage() {
  std::cout << "/* Enviando los mensajes . . . */" << std::endl;
}

void ClientActions::run() {
while(this->state == true){
  switch (this->client->getState()) {
    case 0:
    this->init();
    break;
    case 1:
    this->sendingMessage();
    break;
  }
}
}
