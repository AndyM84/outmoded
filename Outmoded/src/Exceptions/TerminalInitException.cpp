#include <Exceptions/TerminalInitException.h>

namespace Outmoded
{
	const char *TerminalInitException::what() const throw()
	{
		return "The terminal window could not be found or initialized properly.";
	}
}
