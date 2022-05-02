#pragma once
#include <optional>
#include <string>

namespace Connection
{

// Simple RAII wrapper for connection to host
class Connection {

public:
	Connection(const int socket_fd);
	~Connection();

private:
	int m_socket_fd = 0;
};

std::optional<Connection> create(const std::string& server, uint16_t port);

} // namespace Connection
