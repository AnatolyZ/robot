#include "Connection.hpp"
#include <iostream>
#include <atomic>

enum class Command
{
	Stop = 0,
	Forward,
	ForwardRight,
	Right,
	BackwardRight,
	Backward,
	BackwardLeft,
	Left,
	ForwardLeft,
};


void commandThread(std::atomic<Command>& command)
{
	(void) command;
	while(true)
	{

	}
}

int main()
{
	const auto conn = Connection::create("192.168.0.108", 55555);
	return 0;
}
