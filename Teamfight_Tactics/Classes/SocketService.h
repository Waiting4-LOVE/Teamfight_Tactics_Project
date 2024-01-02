#ifndef NETWORKSMALLGAME_SOCKETSERVICE_H
#define NETWORKSMALLGAME_SOCKETSERVICE_H

#include "cocos2d.h"
#include "network/WebSocket.h"
#include "json/document.h"
#include <string>

USING_NS_CC;
using namespace network;
using namespace std;

class SocketService : public WebSocket::Delegate {
	static SocketService* socket;

public:
	static SocketService* getInstance();

	static void deleteInstance();

	~SocketService() override;

	void initSocket();

	void sendMessage(string str);

	string getMessage();

	void setMessage(string s);

	void onOpen(WebSocket* ws) override;

	void onMessage(WebSocket* ws, const WebSocket::Data& data) override;

	void onClose(WebSocket* ws) override;

	void onError(WebSocket* ws, const WebSocket::ErrorCode& error) override;

	class MyWebSocketDelegate : public cocos2d::network::WebSocket::Delegate
	{
	public:
		virtual void onOpen(cocos2d::network::WebSocket* ws) override {
			CCLOG("WebSocket connected");

			// 发送消息示例
			ws->send("Hello, server!");
		}

		virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data) override {
			CCLOG("Received message: %s", data.bytes);
		}

		virtual void onClose(cocos2d::network::WebSocket* ws) override {
			CCLOG("WebSocket disconnected");
		}

		virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error) override {
			CCLOG("WebSocket error: %d", static_cast<int>(error));
		}
	};
	SocketService();
private:
	

	WebSocket* client;
	MyWebSocketDelegate delegate;
	string receiveMessage;

	bool ifReceviceMessage{};
};


#endif //NETWORKSMALLGAME_SOCKETSERVICE_H