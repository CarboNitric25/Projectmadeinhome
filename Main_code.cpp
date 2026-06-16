#include <iostream>
#include <string>
#include <algorithm>

namespace ns1 {
	using namespace std;
	int is_declared = 0;
	string choice;
	string mainl;
	string var1;
	string mainlineinput;
	string closesyskeyword = "sys-exit";
	string programendedmsg = "-/The program is ended.";
};

std::string InputSystem() {
	using namespace std;
	using namespace ns1;
	do {
		cout << "$- ";
		getline(cin, mainlineinput);
		mainlineinput.erase(remove(mainlineinput.begin(), mainlineinput.end(), ' '), mainlineinput.end());
		if (mainlineinput == "sys-out,msg:") {
			cout << "-> msg: ";
			string msg;
			getline(cin, msg);
			if (is_declared == 1 and msg == "var1") {
				cout << "-> " << var1 << "\n";
			}
			else {
				cout << "-output: " << "\"" << msg << "\" \n";
			};
			
		}
		else if (mainlineinput == "sys-exit") {
			continue;
		}
		else if (mainlineinput == "") {
			cout << "-> Please enter a letter or number etc.\n";
		}
		else if (mainlineinput == "sys-input") {
			cout << "-input: ";
			getline(cin, mainl);
			cout << "-Please select a way to use this input: -asg or -done: \n";
			cout << "$- ";
			getline(cin, choice);
			if (choice == "-asg") {
				var1 = mainl;
				cout << "-The input has been added to var1 space.\n";
				is_declared = 1;
			}
			else if (choice == "-done") {
				continue;
			}
			else {
				cout << "The variable changes was discarded.\n";
			};
		}
		else {
			cout << "-> No matching found.\n";
		};
	}while(mainlineinput != closesyskeyword);
	
	return programendedmsg;
};


int main() {
	int start = 1;
	using namespace std;
	InputSystem();

	return 0;
}
