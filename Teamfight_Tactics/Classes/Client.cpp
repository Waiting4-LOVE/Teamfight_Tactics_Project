#include "Client.h"


int Client::init()
{
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        CCLOG("WSAStartup failed: %d\n", result);
        return 1;
    }

    struct addrinfo hints, * res;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(SERVER_IP, PORT, &hints, &res) != 0) {
        WSACleanup();
        return 1;
    }

    connectSocket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (connectSocket == INVALID_SOCKET) {
        freeaddrinfo(res);
        WSACleanup();
        return 1;
    }

    if (connect(connectSocket, res->ai_addr, (int)res->ai_addrlen) == SOCKET_ERROR) {
        closesocket(connectSocket);
        freeaddrinfo(res);
        WSACleanup();
        return 1;
    }
    else 
    {
        // 在此处添加输出信息，表示连接成功
        CCLOG("Connection established successfully");
    }

    freeaddrinfo(res);
}

void Client::communicate()
{
    std::string sendbuf;
    sendbuf = "SB";
    send(connectSocket, (const char*)sendbuf.c_str(), sendbuf.length(), 0);

    char recvbuf[512] = { 0 };
    int recvbuflen = 512;
    int recvResult = recv(connectSocket, recvbuf, recvbuflen, 0);
    if (recvResult > 0) {
        std::cout << "Received message: " << recvbuf << std::endl;
    }
}

void Client::changedata()
{
    std::string data;
    onlineGameData.getData();
    data = onlineGameData.serializeGameData();
    send(connectSocket, (const char*)data.c_str(), data.length(), 0);

   
}

void Client::receivedata()
{
    char recvbuf[1024] = { 0 };
    int recvbuflen = 1024;
    int recvResult = recv(connectSocket, recvbuf, recvbuflen, 0);
    onlineGameData = onlineGameData.deserializeGameData(recvbuf);
    onlineGameData.toPlayer2Data();
}

void Client::close()
{
    closesocket(connectSocket);
    WSACleanup();
}

void Client::join()
{
    char sign[1] = { '1' };
    send(connectSocket, sign, 1, 0);
}

void Client::waitstart()
{
    char recvbuf[1] = { 0 };
    int recvbuflen = 1;
    int recvResult = recv(connectSocket, recvbuf, recvbuflen, 0);
    if (recvResult > 0) 
    {
        if (recvbuf[0] == '1')
        {
            global_data->allstart = true;
        }
    }
}
