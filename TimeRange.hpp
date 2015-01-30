#pragma once
#include "ctime"

class TimeRange
{
	private:
		std::time_t _start;
		std::time_t _end;
	public:
		TimeRange(std::time_t start, std::time_t end);
		TimeRange(const TimeRange & other) noexcept;
		TimeRange(TimeRange && other) noexcept;
		TimeRange & operator=(const TimeRange & other) noexcept;
		TimeRange & operator=(TimeRange && other) noexcept;
		~TimeRange() = default;
		bool is_in_range(std::time_t time_entry) const;
};
