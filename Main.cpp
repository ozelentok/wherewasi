#include <stdexcept>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "CommandLineArgs.hpp"
#include "Parser.hpp"
#include "TimeRangeFile.hpp"
#include "Exception.hpp"

using std::time_t;
using std::string;
using std::ifstream;

std::string get_time_ranges_file_path()
{
	static const std::string file_name = ".wherewasi";
	char * home_path = getenv("HOME");
	if (home_path == NULL)
	{
		throw EnvironmentException("Home directory not found");
	}
	return std::string(home_path) + "/" + file_name;
}

int main(int argc, char const* argv[])
{
	try {
		CommandLineArgs args(argc, argv);
		time_t target_date = Parser::parse_time(args.get_date());
		TimeRangeFile time_range_file(get_time_ranges_file_path());
		TimeRange time_range(0, 0);
		string current_description_line;
		time_range_file.read(time_range, current_description_line);
		while (!time_range_file.eof()) {
			if (time_range.is_in_range(target_date)) {
				std::cout << current_description_line << std::endl;
			}
			time_range_file.read(time_range, current_description_line);
		}
	} catch (const Exception & e) {
		std::cerr << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknown Exception" << std::endl;
	}
	return 0;
}



