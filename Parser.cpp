#include <stdexcept>
#include <ctime>
#include <string>
#include <iostream>
#include "Parser.hpp"

using std::time_t;
using std::string;

time_t Parser::parse_time(const string & s)
{
	using std::tm;
	tm time_data = {0};
	unsigned int pos = 0;
	time_t epoch_time = 0;

	time_data.tm_year = parse_tm_int(s, pos) - 1900;
	if (time_data.tm_year < 0) {
		throw std::invalid_argument("Epoch time could not be represented");
	}
	time_data.tm_mon = parse_tm_int(s, pos) - 1;
	if (time_data.tm_mon < 0 || time_data.tm_mon > 11) {
		throw std::invalid_argument("Epoch time could not be represented");
	}
	time_data.tm_mday = parse_tm_int(s, pos);
	if (time_data.tm_mday < 0 || time_data.tm_mday > 31) {
		throw std::invalid_argument("Epoch time could not be represented");
	}

	epoch_time = mktime(&time_data);
	if (epoch_time == -1) {
		throw std::invalid_argument("Epoch time could not be represented");
	}
	return epoch_time;
}

TIME_RANGE Parser::parse_time_range(const string & s)
{
	size_t space_index = s.find(' ');
	if (space_index == string::npos) {
		throw std::invalid_argument("Time range could not be parsed - no space");
	}
	if (space_index + 1 > s.length()) {
		throw std::invalid_argument("Time range could not be parsed out of bounds");
	}

	TIME_RANGE time_range = {0};
	time_range.start = parse_time(s);
	time_range.end = parse_time(s.substr(space_index + 1));
	return time_range;
}

unsigned int Parser::parse_digit(const char digit_char)
{
	if (digit_char < '0' || digit_char > '9') {
		throw std::invalid_argument("The character is not digit");
	}
	return digit_char - '0';
}

inline bool Parser::is_date_delimiter(const char ch)
{
	return (ch == '-' || ch == '/' || ch == ' ');
}

int Parser::parse_tm_int(const string & s, unsigned int & pos)
{
	int value = 0;
	if (pos >= s.length()) {
		throw std::invalid_argument("Position is out of range");
	}
	for (; pos < s.length() && !is_date_delimiter(s[pos]); pos += 1) {
			value *= 10;
			value += parse_digit(s[pos]);
	}
	pos += 1;
	return value;
}
