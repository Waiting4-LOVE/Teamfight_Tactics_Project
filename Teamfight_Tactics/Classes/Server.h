#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include "OnlineGameData.h"
#pragma comment(lib, "Ws2_32.lib")

#define PORT "8888"

class Server
{
private:
	SOCKET listenSocket;
	SOCKET clientSocket;
public:
	int init();
	void communicate();
	void changedata();
	void receivedata();
	void close();
	void waiting();
	void start();
};
extern Server server;