
#include <iostream>

#include "Performance.h"

// static init
bool Performance::debugMode = false;

std::chrono::high_resolution_clock::time_point Performance::startPoint = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point Performance::endPoint = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point Performance::printPoint = std::chrono::high_resolution_clock::now();

long long Performance::start = 0;
long long Performance::end = 0;
long long Performance::lastPrint = 0;

std::map<std::string, long long> Performance::TimeLogger = {};


void Performance::Start()
{
	if (debugMode)
	{
		// start time
		startPoint = std::chrono::high_resolution_clock::now();
	}
}

void Performance::Lap(const std::string& subjectName)
{
	if (debugMode)
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
}

void Performance::Stop(const std::string& subjectName)
{
	if (debugMode)
	{
		// stop time
		endPoint = std::chrono::high_resolution_clock::now();

		// convert to decimal
		start = std::chrono::time_point_cast<std::chrono::microseconds>(startPoint).time_since_epoch().count();
		end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();

		// log time
		TimeLogger.insert(std::make_pair<const std::string&, long long>(subjectName, end - start));
	}
}

void Performance::PrintTimeLog()
{
	if (debugMode && IntervalElapsed(1000))
	{
		// accumalated time
		long long totalTime = 0;
		for (const auto& tl : TimeLogger)
		{
			totalTime += tl.second;
		}
		// individual timed modules
		for (auto itr = TimeLogger.rbegin(); itr != TimeLogger.rend(); ++itr)
		{
			// console printing decoration
			std::cout << itr->first;
			if (itr->first.size() < 5) std::cout << "\t";
			if (itr->first.size() < 11) std::cout << "\t";
			std::cout << ": " << itr->second << " us(" <<  itr->second * 0.001 << "ms)";
			if (itr->second < 10) std::cout << "\t";
			std::cout << "\t : " <<  ((float)itr->second / totalTime) * 100 << "%" << std::endl;
		}

		// spacing
		std::cout << "\n ///////////////////////// \n" << std::endl;

		// sync time
		printPoint = std::chrono::high_resolution_clock::now();
		
		// clear map
		TimeLogger.clear();
	}
}

// returns true if time passed
bool Performance::IntervalElapsed(long long milliseconds)
{
	// convert to decimal
	lastPrint = std::chrono::time_point_cast<std::chrono::milliseconds>(printPoint).time_since_epoch().count();
	long long now = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();

	// print iteration time in milliseconds
	if ((now - lastPrint) > milliseconds)
	{
		return true;
	}
		return false;	
}