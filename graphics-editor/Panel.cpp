#include "Panel.h"


Panel::Panel(std::shared_ptr<GlobalStorage> s) {
	store = std::move(s);
}

void Panel::Draw(wxDC* dc) {
	//store->objectStore[0] = "panel";
	return;
}