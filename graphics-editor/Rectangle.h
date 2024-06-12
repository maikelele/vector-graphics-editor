#pragma once
#include <wx/wx.h>
#include "memory"
#include "GlobalStorage.h"

class Rect {
public:
	Rect() : count(0) {};
	Rect(std::shared_ptr<GlobalStorage> s);
	void handleClick(wxMouseEvent& event);

private:
	std::shared_ptr<GlobalStorage> store;
	int count;
};