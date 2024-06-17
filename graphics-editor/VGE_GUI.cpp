#include "VGE_GUI.h"

VGE_GUI::VGE_GUI(wxWindow* parent)
	:
	GUI(parent)
{
	store = std::make_shared<GlobalStorage>();
	simpleLine = SimpleLine(store);
	bezierCurve = BezierCurve(store);
	circle = Circle(store);
	rectangle = Rect(store);
	polygon = Poly(store);
	inscrPoly = InscribedPolygon(store);
	this->SetTitle("Vector graphics editor");
}

void VGE_GUI::onResize(wxSizeEvent& event)
{
	Repaint();
	event.Skip();
}

void VGE_GUI::onPanelClick(wxMouseEvent& event)
{
	if (!store->editMode) return;
	switch (store->editID) {
	case 0:
		simpleLine.handleClick(event);
		break;
	case 1:
		bezierCurve.handleClick(event);
		break;
	case 2:
		circle.handleClick(event);
		break;
	case 3:
		rectangle.handleClick(event);
		break;
	case 4:
		polygon.handleClick(event);
		break;
	case 5:
		inscrPoly.handleClick(event);
		break;
	default:
		wxLogMessage("we shouldn't be here");
	}
	Repaint();
}

void VGE_GUI::onFileLoad(wxCommandEvent& event)
{
	wxFileDialog openFileDialog(this, _("Open Data File"), "", "",
		"Text Files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return;  // User cancelled the dialog

	wxFileInputStream input_stream(openFileDialog.GetPath());
	if (!input_stream.IsOk()) {
		wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
		return;
	}


	wxTextInputStream text_in(input_stream);
	store->items.clear();  // Clear existing items

	wxString line;
	while (!input_stream.Eof()) {
		line = text_in.ReadLine();  // Correctly read the full line
		if (line.IsEmpty()) continue;
		wxStringTokenizer tokenizer(line, " ");
		int count = 0;
		Item item = Item();
		int id, size, posX, posY;
		wxUint32 colRGB;
		wxColor color;
		while (tokenizer.HasMoreTokens())
		{
			wxString token = tokenizer.GetNextToken();

			switch (count) {
			case 0:
				token.ToInt(&id);
				item.id = id;
				break;
			case 1:
				token.ToUInt(&colRGB);
				color.SetRGB(colRGB);
				item.color = color;
				break;
			case 2:
				token.ToInt(&size);
				item.vertexes_count = size;
				break;
			default:
				token.ToInt(&posX);
				token = tokenizer.GetNextToken();
				token.ToInt(&posY);
				item.points.push_back(wxPoint(posX, posY));
			}

			count++;
		}
		store->items.push_back(item);
	}

	Repaint();
}

void VGE_GUI::onFileSave(wxCommandEvent& event)
{
	wxFileDialog saveFileDialog(this, _("Save Data"), "", "",
		"Text Files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;  // User cancelled the dialog

	wxFile file(saveFileDialog.GetPath(), wxFile::write);
	if (!file.IsOpened()) {
		wxLogError("Cannot open file '%s' for writing.", saveFileDialog.GetPath());
		return;
	}

	wxFileOutputStream output_stream(file);
	if (!output_stream.IsOk()) {
		wxLogError("Cannot create output stream.");
		return;
	}

	wxTextOutputStream text_out(output_stream);  // Correct usage: Pass the output stream to the constructor
	for (const auto& item : store->items) {
		text_out << item.id << " "
			<< item.color.GetRGBA() << " "
			<< static_cast<int>(item.points.size());  // Casting size_t to long
		for (const auto& pt : item.points) {
			text_out << " " << pt.x << " " << pt.y;
		}
		text_out << "\n";
	}
}

void VGE_GUI::onColourPickerChange(wxColourPickerEvent& event)
{
	store->currentColor = event.GetColour();
}

void VGE_GUI::onLineClick(wxCommandEvent& event)
{
	if (store->editMode) {
		if (store->editID == 0) {
			store->clearCurrentItem();
			lineButton->SetBackgroundColour(wxNullColour);
			lineButton->Refresh();
		}
		return;
	}
	store->editMode = true;
	store->editID = 0;
	lineButton->SetBackgroundColour(activeColor);
	lineButton->Refresh();

}

void VGE_GUI::onBezierClick(wxCommandEvent& event)
{
	if (store->editMode) {
		if (store->editID == 1) {
			store->editMode = false;
			store->commitCurrentItem();
			bezierButton->SetBackgroundColour(wxNullColour);
			bezierButton->Refresh();
			Repaint();
		}
		return;
	}
	store->editMode = true;
	store->editID = 1;
	bezierButton->SetBackgroundColour(activeColor);
	bezierButton->Refresh();
}

void VGE_GUI::onCircleClick(wxCommandEvent& event)
{
	if (store->editMode) {
		if (store->editID == 2) {
			store->clearCurrentItem();
			circleButton->SetBackgroundColour(wxNullColour);
			circleButton->Refresh();
		}
		return;
	}
	store->editMode = true;
	store->editID = 2;
	circleButton->SetBackgroundColour(activeColor);
	circleButton->Refresh();
}

void VGE_GUI::onRectClick(wxCommandEvent& event)
{
	if (store->editMode) {
		if (store->editID == 3) {
			store->clearCurrentItem();
			rectButton->SetBackgroundColour(wxNullColour);
			rectButton->Refresh();
		}
		return;
	}
	store->editMode = true;
	store->editID = 3;

	rectButton->SetBackgroundColour(activeColor);
	rectButton->Refresh();
}

void VGE_GUI::onPolygonClick(wxCommandEvent& event)
{
	if (store->editMode) {
		if (store->editID == 4) {
			store->editMode = false;
			store->commitCurrentItem();
			polygonButton->SetBackgroundColour(wxNullColour);
			polygonButton->Refresh();
			Repaint();
		}
		return;
	}


	store->editMode = true;
	store->editID = 4;
	polygonButton->SetBackgroundColour(activeColor);
	polygonButton->Refresh();
}

void VGE_GUI::onInscPolyClick(wxCommandEvent& event)
{
	if (store->editMode) {
		if (store->editID == 5) {
			store->clearCurrentItem();
			inscPolyButton->SetBackgroundColour(wxNullColour);
			inscPolyButton->Refresh();
		}
		return;
	}

	wxTextEntryDialog dialog(this, wxT("Wprowadz liczbe wierzcholkow wielakata:"),
		wxT("Polygon Sides"), wxT("4"));
	if (dialog.ShowModal() == wxID_OK) {
		wxString input = dialog.GetValue();
		long sides;
		if (input.ToLong(&sides) && sides > 2) {
			store->currentItem.vertexes_count = sides;
		}
		else {
			wxMessageBox("Prosze wprowadzic liczbe wieksza od 2:", "Invalid Input", wxOK | wxICON_ERROR);
			return;
		}
	}
	else {
		return;
	}

	store->editMode = true;
	store->editID = 5;
	inscPolyButton->SetBackgroundColour(activeColor);
	inscPolyButton->Refresh();
}

void VGE_GUI::onClear(wxCommandEvent& event)
{
	if (store->editMode) return;
	store->items.clear();
	store->editID = -1;
	Repaint();
}


void VGE_GUI::Repaint()
{
	wxClientDC _dc(m_panel1);
	wxBufferedDC dc(&_dc);

	Panel panel = Panel(store);
	panel.Draw(&dc);
}