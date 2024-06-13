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

double pointDistance(wxPoint pt1, wxPoint pt2) {
	int dx = pt2.x - pt1.x;
	int dy = pt2.y - pt1.y;
	return std::sqrt(dx * dx + dy * dy);
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
		case 2:
			dc->SetBrush(*wxTRANSPARENT_BRUSH);
			dc->DrawCircle(item.points[0], pointDistance(item.points[0], item.points[1]));
			break;
		case 3:
			dc->SetBrush(*wxTRANSPARENT_BRUSH);
			dc->DrawRectangle(wxRect(item.points[0], item.points[1]));
			break;
		case 4:
			dc->SetBrush(*wxTRANSPARENT_BRUSH);
			dc->DrawPolygon(vectorToWxPointList(item.points));
			break;
		case 5:
			dc->SetBrush(*wxTRANSPARENT_BRUSH);
			dc->DrawCircle(item.points[0], pointDistance(item.points[0], item.points[1]));
			dc->DrawPolygon(item.points.size() - 2, &item.points[2]);

			break;
		}
	}

	// Draw the current object
	dc->SetPen(wxPen(store->currentColor, defaultPenWidth));
	switch (store->editID) {
	case 1:
		if(store->currentItem.points.size() >= 2)
			dc->DrawSpline(vectorToWxPointList(store->currentItem.points));
		break;
	case 4:
		dc->SetBrush(*wxTRANSPARENT_BRUSH);
		dc->DrawPolygon(vectorToWxPointList(store->currentItem.points));
		break;
	}

	return;
}