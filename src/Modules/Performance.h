#pragma once

#include <map>
#include <string>
#include <chrono>

struct Performance
{
	void Start();
	void Lap(const std::string& subjectName);
	void Stop(const std::string& subjectName);


	void PrintTimeLog();

	std::map<std::string, long long> TimeLogger;

private:

	std::chrono::high_resolution_clock::time_point startPoint;
	std::chrono::high_resolution_clock::time_point endPoint;

	long long start = 0;
	long long end = 0;

};

