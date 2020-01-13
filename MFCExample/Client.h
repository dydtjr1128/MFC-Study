#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include <string>
#include <boost/asio.hpp>
#include <boost/asio/ip/address.hpp>

namespace network {
	class Client {
	protected:
		boost::asio::ip::address serverIP_;
		unsigned short serverPort_;
		std::string target_;
	public:
		explicit Client(std::string serverIP, unsigned short serverPort);
		virtual ~Client();

		void SetTargetPath(const std::string& path);
		virtual void InitializeSocket() = 0;
		virtual void SendRequest(std::string path) = 0;
		virtual std::string ReceiveResponse() = 0;
		//virtual std::any get(std::string path) = 0;
	};

}

#endif // !NETWORK_CLIENT_H