#pragma once
#include <ctime>
#include <string>

class TimeRange
{
	private:
		std::time_t _start;
		std::time_t _end;
		std::string _description;
	public:
		TimeRange(std::time_t start, std::time_t end, 
				const std::string & description);
		TimeRange(const TimeRange & other) noexcept;
		TimeRange(TimeRange && other) noexcept;
		TimeRange & operator=(const TimeRange & other) noexcept;
		TimeRange & operator=(TimeRange && other) noexcept;
		~TimeRange() = default;
		std::string to_string() const;
		bool is_in_range(std::time_t time_entry) const noexcept;
};
