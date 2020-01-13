#include "pch.h"
#include "HttpsClient.h"

namespace network {
	namespace https {

		HttpsClient::HttpsClient(std::string serverIP, unsigned short serverPort) : Client(serverIP, serverPort)
			/*,
			context_(ssl::context::method::sslv23_client),
			socket_(boost::asio::io_service(), context_)*/
		{
		}

		HttpsClient::~HttpsClient()
		{
		}

		void Connect(const boost::system::error_code& error)
		{/*
			if (!error)
			{
				socket_.async_handshake(boost::asio::ssl::stream_base::client,
					[](const boost::asio::placeholders::error) {
						if (!error)
						{
							std::cout << "Enter message: ";
							std::cin.getline(request_, max_length);
							size_t request_length = strlen(request_);

							boost::asio::async_write(socket_,
								boost::asio::buffer(request_, request_length),
								boost::bind(&client::handle_write, this,
									boost::asio::placeholders::error,
									boost::asio::placeholders::bytes_transferred));
						}
						else
						{
							std::cout << "Handshake failed: " << error.message() << "\n";
						}
					}
				);
			}
			else
			{
				std::cout << "Connect failed: " << error.message() << "\n";
			}*/


		}

		void HttpsClient::InitializeSocket()
		{

			//socket_.set_verify_mode(boost::asio::ssl::verify_peer);

			//boost::asio::async_connect(socket_.lowest_layer(), endpoint_iterator,
			//	boost::bind(&client::handle_connect, this,
			//		boost::asio::placeholders::error));
			//// what we need
			//ssock_.lowest_layer().connect({ serverIP_, serverPort_ });
			//ssock_.handshake(ssl::stream_base::handshake_type::client);

			//std::ostream request_stream(&request_);
			//request_stream << "GET " << path << " HTTP/1.0\r\n";
			//request_stream << "Host: " << server << "\r\n";
			//request_stream << "Accept: */*\r\n";
			//request_stream << "Connection: close\r\n\r\n";
		}

		void HttpsClient::SendRequest(std::string path)
		{
			/*std::string request("GET " + path + " HTTP/1.1\r\n\r\n");
			boost::asio::write(ssock_, buffer(request));*/
		}

		std::string HttpsClient::ReceiveResponse()
		{
			std::string response;

			/*do {
				char buf[1024];
				size_t bytes_transferred = ssock.read_some(buffer(buf), ec);
				if (!ec) response.append(buf, buf + bytes_transferred);
			} while (!ec);*/
			return response;
		}

	}
}