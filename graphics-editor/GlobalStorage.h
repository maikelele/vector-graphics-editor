#pragma once
#include "iostream"
#include "vector"
#include "Item.h"

class GlobalStorage
{
public:
	 std::vector<Item> items; // vector of Items containing points(wxPoint) and colour that define objects to draw 
	 bool editMode = false;
	 int editID; // 0 - line, 1 - bezier, 2 - circle, 3 - rect, 4 - poly, 5 - inscPoly
	 Item currentItem = Item();
	 wxColor currentColor = wxColor(RGB(255,0,0));
};

