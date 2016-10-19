#include "../../h/actions/ClientActions.h"

ClientActions::ClientActions(Client *client){
  this->client = client;
  this->state = true;

  this->messageActions = new MessageActions(this->client);
  this->messageThread = new GenericThread(this->messageActions);
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
    /* Aqui inica el hilo que se encarga de escuchar desde el cliente. */
    this->listen = new Listen(this->client);
    this->listenThread = new GenericThread(this->listen);
    this->listenThread->createThread();
    this->client->setState(2);
  }else{
    cout << "/* Error conectando. */" << endl;
  }
};

void ClientActions::sendMessages() {
  /*Aqui wait */
  this->client->msleep(5000);
  if(this->client->getLeftQueue().empty() == false){
    if(this->client->sendMessage() != INVALID_SOCKET){
      //cout << "/* Mensaje enviado. */" << endl;
    }else{
      cout << "/* Mensaje no enviado */" << endl;
    }
  }else{
    //cout << "/* Queue esta vacia. */" << endl;
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
      cout << "/* Nodo funcionando . . . */" << endl;
      /* Inicia el hilo para agregar mensajes. */
      this->messageThread->createThread();
      this->sendMessages();
      break;
    }
  }
};
