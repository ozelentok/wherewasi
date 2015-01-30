#include <stdexcept>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "CommandLineArgs.hpp"
#include "Parser.hpp"

using std::time_t;
using std::string;
using std::ifstream;

int main(int argc, char const* argv[])
{
	try {
		CommandLineArgs args(argc, argv);
		time_t target_date = Parser::parse_time(args.get_date());
		ifstream time_range_file("/etc/wherewasi.ranges", std::ios_base::in);
		if (!time_range_file.good()) {
			throw std::invalid_argument("File is not valid");
		}
		string current_range_line;
		string current_description_line;
		TIME_RANGE time_range = {0};
		std::getline(time_range_file, current_range_line);
		std::getline(time_range_file, current_description_line);
		while (time_range_file.good()) {
			time_range = Parser::parse_time_range(current_range_line);
			if (target_date >= time_range.start && target_date <= time_range.end) {
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



