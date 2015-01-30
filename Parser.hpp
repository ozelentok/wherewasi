#pragma once
#include <string>

using std::string;

struct TIME_RANGE {
	time_t start;
	time_t end;
};

class Parser {
public:

	static time_t parse_time(const string & s);
	static TIME_RANGE parse_time_range(const string & s);
	static unsigned int parse_digit(const char ch);
	static int parse_tm_int(const string & s, unsigned int & pos);

	private:

	static bool is_date_delimiter(const char ch);
	Parser(){};
	Parser(const Parser & other){};
	virtual ~Parser() = 0;
};
