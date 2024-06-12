#include "Rectangle.h"

Rect::Rect(std::shared_ptr<GlobalStorage> s) : Rect() {
	store = std::move(s);
}

void Rect::handleClick(wxMouseEvent& event) {
	int x = event.GetX();
	int y = event.GetY();
	store->currentItem.Add(wxPoint(x, y));

	if (count == 1) {
		store->commitCurrentItem();
		count = 0;
	}
	else {
		count++;
	}
}