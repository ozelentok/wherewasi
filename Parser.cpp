#include <stdexcept>
#include <string>
#include <iostream>
#include <ctime>
#include "Parser.hpp"
#include "TimeRange.hpp"
#include "Exception.hpp"

using std::time_t;
using std::string;

time_t Parser::parse_time(const string & s)
{
	using std::tm;
	tm time_data = {0};
	unsigned int pos = 0;
	time_t epoch_time = 0;

	try {
		time_data.tm_year = parse_tm_int(s, pos) - 1900;
		time_data.tm_mon = parse_tm_int(s, pos) - 1;
		time_data.tm_mday = parse_tm_int(s, pos);
	} catch (const ParseException & e) {
		throw ParseException("Malformed time");
	}

	if (time_data.tm_year < 0) {
		throw ParseException("Epoch time could not be represented");
	}

	if (time_data.tm_mon < 0 || time_data.tm_mon > 11) {
		throw ParseException("Epoch time could not be represented");
	}

	if (time_data.tm_mday < 0 || time_data.tm_mday > 31) {
		throw ParseException("Epoch time could not be represented");
	}

	epoch_time = mktime(&time_data);
	if (epoch_time == -1) {
		throw ParseException("Epoch time could not be represented");
	}
	return epoch_time;
}

TimeRange Parser::parse_time_range(const string & s)
{
	size_t space_index = s.find(' ');
	if (space_index == string::npos) {
		throw ParseException("Malformed time range");
	}
	if (space_index + 1 > s.length()) {
		throw ParseException("Malformed time range");
	}

	time_t start = parse_time(s);
	time_t end = parse_time(s.substr(space_index + 1));
	return TimeRange(start, end);
}

unsigned int Parser::parse_digit(const char digit_char)
{
	if (digit_char < '0' || digit_char > '9') {
		throw ParseException("Character is not a digit");
	}
	return digit_char - '0';
}

int Parser::parse_tm_int(const string & s, unsigned int & pos)
{
	int value = 0;
	if (pos >= s.length()) {
		throw ParseException("Position is out of range");
	}
	for (; pos < s.length() && !is_date_delimiter(s[pos]); pos += 1) {
			value *= 10;
			value += parse_digit(s[pos]);
	}
	pos += 1;
	return value;
}

inline bool Parser::is_date_delimiter(const char ch) noexcept
{
	return (ch == '-' || ch == '/' || ch == ' ');
}


