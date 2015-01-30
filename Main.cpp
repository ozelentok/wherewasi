#include <stdexcept>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "CommandLineArgs.hpp"
#include "Parser.hpp"
#include <cstdlib>

using std::time_t;
using std::string;
using std::ifstream;

std::string get_time_ranges_file_path()
{
	static const std::string file_name = ".wherewasi";
	char * home_path = getenv("HOME");
	if (home_path == NULL)
	{
		throw std::runtime_error("Home directory not found");
	}
	return std::string(home_path) + "/" + file_name;
}

int main(int argc, char const* argv[])
{
	try {
		CommandLineArgs args(argc, argv);
		time_t target_date = Parser::parse_time(args.get_date());
		ifstream time_range_file(get_time_ranges_file_path(), std::ios_base::in);
		if (!time_range_file.good()) {
			throw std::invalid_argument("The time ranges file could not be opened");
		}
		string current_range_line;
		string current_description_line;
		std::getline(time_range_file, current_range_line);
		std::getline(time_range_file, current_description_line);
		while (!time_range_file.eof()) {
			TimeRange time_range = Parser::parse_time_range(current_range_line);
			if (time_range.is_in_range(target_date)) {
				std::cout << current_description_line << std::endl;
			}
			std::getline(time_range_file, current_range_line);
			std::getline(time_range_file, current_description_line);
		}
	} catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}



