
#include <iostream>

#include "Performance.h"


void Performance::Start()
{
	// start time
	startPoint = std::chrono::high_resolution_clock::now();
}

void Performance::Lap(const std::string& subjectName)
{
	// close time
	endPoint = std::chrono::high_resolution_clock::now();

	// convert to decimal
	start = std::chrono::time_point_cast<std::chrono::microseconds>(startPoint).time_since_epoch().count();
	end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();

	// log time
	TimeLogger.insert(std::make_pair<const std::string&, long long>(subjectName, end - start));

	// restart time
	startPoint = std::chrono::high_resolution_clock::now();
}

void Performance::Stop(const std::string& subjectName)
{
	// stop time
	endPoint = std::chrono::high_resolution_clock::now();

	// convert to decimal
	start = std::chrono::time_point_cast<std::chrono::microseconds>(startPoint).time_since_epoch().count();
	end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();

	// log time
	TimeLogger.insert(std::make_pair<const std::string&, long long>(subjectName, end - start));
}

void Performance::PrintTimeLog()
{
	// individual timed modules
	for (auto itr = TimeLogger.rbegin(); itr != TimeLogger.rend(); ++itr)
	{
		std::cout << itr->first << ": " << itr->second << " us(" << itr->second * 0.001 << "ms)" << std::endl;
	}

	std::cout << std::endl;

	// % representation of computing time
	long long totalTime = 0;
	for (const auto& tl : TimeLogger)
	{
		totalTime += tl.second;
	}
	for (auto itr = TimeLogger.rbegin(); itr != TimeLogger.rend(); ++itr)
	{
		std::cout << itr->first << ": " << ((float)(itr->second) / totalTime) * 100 << "%" << std::endl;
	}

	// spacing
	std::cout << "\n ///////////////////////// \n" << std::endl;
}