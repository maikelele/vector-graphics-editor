#include "InscribedPolygon.h"

InscribedPolygon::InscribedPolygon(std::shared_ptr<GlobalStorage> s) : InscribedPolygon() {
	store = std::move(s);
}

double pointDistance1(wxPoint pt1, wxPoint pt2) {
	int dx = pt2.x - pt1.x;
	int dy = pt2.y - pt1.y;
	return std::sqrt(dx * dx + dy * dy);
}

void InscribedPolygon::handleClick(wxMouseEvent& event) {
	int x = event.GetX();
	int y = event.GetY();
	store->currentItem.Add(wxPoint(x, y));

	if (count == 1) {
		double angleIncrement = 2 * M_PI / store->currentItem.vertexes_count;
		for (int i = 0; i < store->currentItem.vertexes_count; ++i) {
			double angle = i * angleIncrement;
			double radius = pointDistance1(store->currentItem.points[0], store->currentItem.points[1]);
			int x = store->currentItem.points[0].x + radius * cos(angle);
			int y = store->currentItem.points[0].y + radius * sin(angle);
			store->currentItem.Add(wxPoint(x, y));
		}
		store->commitCurrentItem();
		count = 0;
	}
	else {
		count++;
	}

}