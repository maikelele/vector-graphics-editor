#pragma once
#include <wx/wx.h>
#include "memory"
#include "GlobalStorage.h"

class SimpleLine
{
public:
	SimpleLine(): count(0){};
	SimpleLine(std::shared_ptr<GlobalStorage> s);
	void handleClick(wxMouseEvent& event);
private:
	std::shared_ptr<GlobalStorage> store;
	int count;
};

