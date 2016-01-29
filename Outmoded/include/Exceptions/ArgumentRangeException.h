#pragma once

#include <exception>
#include <string>

namespace Outmoded
{
	class ArgumentRangeException : public std::exception
	{
	public:
		ArgumentRangeException();
		ArgumentRangeException(const std::string &Arg, const std::string &Min, const std::string &Max);
		ArgumentRangeException(const ArgumentRangeException &Source);

		virtual const char *what() const throw();

	protected:
		const std::string Argument;
		const std::string Minimum;
		const std::string Maximum;
	};
}