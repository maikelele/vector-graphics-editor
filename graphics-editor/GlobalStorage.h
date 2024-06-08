#pragma once
#include "iostream"
#include "vector"
#include "Item.h"

class GlobalStorage
{
public:
	 std::vector<Item> items; // vector of Items containing points(wxPoint) and colour that define objects to draw 
};

