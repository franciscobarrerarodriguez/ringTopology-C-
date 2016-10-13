#include "../../h/actions/MessageActions.h"

using namespace std;

MessageActions::MessageActions(Client *client){
  this->client = client;
  this->state = true;
};

void MessageActions::run(){
  while (this->state == true) {
    cout << "/* Send message l/r? (left/right) */" << endl;
    string option;
    cin >> option;
    if((option == "l") || (option == "r") || (option == "R") || (option == "L")){
      this->client->create(option);
    }else{
      cout << "/* Wrong option. */" << endl;
    }
  }
};
