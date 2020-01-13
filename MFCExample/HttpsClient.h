#ifndef NETWORK_HTTPS_HTTPS_CLIENT_H
#define NETWORK_HTTPS_HTTPS_CLIENT_H

#include <iostream>
#include <string>

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/bind.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/stream.hpp>

#include "Client.h"

//#pragma comment(lib, "libeay32")
//#pragma comment(lib, "ssleay32")

using tcp = boost::asio::ip::tcp; // from <boost/asio/ip/tcp.hpp>
namespace ssl = boost::asio::ssl; // from <boost/asio/ssl.hpp>

namespace network {
	namespace https {
		class HttpsClient : public Client {
		private:
			std::string target_;

			/*ssl::context context_;
			ssl::stream<tcp::socket> socket_;*/

			boost::asio::streambuf request_;
			boost::asio::streambuf response_;
		public:
			explicit HttpsClient(std::string serverIP, unsigned short serverPort);
			~HttpsClient();

			void InitializeSocket() override;
			void SendRequest(std::string path)	    override;
			std::string ReceiveResponse()  override;

		};

	}
}

#endif // !NETWORK_HTTPS_HTTPS_CLIENT_H