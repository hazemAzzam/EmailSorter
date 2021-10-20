#include <string>
#include <iostream>

using namespace std;

class Path
{
private:
	void setup() {
		string temp = "";
		for (int i =0; i < text.size(); i++) {
			/*if (text[i] == '"')
				continue;*/
			if (text[i] == '\\')
				temp += '\\';
			temp += text[i];
		}
		text = temp;
	}
public:
	string text;
	string getPathFromUser() {
		cout << "Enter path: ";
		getline(cin, text);
		setup();
		return text;
	}
};