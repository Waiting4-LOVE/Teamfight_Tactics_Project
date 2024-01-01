#include"Server.h"


int Server::init()
{
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return 1;
    }

    struct addrinfo hints, * res;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(NULL, PORT, &hints, &res) != 0) {
        WSACleanup();
        return 1;
    }

    listenSocket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (listenSocket == INVALID_SOCKET) {
        freeaddrinfo(res);
        WSACleanup();
        return 1;
    }

    if (bind(listenSocket, res->ai_addr, (int)res->ai_addrlen) == SOCKET_ERROR) {
        closesocket(listenSocket);
        freeaddrinfo(res);
        WSACleanup();
        return 1;
    }
    else {
        CCLOG("Successfully listening\n");
    }

    freeaddrinfo(res);

    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }
    else {
        CCLOG("Successfully listening\n");
    }

    clientSocket = accept(listenSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }
    
}

void Server::communicate()
{
    char recvbuf[512] = { 0 };
    int recvbuflen = 512;
    int recvResult = recv(clientSocket, recvbuf, recvbuflen, 0);
    if (recvResult > 0) {
		std::cout << "Received message: " << recvbuf << std::endl;
	}

    std::string sendbuf;
    std::cin >> sendbuf;
    send(clientSocket, (const char*)sendbuf.c_str(), sendbuf.length(), 0);
}

void Server::changedata()
{
    std::string data;
    onlineGameData.getData();
    data = onlineGameData.serializeGameData();
    send(clientSocket, (const char*)data.c_str(), data.length(), 0);

    
    
}

void Server::receivedata()
{
    char recvbuf[1024] = { 0 };
    int recvbuflen = 1024;
    int recvResult = recv(clientSocket, recvbuf, recvbuflen, 0);
    onlineGameData = onlineGameData.deserializeGameData(recvbuf);
    onlineGameData.toPlayer2Data();
}

void Server::close()
{
    closesocket(clientSocket);
    closesocket(listenSocket);
    WSACleanup();
}
void Server::waiting()
{
    char recvbuf[1] = { 0 };
    int recvbuflen = 1;
    int recvResult = recv(clientSocket, recvbuf, recvbuflen, 0);
    if (recvResult > 0) {
        if (recvbuf[0] == '1')
        {
            global_data->canstart = true;
        }
	}
}
void Server::start()
{
    char sign[1] = { '1' };
    send(clientSocket, sign, 1, 0);
}
/*
int main() {
    Server server;
    server.init();
    server.communicate();
    server.communicate();
    server.close();
    return 0;
}*/
