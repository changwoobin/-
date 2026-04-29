#pragma once
#include "DocWriter.h"

class HTMLWriter: public DocWriter
{
protected:
	string fontName = "±Ã¼­Ã¼";
	int fontSize = 20;
	string fontColor = "blue";
public:
	HTMLWriter();
	~HTMLWriter();

	using DocWriter::DocWriter;

	void Write();

	void SetFont(const string& fontName, int fontSize, const string& fontColor);
	HTMLWriter& operator<<(const string& item);
	HTMLWriter& operator<<(const int& num);
};

