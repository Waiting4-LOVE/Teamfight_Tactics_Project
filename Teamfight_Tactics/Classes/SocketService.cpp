#include "SocketService.h"

#include <utility>
USING_NS_CC;
/*
SocketService* SocketService::socket = nullptr;

SocketService* SocketService::getInstance() {
    if (!socket) {
        socket = new SocketService();
    }
    return socket;
}

void SocketService::deleteInstance() {
    delete socket;
    socket = nullptr;
}

SocketService::~SocketService() {
    if (client) client->close();
}

void SocketService::initSocket() {
    
    auto s = FileUtils::getInstance()->getStringFromFile("utils.json");
    rapidjson::Document doc;
    doc.Parse<0>(s.c_str());
    auto ip = doc["ip"].GetString();
    auto port = doc["port"].GetInt();
    string str = string("ws://") + ip + ":" + to_string(port);
   
    client = new WebSocket();
    client->init(*this, str); 
    client = new WebSocket();
    client->init(delegate, "ws://frp-boy.top:60849");
    receiveMessage = "";
    ifReceviceMessage = false;
}

void SocketService::sendMessage(string str) {
    CCLOG("\t%s\n", str.c_str());
    client->send(str);
}

string SocketService::getMessage() {
    return receiveMessage;
}

void SocketService::setMessage(string s) {
    receiveMessage = std::move(s);
}

void SocketService::onOpen(WebSocket* ws) {
    log("\tsuccessful\n");
}

void SocketService::onMessage(WebSocket* ws, const WebSocket::Data& data) {
    log("\t%s\n", data.bytes);
    receiveMessage = data.bytes;
    ifReceviceMessage = true;
}

void SocketService::onClose(WebSocket* ws) {
    log("\tStopped\n");
}

void SocketService::onError(WebSocket* ws, const WebSocket::ErrorCode& error) {
    //
}

SocketService::SocketService() {
    initSocket();
}*/

SocketService* SocketService::socket = nullptr;

SocketService* SocketService::getInstance() {
    if (!socket) {
        socket = new SocketService();
    }
    return socket;
}

void SocketService::deleteInstance() {
    if (socket) {
        delete socket;
        socket = nullptr;
    }
}

SocketService::SocketService() : client(nullptr), ifReceviceMessage(false) {
}

SocketService::~SocketService() {
    if (client) {
        client->close();
    }
}

void SocketService::initSocket() {
    client = new WebSocket();
    client->init(*this, "ws://frp-boy.top:60849");
}

void SocketService::sendMessage(string str) {
    if (client && client->getReadyState() == WebSocket::State::OPEN) {
        client->send(str);
    }
}

string SocketService::getMessage() {
    if (ifReceviceMessage) {
        ifReceviceMessage = false;
        return receiveMessage;
    }
    return "";
}

void SocketService::setMessage(string s) {
    receiveMessage = s;
    ifReceviceMessage = true;
}

void SocketService::onOpen(WebSocket* ws) {
    CCLOG("WebSocket connected");
}

void SocketService::onMessage(WebSocket* ws, const WebSocket::Data& data) {
    CCLOG("Received message: %s", data.bytes);
    setMessage(data.bytes);
}

void SocketService::onClose(WebSocket* ws) {
    CCLOG("WebSocket disconnected");
}

void SocketService::onError(WebSocket* ws, const WebSocket::ErrorCode& error) {
    CCLOG("WebSocket error: %d", static_cast<int>(error));
}


