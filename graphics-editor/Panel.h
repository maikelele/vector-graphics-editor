#pragma once
#include <wx/wx.h>
#include "memory"
#include "GlobalStorage.h"

class Panel
{
public:
	Panel(std::shared_ptr<GlobalStorage> s);
	void Draw(wxDC * dc);
private:
	std::shared_ptr<GlobalStorage> store;
};

