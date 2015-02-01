#pragma once
#include <fstream>
#include "TimeRange.hpp"

class TimeRangeFile {

private:
	std::ifstream _file_stream;

public:
	TimeRangeFile(const std::string & file_path);
	~TimeRangeFile() = default;
	void read(TimeRange & time_ranges);
	bool eof() const;
	static std::string get_default_path();
};
