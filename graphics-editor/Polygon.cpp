#include "Polygon.h"

Poly::Poly(std::shared_ptr<GlobalStorage> s) : Poly() {
	store = std::move(s);
}

void Poly::handleClick(wxMouseEvent& event) {
	int x = event.GetX();
	int y = event.GetY();
	store->currentItem.Add(wxPoint(x, y));

	if (count == store->currentItem.vertexes_count - 1) {
		store->commitCurrentItem();
		count = 0;
	}
	else {
		count++;
	}
}