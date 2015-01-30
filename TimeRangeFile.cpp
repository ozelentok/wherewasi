#include "TimeRangeFile.hpp"
#include "TimeRange.hpp"
#include "Parser.hpp"
#include "Exception.hpp"
#include <iostream>

TimeRangeFile::TimeRangeFile(const std::string & file_path)
{
	_file_stream.open(file_path, std::ifstream::in);
	if (_file_stream.fail()) {
		throw IOException("Opening " + file_path + " failed");
	}
}

void TimeRangeFile::read(TimeRange & time_range, std::string & description)
{
	std::string range_line;
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
		time_range = Parser::parse_time_range(range_line);
	}
	catch (const ParseException & e) {
		throw IOException("Malformed time range file");
	}
}

bool TimeRangeFile::eof() const
{
	return _file_stream.eof();
}
