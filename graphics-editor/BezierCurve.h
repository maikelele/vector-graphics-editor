#pragma once
#include <wx/wx.h>
#include "memory"
#include "GlobalStorage.h"

class BezierCurve
{
public:
	BezierCurve() = default;
	BezierCurve(std::shared_ptr<GlobalStorage> s);
	void handleClick(wxMouseEvent& event);
private:
	std::shared_ptr<GlobalStorage> store;
};

