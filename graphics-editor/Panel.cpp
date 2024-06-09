#include "Panel.h"


Panel::Panel(std::shared_ptr<GlobalStorage> s) {
	store = std::move(s);
	defaultPenWidth = 3;
}

wxPointList* vectorToWxPointList(std::vector<wxPoint>& pts) {
	wxPointList* pointList = new wxPointList();
	for (wxPoint point : pts) {
		pointList->Append(new wxPoint(point));
	}
	return pointList;
}

void Panel::Draw(wxDC* dc) {
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();

	// Draw items commited to global storage
	for (Item item : store->items) {
		dc->SetPen(wxPen(item.color, defaultPenWidth));
		switch (item.id) {
		case 0:
			dc->DrawLine(item.points[0], item.points[1]);
			break;
		case 1:
			dc->DrawSpline(vectorToWxPointList(item.points));
			break;
		}
	}

	// Draw the current object
	switch (store->editID) {
	case 1:
		dc->SetPen(wxPen(store->currentColor, defaultPenWidth));
		if(store->currentItem.points.size() >= 2)
			dc->DrawSpline(vectorToWxPointList(store->currentItem.points));
		break;
	}

	return;
}