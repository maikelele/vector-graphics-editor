#include "GlobalStorage.h"

void GlobalStorage::commitCurrentItem() {
	currentItem.color = currentColor;
	currentItem.id = editID;
	items.push_back(currentItem);
	currentItem = Item();
}

void GlobalStorage::clearCurrentItem() {
	editMode = false;
	editID = -1;
	currentItem = Item();
}