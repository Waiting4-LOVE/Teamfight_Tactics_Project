#pragma once
#include"cocos2d.h"
#include"network/websocket.h"

USING_NS_CC;


class SocketBase : public network::WebSocket {
public:
	SocketBase()
	{
		// 创建WebSocket服务器
		webSocketServer = new network::WebSocket::Delegate();

		// 设置WebSocket回调函数
		webSocketServer->init(this, "ws://0.0.0.0:9002");  // 监听所有网络接口的9002端口

		webSocketServer->onOpen = [=](cocos2d::network::WebSocket* ws) {
			CCLOG("WebSocket server connected");
			};

		webSocketServer->onMessage = [=](cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data) {
			CCLOG("Received message: %s", data.bytes);

			// 处理接收到的消息，可以根据需要进行逻辑处理
			// 例如，广播消息给所有连接的客户端
			broadcastMessage(data.bytes);
			};

		webSocketServer->onClose = [=](cocos2d::network::WebSocket* ws) {
			CCLOG("WebSocket server disconnected");
			};

		// 开始监听
		webSocketServer->open();
	}

	~SocketBase()
	{
		// 关闭WebSocket
		webSocketServer->close();
		delete webSocketServer;
	}

	// 广播消息给所有连接的客户端
	void broadcastMessage(const std::string& message)
	{
		// 遍历所有客户端连接，并发送消息
		for (auto& connection : webSocketServer->getConnections())
		{
			webSocketServer->send(connection, message);
		}
	}

private:
	network::WebSocket::Delegate* webSocketServer;
};

