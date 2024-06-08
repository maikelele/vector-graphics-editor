#pragma once
#include "string"
#include <wx/wx.h>

class Item
{
public:
	Item(std::vector<wxPoint> _points, std::string _colour) {
		points = _points;
		colour = _colour;
	}

	std::string colour;
	std::vector<wxPoint> points;
};

