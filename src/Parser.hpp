#pragma once
#include <string>
#include "TimeRange.hpp"

class Parser {
public:

	static time_t parse_time(const std::string & s);
	static TimeRange parse_time_range(
		const std::string & times_line,
		const std::string & description);
	static unsigned int parse_digit(const char ch);
	static int parse_tm_int(const std::string & s, unsigned int & pos);

private:

	static bool is_date_delimiter(const char ch) noexcept;
	virtual ~Parser() = 0;
};
