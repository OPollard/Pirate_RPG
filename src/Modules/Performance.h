#pragma once

#include <map>
#include <string>
#include <chrono>

struct Performance
{
	static void Start();
	static void Lap(const std::string& subjectName);
	static void Stop(const std::string& subjectName);

	static bool IntervalElapsed(long long milliseconds);

	static void PrintTimeLog();

	static bool debugMode;

private:

	static std::chrono::high_resolution_clock::time_point startPoint;
	static std::chrono::high_resolution_clock::time_point endPoint;
	static std::chrono::high_resolution_clock::time_point printPoint;

	static long long start;
	static long long end;
	static long long lastPrint;

	static std::map<std::string, long long> TimeLogger;

};

