clear
echo "Compilando Node . . ."
g++ cpp/thread/IRunnable.cpp cpp/thread/GenericThread.cpp cpp/actions/MessageActions.cpp cpp/actions/ServerActions.cpp cpp/actions/ClientActions.cpp cpp/actions/right/listen.cpp cpp/actions/right/write.cpp cpp/client/Client.cpp cpp/server/Server.cpp cpp/Node.cpp cpp/Main.cpp -o mainNode -l pthread
echo "Compilado . . ."
