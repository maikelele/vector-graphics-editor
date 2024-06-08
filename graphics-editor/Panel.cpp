#include "Panel.h"


Panel::Panel(std::shared_ptr<GlobalStorage> s) {
	store = std::move(s);
}

void Panel::Draw(wxDC* dc) {
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();

	for (Item item : store->items) {
		switch (item.id) {
		case 0:
			dc->SetPen(wxPen(item.color, 3));
			dc->DrawLine(item.points[0], item.points[1]);
			break;
		}
	}
	return;
}