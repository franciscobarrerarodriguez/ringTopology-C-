#include "../../h/actions/ClientActions.h"

ClientActions::ClientActions(Client *client){
  this->client = client;
  this->state = true;
};

void ClientActions::initClient(){
  if(this->client->initializeClient() != INVALID_SOCKET){
    cout << "/* Cliente iniciado . . . */" << endl;
    this->client->setState(1);
  }else{
    cout << "/* Cliente no iniciado. */" << endl;
  }
};

void ClientActions::connectClient(){
  if(this->client->connectClient() != INVALID_SOCKET){
    cout << "/* Cliente conectado . . . */" << endl;
    this->client->setState(2);
  }else{
    cout << "/* Error conectando. */" << endl;
  }
};

void ClientActions::sendMessages() {
  if(!this->client->getLeftPriorityQueue().empty()){
    if(this->client->sendMessage() != INVALID_SOCKET){
      cout << "/* Mensaje enviado. */" << endl;
    }else{
      cout << "/* Mensaje no enviado */" << endl;
    }
  }
};

void ClientActions::run() {
  while(this->state == true){
    switch (this->client->getState()) {
      case 0:
      this->initClient();
      break;
      case 1:
      this->connectClient();
      break;
      case 2:
      this->sendMessages();
      break;
    }
  }
};
