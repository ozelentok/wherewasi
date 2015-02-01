#include <ctime>
#include <algorithm>
#include <utility>
#include "TimeRange.hpp"
#include <cassert>
#include "Utils.hpp"

TimeRange::TimeRange(std::time_t start, std::time_t end,
		const std::string & description)
	: _start(start),
		_end(end),
		_description(description)
{}

TimeRange::TimeRange(const TimeRange & other) noexcept
{
	operator=(other);
}

TimeRange::TimeRange(TimeRange && other) noexcept
	: _start(0), _end(0)
{
	operator=(other);
}

TimeRange & TimeRange::operator=(const TimeRange & other) noexcept
{
	_start = other._start;
	_end = other._end;
	_description = other._description;
	return *this;
}

TimeRange & TimeRange::operator=(TimeRange && other) noexcept
{
	std::swap(_start, other._start);
	std::swap(_end, other._end);
	std::swap(_description, other._description);
	return *this;
}

std::string TimeRange::to_string() const
{
	const int TIME_BUFFER_SIZE = 32;
	const char * TIME_FORMAT = "<%F>";
	char start_buffer[TIME_BUFFER_SIZE] = {0};
	char end_buffer[TIME_BUFFER_SIZE] = {0};
	tm start_tm = *localtime(&_start);
	tm end_tm = *localtime(&_end);
	int format_result = 0;
	_UNUSED(format_result);

	format_result = strftime(
			start_buffer, sizeof(start_buffer),
			TIME_FORMAT, &start_tm);
	assert(format_result != 0);

	format_result = strftime(
			end_buffer, sizeof(end_buffer),
			TIME_FORMAT, &end_tm);
	assert(format_result != 0);

	return std::string(start_buffer) + " " +
		_description + " " + end_buffer;
}

bool TimeRange::is_in_range(std::time_t time_entry) const noexcept
{
	return (time_entry >= _start && time_entry <= _end);
}
