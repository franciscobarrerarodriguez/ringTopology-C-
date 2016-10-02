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

/*
* Escribe aqui tu codigo de como se va a enviar el mensaje,
* Es decir aqui el nodo genera su propio mensaje y lo envia;
* Tambien configurar cada cuanto se envia un mensaje o como se envia un nuevo
* mensaje.
*/
void ClientActions::sendingMessage() {
  if(this->client->isCreated() == false){
    this->client->create();
  }else{
    if(this->client->getLeftSimpleQueue().isEmpty() == false){
      this->client->sendMessage();
    }
  }
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
