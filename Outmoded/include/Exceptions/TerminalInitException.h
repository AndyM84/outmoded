#pragma once

#include <exception>
#include <string>

namespace Outmoded
{
	class TerminalInitException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
}

