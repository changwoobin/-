#include "HTMLWriter.h"
#include <iostream>
#include <fstream>
using namespace std;
HTMLWriter::HTMLWriter()
	:DocWriter("noname.html", "nocontent"){
	cout << "HTMLWriter 积己磊" << endl;
}
HTMLWriter::~HTMLWriter(){
	cout << "HTMLWriter 家戈磊" << endl;
}

void HTMLWriter::Write(){
	ofstream fout(fileName);
	fout << "<html><head><title>Greenjoa Homepage</title></head>";
	fout << "<body><h1>202411365 厘快后</h1><font face='" 
		<< fontName << "' size='" 
		<< fontSize << "' color='" 
		<< fontColor << "'>"
		<< content 
		<< "</body></html>";
}

void HTMLWriter::SetFont(const string& fontName, int fontSize, const string& fontColor){
	this->fontName = fontName;
	this->fontSize = fontSize;
	this->fontColor = fontColor;
}

HTMLWriter& HTMLWriter::operator<<(const string& item)
{
	content += "<br>" + item + "<br>";
	return *this;
}

HTMLWriter& HTMLWriter::operator<<(const int& num)
{
	content += to_string(num);
	return *this;
}