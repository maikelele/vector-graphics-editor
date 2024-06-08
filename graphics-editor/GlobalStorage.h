#pragma once
#include "iostream"
#include "vector"

class GlobalStorage
{
public:
	 std::vector<std::vector<double>> items; // vector of vectors containing points that define objects to draw 
	// TODO: instead of double ^ it should be a struct or class Point with x and y variables
};

