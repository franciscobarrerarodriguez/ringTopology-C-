#include "../../h/actions/ServerActions.h"

using namespace std;

ServerActions::ServerActions(Server *server){
  cout << "/* Soy un server actions */" << endl;
  this->server = server;
};

void ServerActions::run(){
  if(this->server->initializeServer() != INVALID_SOCKET){
    cout << "Servidor iniciado . . ." << endl;
    if(this->server->listenClient() != INVALID_SOCKET){
      cout << "Bind funcionando esperando cliente . . ." << endl;
      if(this->server->acceptClient() != INVALID_SOCKET){
        cout << "Cliente aceptado . . ." << endl;
      }else{
        cout << "Cliente no aceptado." << endl;
      }
    }else{
      cout << "Bind falló." << endl;
    }
  }else{
    cout << "Servidor no iniciado." << endl;
  }
};
