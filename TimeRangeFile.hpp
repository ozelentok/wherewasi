#pragma once
#include <fstream>
#include "TimeRange.hpp"

class TimeRangeFile {

private:
	std::ifstream _file_stream;

public:
	TimeRangeFile(const std::string & file_path);
	~TimeRangeFile() = default;
	void read(TimeRange & time_range, std::string & description);
	bool eof() const;
};
