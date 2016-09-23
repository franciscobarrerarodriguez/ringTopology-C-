#include <iostream>
#include "../h/stack.h"
#include "../h/message.h"
using namespace std;

int main(){


message * messages = new message("ip");
stack<message> *stacks = new stack<message>();
//message *messages = new message("ip");

 stacks->push(messages);

return 0;
}
