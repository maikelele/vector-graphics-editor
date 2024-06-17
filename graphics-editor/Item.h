#pragma once
#include "string"
#include <wx/wx.h>

class  Item
{
public:
	Item() {
		points = std::vector<wxPoint>();
		color = "";
		id = 0;
		vertexes_count = 0;
	}
	Item(std::vector<wxPoint> _points, wxColor _color, int _id) {
		points = _points;
		color = _color;
		id = _id;
		vertexes_count = 0;
	}
	void Add(wxPoint point) {
		points.push_back(point);
	}

	wxColor color;
	std::vector<wxPoint> points;
	int id;
	int vertexes_count;
};

