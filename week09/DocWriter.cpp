#include "DocWriter.h"
#include <iostream>
#include <fstream>

DocWriter::DocWriter():DocWriter("noname.txt", "nocontent")
{
}

DocWriter::DocWriter(const string& fileName, const string& content)
	: fileName(fileName), content(content)
{
	cout << "DocWriter 积己磊" << endl;
}

DocWriter::~DocWriter()
{
	cout << "DocWriter 家戈磊" << endl;
}

void DocWriter::SetFileName(const string& fileName)
{
	this->fileName = fileName;
}

void DocWriter::SetContent(const string& content)
{
	this->content = content;
}

void DocWriter::Write()
{
	ofstream fout(fileName);
	fout << "202411365 厘快后" << endl;
	fout << content << endl;
	
}

DocWriter& DocWriter::operator<<(const string& item)
{
	content += "\n" + item + "\n";
	return *this;
}

DocWriter& DocWriter::operator<<(const int& num)
{
	content += to_string(num);
	return *this;
}

void DocWriter::readFile()
{
	ifstream fin(fileName);
	if (fin.is_open()) {
		while (!fin.fail()) {
			string str;
			getline(fin, str);
			cout << str << endl;
		}
	}
}
void DocWriter::readFile() const
{
	ifstream fin(fileName);
	if (fin.is_open()) {
		while (!fin.fail()) {
			string str;
			getline(fin, str);
			cout << str << endl;
		}
	}
}

