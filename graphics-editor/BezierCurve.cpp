#include "BezierCurve.h"

BezierCurve::BezierCurve(std::shared_ptr<GlobalStorage> s) {
	store = std::move(s);
}

void BezierCurve::handleClick(wxMouseEvent& event) {
	int x = event.GetX();
	int y = event.GetY();
	store->currentItem.Add(wxPoint(x, y));
}