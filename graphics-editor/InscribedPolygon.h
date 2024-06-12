#pragma once
#include <wx/wx.h>
#include "memory"
#include "GlobalStorage.h"
#include "Polygon.h"
#include "Circle.h"
#pragma once

class InscribedPolygon {
public:
	InscribedPolygon() : count(0) {};
	InscribedPolygon(std::shared_ptr<GlobalStorage> s);
	void handleClick(wxMouseEvent& event);

private:
	std::shared_ptr<GlobalStorage> store;
	int count;
};