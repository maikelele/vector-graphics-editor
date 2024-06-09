#include "Circle.h"
Circle::Circle(std::shared_ptr<GlobalStorage> s) {
	store = std::move(s);
	count = 0;
}

void Circle::handleClick(wxMouseEvent& event) {
	int x = event.GetX();
	int y = event.GetY();
	store->currentItem.Add(wxPoint(x, y));
	//second point: save currentItem and clear
	if (count == 1) {
		store->commitCurrentItem();
		count = 0;
	}
	else {
		count++;
	}
}