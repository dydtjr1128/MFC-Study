#include "pch.h"
#include "Client.h"

namespace network {
	Client::Client(std::string serverIP, unsigned short serverPort) :
		serverIP_(boost::asio::ip::address::from_string(serverIP)),
		serverPort_(serverPort)
	{
		
	}

	Client::~Client()
	{
	}

	void Client::SetTargetPath(const std::string& path)
	{
		this->target_ = path;
	}

}

