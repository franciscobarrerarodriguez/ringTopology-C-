#include "../../h/actions/MessageActions.h"

using namespace std;

MessageActions::MessageActions(Client *client){
  this->client = client;
  this->state = true;
};

void MessageActions::run(){
  while (this->state == true) {
    cout << "/* Escriba un mensaje */" << endl;
    string message;
    cin >> message;
    this->client->create(message);
  }
};
