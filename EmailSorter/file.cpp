#include <iostream>
#include <fstream>
#include <string>
#include "folder.cpp"
using namespace std;

class file
{
private:
	string name;
	string path;
	double count;
	ofstream output;
public:
	void getInfo() {
		cout << "Enter file name: ";
		getline(cin, name);
		cout << "Enter Path: ";
		
	}
	void open(folder folder) {
		string path = folder.name + "\\" + name;
		output.open(path, ios::app);
	}
	void addString(folder folderName, string text) {
		output << text << endl;
	}
};