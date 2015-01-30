#include <ctime>
#include <algorithm>
#include <utility>
#include "TimeRange.hpp"

TimeRange::TimeRange(std::time_t start, std::time_t end):
	_start(start),
	_end(end)
{}

TimeRange::TimeRange(const TimeRange & other) noexcept
{
	operator=(other);
}

TimeRange::TimeRange(TimeRange && other) noexcept
	: _start(0), _end(0)
{
	std::swap(_start, other._start);
	std::swap(_end, other._end);
}

TimeRange & TimeRange::operator=(const TimeRange & other) noexcept
{
	_start = other._start;
	_end = other._end;
	return *this;
}

TimeRange & TimeRange::operator=(TimeRange && other) noexcept
{
	std::swap(_start, other._start);
	std::swap(_end, other._end);
	return *this;
}

TimeRange::~TimeRange()
{};

bool TimeRange::is_in_range(std::time_t time_entry)
{
	return (time_entry >= _start && time_entry <= _end);
}
