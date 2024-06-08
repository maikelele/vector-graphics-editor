#pragma once
#include "iostream"
#include "vector"

class GlobalStorage
{
public:
	//GlobalStorage() = default;
	//GlobalStorage(const GlobalStorage& other) = default;
	std::vector < std::string > objectStore;
protected:
	// std::vector<std::vector<double>> objectStore; // vector of vectors containing points that define objects to draw 
	// TODO: instead of double ^ it should be a struct or class Point with x and y variables
};

