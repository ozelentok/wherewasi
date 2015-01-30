#include "CommandLineArgs.hpp"
#include "Exception.hpp"

static const int _arg_date_index = 1;

CommandLineArgs::CommandLineArgs(const int argc, char const * argv[])
{
	if (argc != 2)
	{
		throw InvalidArgumentException(
				"Usage: wherewasi [TIME]\n"
				"Time can be in the following formats:\n"
				"  [YYYY-MM-DD]\n"
				"  [YYYY/MM/DD]\n");
	}
	_date = std::string(argv[_arg_date_index]);
}

std::string CommandLineArgs::get_date() const
{
	return _date;
}
