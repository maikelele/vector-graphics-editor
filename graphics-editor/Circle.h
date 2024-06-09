#pragma once
#include <wx/wx.h>
#include "memory"
#include "GlobalStorage.h"

class Circle
{
public:
	Circle() : count(0) {};
	Circle(std::shared_ptr<GlobalStorage> s);
	void handleClick(wxMouseEvent& event);
private:
	std::shared_ptr<GlobalStorage> store;
	int count;
};