#include "Client.h"
#include <unistd.h>

using namespace std;

Client::Client(){
this->socket_server= socket(PF_INET, SOCK_STREAM,0);
}
