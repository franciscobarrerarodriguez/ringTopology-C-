#g++ iRunnable.cpp server.cpp threadListen.cpp listenClient.cpp mainServer.cpp -o mainServer -l pthread
clear
echo "Compilando Node . . ."
g++ cpp/iRunnable.cpp cpp/listen/Thread.cpp cpp/listen/Listen.cpp cpp/Client.cpp cpp/Server.cpp cpp/Node.cpp cpp/Main.cpp -o mainNode -l pthread
echo "Compilado . . ."
