#include "CommandLineArgs.hpp"
#include <stdexcept>

static const int _arg_date_index = 1;

CommandLineArgs::CommandLineArgs(const int argc, char const * argv[])
{
	if (argc != 2)
	{
		throw std::invalid_argument("Invalid number of arguments");
	}
	_date = std::string(argv[_arg_date_index]);
}

CommandLineArgs::~CommandLineArgs()
{}

std::string CommandLineArgs::get_date()
{
	return _date;
}
