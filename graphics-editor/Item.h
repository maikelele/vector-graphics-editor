#pragma once
#include "string"
#include <wx/wx.h>

class Item
{
public:
	Item() {
		points = std::vector<wxPoint>();
		colour = "";
	}
	Item(std::vector<wxPoint> _points, std::string _colour) {
		points = _points;
		colour = _colour;
	}
	void Add(wxPoint point) {
		points.push_back(point);
	}

	std::string colour;
	std::vector<wxPoint> points;
};

