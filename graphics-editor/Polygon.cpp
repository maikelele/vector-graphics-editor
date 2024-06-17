#include "Polygon.h"

Poly::Poly(std::shared_ptr<GlobalStorage> s) : Poly() {
	store = std::move(s);
}

void Poly::handleClick(wxMouseEvent& event) {
	int x = event.GetX();
	int y = event.GetY();
	store->currentItem.Add(wxPoint(x, y));
}