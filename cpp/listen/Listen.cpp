#include "../../h/listen/Listen.h"

using namespace std;

Listen::Listen(){
  cout << "/* Soy un listen */" << endl;
};

void Listen::run(){
  while(this->state == true){
    cout << "/* message */" << endl;
  }
};
