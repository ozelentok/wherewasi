#pragma once
#include <string>

class CommandLineArgs {

private:
	std::string _date;
	CommandLineArgs(const CommandLineArgs & other);

public:
	CommandLineArgs(const int argc, char const * argv[]);
	~CommandLineArgs();

	std::string get_date();
};
