#pragma once
#include"cocos2d.h"
#include"network/websocket.h"

USING_NS_CC;


class SocketBase : public network::WebSocket {
public:
	SocketBase()
	{
		// ����WebSocket������
		webSocketServer = new network::WebSocket::Delegate();

		// ����WebSocket�ص�����
		webSocketServer->init(this, "ws://0.0.0.0:9002");  // ������������ӿڵ�9002�˿�

		webSocketServer->onOpen = [=](cocos2d::network::WebSocket* ws) {
			CCLOG("WebSocket server connected");
			};

		webSocketServer->onMessage = [=](cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data) {
			CCLOG("Received message: %s", data.bytes);

			// ������յ�����Ϣ�����Ը�����Ҫ�����߼�����
			// ���磬�㲥��Ϣ���������ӵĿͻ���
			broadcastMessage(data.bytes);
			};

		webSocketServer->onClose = [=](cocos2d::network::WebSocket* ws) {
			CCLOG("WebSocket server disconnected");
			};

		// ��ʼ����
		webSocketServer->open();
	}

	~SocketBase()
	{
		// �ر�WebSocket
		webSocketServer->close();
		delete webSocketServer;
	}

	// �㲥��Ϣ���������ӵĿͻ���
	void broadcastMessage(const std::string& message)
	{
		// �������пͻ������ӣ���������Ϣ
		for (auto& connection : webSocketServer->getConnections())
		{
			webSocketServer->send(connection, message);
		}
	}

private:
	network::WebSocket::Delegate* webSocketServer;
};

