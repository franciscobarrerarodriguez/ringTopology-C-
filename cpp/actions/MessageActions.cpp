#include "../../h/actions/MessageActions.h"

using namespace std;

MessageActions::MessageActions(Client *client){
  this->client = client;
  this->state = true;
};

void MessageActions::run(){
  while (this->state == true) {
    cout << "/* ¿Enviar un mensaje? (y)*/" << endl;
    string option;
    cin >> option;
    if(option == "y"){
      this->client->create();
    }
  }
};
