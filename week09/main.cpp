#include "DocWriter.h"
#include "HTMLWriter.h"
#include <iostream>
using namespace std;

void showFile(const DocWriter* doc) {
	doc->readFile();
}

int main() {
	DocWriter doc("testttt.txt", "greenjoa");
	doc.Write();
	HTMLWriter doc1("test.html", "");
	doc1 << "»§" << 5 << "¿ìÀ¯" << 3;
	doc1.Write();
	showFile(&doc1);
	cout << "-----------------" << endl;
	showFile(&doc);

	//DocWriter doc1;
	//HTMLWriter html1;
	////html1 = doc1;
	//doc1 = html1;
	//DocWriter& doc2 = html1;
	//DocWriter* doc3 = &html1;
	//doc3->Write();

	/*HTMLWriter html1;
	html1.Write();

	HTMLWriter html2("index.html", "greenjoa");
	html2.SetFont("±¼¸²Ã¼", 30, "red");
	html2.Write();*/

	//DocWriter doc1;
	//doc1.Write();

	//DocWriter doc2("greenjoa.txt", "greenjoa");
	//doc2.Write();
	return 0;
}