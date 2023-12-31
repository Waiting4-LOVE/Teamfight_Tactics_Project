#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include<string>
#include "OnlineGameData.h"
#pragma comment(lib, "Ws2_32.lib")

#define PORT "8888"
#define SERVER_IP "172.20.10.2"


class Client
{
private:
    SOCKET connectSocket;
public:
    int init();
    void communicate();
    void changedata();
    void receivedata();
    void close();
    void join();
    void waitstart();
};

