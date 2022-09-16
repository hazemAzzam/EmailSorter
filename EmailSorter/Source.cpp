#include <iostream>
#include <fstream>
#include <string>
#include "path.cpp"
using namespace std;

class Domain
{
public:
	string name;
	string chare;
	double count;
	ofstream output;
	Path folder;

	void getNamefromChare() {
		name = "";
		for (int i = 0; i < chare.size(); i++) {
			name += chare[i];
		}
	}
	void addEmail(string email)
	{
		if (!output.is_open())
			output.open(folder.text + "\\" + name + ".txt", ios::app);
		output << email << endl;	
	}
};

int main()
{
	Path inputPath;
	Domain domains[26];
	int numberOfElementsInDomain = 0;
	Path folderPath;

	// take folder path from user
	cout << "(Output folder) ";
	folderPath.getPathFromUser();
	
	// first take domains from user
	int enterNewDomain = 1;
	while (enterNewDomain == 1) {
		cout << "Enter Domain Name: ";
		cin >> domains[numberOfElementsInDomain].chare;
		domains[numberOfElementsInDomain].getNamefromChare();
		domains[numberOfElementsInDomain].count = 0;
		domains[numberOfElementsInDomain].folder = folderPath;
		numberOfElementsInDomain++;
		cout << "Another domain ?(1 - 0): ";
		cin >> enterNewDomain;
	}

	// then take input file path from user
	cin.ignore();
	cout << "(input) ";
	inputPath.getPathFromUser();

	// create ifstream for input file 
	cout << inputPath.text << endl;
	ifstream input(inputPath.text);

	// some output
	cout << "Output folder: " << folderPath.text << endl;
	cout << "Number of domains: " << numberOfElementsInDomain << endl;
	cout << "Domains{ ";
	for (int i = 0; i < numberOfElementsInDomain; i++)
		cout << domains[i].name << " ";
	cout << "}\n";

	// then start search
	string text = "";
	for (int i = 0; i < numberOfElementsInDomain; i++) {
		while (input >> text) {
			if (text.find(domains[i].name) != string::npos) {
				domains[i].addEmail(text);
				domains[i].count++;
				/*if (int(domains[i].count) % 1 == 0) {
					system("cls");
					cout << "domain name: " << domains[i].name;
					cout << "   counter: " << domains[i].count << endl;
				}*/
			}
		}
		input.clear();
		input.seekg(0);
	}
	cout << endl;
	for (int i = 0; i < numberOfElementsInDomain; i++) {
		cout << "domain name: " << domains[i].name;
		cout << "    counter: " << domains[i].count << endl;
	}

	system("pause");
	return 0;
}
