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
string passwordGenerator();
string checkPasswordStrength();
bool checkUppercase(string password);
bool checkSymbol(string password);


// ask user for options
int askForOptions() {
	int decision;
	cout << "To generate strong password type \"1\".\nTo check password strength type \"2\".\n";
	// if user input is not right, warning and ask again
	cin >> decision;
	cout << "\n";

	while (cin.fail())
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
		// next, request user reinput
		cout << "Please input an integer!\n";
		cout << "To generate strong password type \"1\".\nTo check password strength type \"2\".\n";
		// if user input is not right, warning and ask again
		cin >> decision;
	}

	return decision;
}

// ask user if continue 
bool ifContinue() {
	string decision;

		cout << "\nTo continue type \"yes\".\nTo stop type \"no\"\n";
		cin >> decision;
		cout << "\n";

		// convert string into uppercase
		for (int i = 0; i < decision.length(); i++) {
			decision[i] = toupper(decision[i]);
		}
		
		// check for valid input
		while (!(decision.compare("YES") == 0 || decision.compare("NO") == 0)) {
			cout << "Invalid input!\n";

			cout << "\nTo continue type \"yes\".\nTo stop type \"no\"\n";
			cin >> decision;
			cout << "\n";

			// convert string into uppercase
			for (int i = 0; i < decision.length(); i++) {
				decision[i] = toupper(decision[i]);
			}
		} 

		if (decision.compare("YES")) {
			return true;
		}
		else if (decision.compare("NO")) {
			return false;
		}
	
}

// generate strong passwords
string passwordGenerator() {
	string password;
	char alphnum[] = "0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
	int alphnumLength = sizeof(alphnum);

	int passwordLength;
	do {
		cout << "Length of your strong password (at least 8 letters): ";
		cin >> passwordLength;

		// make sure valid input
		while (cin.fail())
		{
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			// next, request user reinput
			cout << "Please input an integer!\n";
			cout << "Length of your strong password (at least 8 letters): ";
			cin >> passwordLength;
		}

		if (passwordLength < 8 || passwordLength > 100) {
			cout << "Invalid password length! (8 < Length < 100) \n";
		}
	} while (passwordLength < 8 || passwordLength > 100);


	for (int i = 0; i < passwordLength; i++) {
		password = password + alphnum[rand() % alphnumLength];
	}
	
	return password;
}

// check user password strength
string checkPasswordStrength() {

	string userPassword;

	cout << "Your password: ";
	cin >> userPassword;

	if (userPassword.length() < 8) {
		return "Weak, not long enought; minimun 8 letters!";
	}
	// no letter or uppercase letter
	else if (!checkUppercase(userPassword)) { 
		return "Weak, no uppercase letters or any letters!";
	} 
	else  if (!checkSymbol(userPassword)) {
		return "Weak, no sepcial symbols/characters!";
	}
	else {
		return "Strong password!";
	}
}

// check if there is at least one uppercase or any letter
bool checkUppercase(string password) {
	for (int i = 0; i < password.length(); i++) {
		if (isupper(password[i])) {
			return true;
		}
	}
	
	return false;
}

// check if there is at least one symbol
bool checkSymbol(string password) {
	for (int i = 0; i < password.length(); i++) {
		if (!isalpha(password[i]) && !isdigit(password[i])) {
			return true;
		}
	}
	return false;
}

// main functions
int main() {
	
	 do {
		if (askForOptions() == 1) {
			srand(time(NULL));
			cout << passwordGenerator() << "\n";
		}
		else {
			do {
				cout << checkPasswordStrength() << "\n";
			} while (!ifContinue());
		}
	 } while (!ifContinue());

}