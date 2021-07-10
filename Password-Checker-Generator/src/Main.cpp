/*	Project Name: Password Processor (Checker & Generator)
	Author: QGH
	Description: check and generate passwords
		1. Ask if check or generate passwords
		2. Check user password strength, if not strong enough,
		options of auto generating password is avaible
		3. Run until user stop the program
*/

#include <iostream>
#include <string>

using namespace std;

int askForOptions();
bool ifContinue();
string askForInput();

// ask user for options
int askForOptions() {
	int decision;
	cout << "To check password strength, type \"1\".\nTo generate strong password type \"2\".\n";
	// if user input is not right, warning and ask again
	cin >> decision;
	cout << "\n";

	return decision;
}

// ask user if continue 
bool ifContinue() {
	string decision; 
	cout << "To continue type \"yes\".\nTo stop type \"no\"\n";
	cin >> decision;
	cout << "\n";
	
	//convert string into uppercase
	for (int i = 0; i < decision.length(); i++) {
		decision[i] = toupper(decision[i]);
	}
	cout << decision;

	if (decision.compare("YES")) {
		return true;
	}
	else {
		return false;
	}
}

// ask user for inputs
string askForInput() {

	string input;


	
	return input;
}

// main functions
int main() {
	
	bool check = ifContinue();
	cout << check;
	while (ifContinue()) {
		if (askForOptions() == 1) {
			cout <<"you choose 1";
		}
		else {
			cout << "you choose 2";
		}
	}

}