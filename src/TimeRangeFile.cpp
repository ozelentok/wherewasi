#include "TimeRangeFile.hpp"
#include "TimeRange.hpp"
#include "Parser.hpp"
#include "Exception.hpp"

TimeRangeFile::TimeRangeFile(const std::string & file_path)
{
	_file_stream.open(file_path, std::ifstream::in);
	if (_file_stream.fail()) {
		throw IOException("Opening " + file_path + " failed");
	}
}

void TimeRangeFile::read(TimeRange & time_ranges)
{
	std::string range_line;
	std::string description;
	std::getline(_file_stream, range_line);
	if (_file_stream.bad()) {
		throw IOException("Failed reading time range file");
	}
	if (_file_stream.eof()) {
		return;
	}

	std::getline(_file_stream, description);
	if (_file_stream.bad()) {
		throw IOException("Failed reading time range file");
	}
	if (_file_stream.eof()) {
		throw IOException("Malformed time range file");
	}

	try {
		time_ranges = Parser::parse_time_range(range_line, description);
	}
	catch (const ParseException & e) {
		throw IOException("Malformed time range file");
	}
}

bool TimeRangeFile::eof() const
{
	return _file_stream.eof();
}

std::string TimeRangeFile::get_default_path()
{
	static const std::string file_name = ".wherewasi";
	char * home_path = getenv("HOME");
	if (home_path == NULL)
	{
		throw EnvironmentException("Home directory not found");
	}
	return (std::string(home_path) + "/" + file_name);
}
