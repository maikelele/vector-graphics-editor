#pragma once
#include <wx/wx.h>
#include "memory"
#include "GlobalStorage.h"

class Poly {
public:
	Poly() : count(0) {};
	Poly(std::shared_ptr<GlobalStorage> s);
	void handleClick(wxMouseEvent& event);

private:
	std::shared_ptr<GlobalStorage> store;
	int count;
	int vertexes_count;
};