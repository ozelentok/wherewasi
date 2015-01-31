#pragma once
#include <string>

class CommandLineArgs {

private:
	std::string _date;

public:
	CommandLineArgs(const int argc, char const * argv[]);
	~CommandLineArgs() = default;

	std::string get_date() const;
};
