#pragma once
#include <chrono>
#include <string>

class Stopwatch
{
public:
	void start();
	void stop();
	void restart();
	void print_elapsed(const std::string& label) const;
	void print_elapsed_us(const std::string& label) const;
	void print_total_elapsed(const std::string& label) const;

	int get_elapsed_time_microseconds() const;
	int get_elapsed_time_milliseconds() const;
	int get_total_elapsed_time_milliseconds() const;
	int get_total_time_microseconds() const;


private:
	std::chrono::time_point<std::chrono::steady_clock> start_time_;
	std::chrono::time_point<std::chrono::steady_clock> end_time_;

};

