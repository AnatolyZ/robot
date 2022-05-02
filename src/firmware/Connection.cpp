#include "Connection.hpp"

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

namespace Connection {

Connection::Connection(const int socket_fd)
	: m_socket_fd(socket_fd)
{
}

Connection::~Connection()
{
	::close(m_socket_fd);
}

std::optional<Connection>create(const std::string& server, uint16_t port)
{
	const auto socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0)
	{
		std::cerr << "Failed to open socket." << std::endl;
		return std::nullopt;
	}

	auto server_he = ::gethostbyname(server.c_str());
	if (server_he == nullptr) {
		std::cerr << "Host " << server << " not found.";
		::close(socket_fd);
		return std::nullopt;
	}

	::sockaddr_in serv_addr{};
	serv_addr.sin_family = AF_INET;
	std::memcpy(
		reinterpret_cast<char*>(&serv_addr.sin_addr.s_addr),
		reinterpret_cast<char*>(server_he->h_addr),
		server_he->h_length);
	serv_addr.sin_port = ::htons(port);
	if (::connect(
		socket_fd,
		reinterpret_cast<::sockaddr*>(&serv_addr),
		sizeof(serv_addr)) < 0)
	{
		std::cerr << "Conection to " << server << ":" << port << " failed.";
		::close(socket_fd);
		return std::nullopt;
	}

	return Connection(socket_fd);
}

} // namespace Connection
