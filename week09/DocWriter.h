#pragma once
#include <string>

using namespace std;

class DocWriter
{
protected:
	string fileName;
	string content;
public:
	DocWriter();
	DocWriter(const string& fileName, const string& content);
	~DocWriter();

	void SetFileName(const string& fileName);
	void SetContent(const string& content);

	void Write();
	DocWriter& operator<<(const string & item);
	DocWriter& operator<<(const int& num);
	void readFile();
	void readFile() const;
};

