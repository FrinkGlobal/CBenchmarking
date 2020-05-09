#include "Stopwatch.h"

#include <iostream>

void Stopwatch::start()
{
	this->start_time_ = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop()
{
	this->end_time_ = std::chrono::high_resolution_clock::now();
}

void Stopwatch::restart()
{
	this->start();
}

void Stopwatch::print_elapsed(const std::string& label) const
{
	std::cout << label << " took " << this->get_elapsed_time_milliseconds() << " ms.\n" << std::endl;
}

void Stopwatch::print_elapsed_us(const std::string& label) const
{
	std::cout << label << " took " << this->get_elapsed_time_microseconds() << " us.\n" << std::endl;
}

void Stopwatch::print_total_elapsed(const std::string& label) const
{
	std::cout << label << " took " << this->get_total_elapsed_time_milliseconds() << " ms." << std::endl;
}

int Stopwatch::get_elapsed_time_microseconds() const
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - this->start_time_).count();
}

int Stopwatch::get_total_time_microseconds() const
{
	return std::chrono::duration_cast<std::chrono::microseconds>(this->end_time_ - this->start_time_).count();
}

int Stopwatch::get_elapsed_time_milliseconds() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - this->start_time_).count();
}

int Stopwatch::get_total_elapsed_time_milliseconds() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(this->end_time_ - this->start_time_).count();
}
