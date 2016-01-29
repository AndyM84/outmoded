#include <Exceptions/ArgumentRangeException.h>

namespace Outmoded
{
	ArgumentRangeException::ArgumentRangeException()
		: Argument("NULL"), Minimum("NULL"), Maximum("NULL")
	{ }

	ArgumentRangeException::ArgumentRangeException(const std::string &Arg, const std::string &Min, const std::string &Max)
		: Argument(Arg), Minimum(Min), Maximum(Max)
	{ }

	ArgumentRangeException::ArgumentRangeException(const ArgumentRangeException &Source)
		: Argument(Source.Argument), Minimum(Source.Minimum), Maximum(Source.Maximum)
	{ }

	const char *ArgumentRangeException::what() const throw()
	{
		std::string msg = "The '" + this->Argument + "' argument was out of range. (Must be between " + this->Minimum + " and " + this->Maximum + ")";

		return msg.c_str();
	}
}
