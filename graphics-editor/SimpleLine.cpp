#include "SimpleLine.h"

SimpleLine::SimpleLine(std::shared_ptr<GlobalStorage> s) {
	store = std::move(s);
	count = 0;
}

void SimpleLine::handleClick(wxMouseEvent& event) {
	int x = event.GetX();
	int y = event.GetY();
	store->currentItem.Add(wxPoint(x, y));
	//second point: save currentItem and clear
	if (count == 1) {
		store->currentItem.color = store->currentColor;
		store->currentItem.id = store->editID;
		store->items.push_back(store->currentItem);
		store->currentItem = Item();
		count = 0;
	}
	else {
		count++;
	}

}