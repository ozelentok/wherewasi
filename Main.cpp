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

int main(int argc, char const * argv[])
{
	try {
		CommandLineArgs args(argc, argv);
		time_t target_date = Parser::parse_time(args.get_date());
		TimeRangeFile time_range_file(TimeRangeFile::get_default_path());
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



