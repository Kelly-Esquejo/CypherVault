
#include "prompts.h"
#include <unistd.h>
#include <conio.h> 


string commonPasswords[]  = {"qwerty", "password", "abc123", "uiop"};
//**********************************************************************
// Enumerator 
enum IN { 
	// 13 is ASCII for carriage 
	// return 
	IN_BACK = 8, 
	IN_RET = 13 

}; 

/*
	Creates new account. 
*/
void Prompts::newAccount (string &service, string &username, string &password){
	cout  << endl << endl << "----------------------------------------" << endl;
	cout << "|            Account Setup             |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Enter service or type 'exit' to quit: ";
	cin >> service;
	if(service == "exit"){
		return;
	}
	cout << "Enter email or username for " << service << ": ";
	cin >> username;
	cout << "Enter password for " << username << " on " << service << ": ";

	password = getPassword();

	// Checks validity of password
	bool isValid = true;
	while(isValid){
		// check length
		
		if(password.length() >= 12){
			bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

			cout << "Password length needs to be at least 12 characters." << endl;
			// check complexity
			// Does it include at least one special character, uppercase, lowercase, and number
			for (char ch : password){
				if (isupper(ch)) hasUpper = true;
				else if (islower(ch)) hasLower = true;
				else if (isdigit(ch)) hasDigit = true;
				else if (ispunct(ch)) hasSpecial = true;
			}

			// check if common password

			// check history

			isValid = false;
		}
	}
	
	bool validInput = true;
	cout << "Show password? Type 1 (yes) or 2 (no): ";
	string seePassword;

	while(validInput){
		cin >> seePassword;

		if(seePassword == "1"){
			cout << "Password: " << password << endl;
		}else if(seePassword == "2"){
			validInput = false;
		}else{
			cout << "Invalid input: Type 1 (yes) or 2 (no)" << endl;
		}
	}
	newcredential.setCredential(service, username, password);
}

/*
	Changes password while hiding user input as user types

*/
void Prompts::changePassword(string &password){
	cout << endl << endl << "-----------------------------------------" << endl;
	cout << "|          Changing Password            |" << endl;
	cout << "-----------------------------------------" << endl;

	cout << "Changing password for " << endl;
	// TODO: get service 

	// get user input for password
	cin >> password;

	// see if user wants to see password
	string seePassword;
	cout << "Show password? Type yes or no: ";
	bool validInput = true;
	while(validInput){
		cin >> seePassword;
		if(seePassword == "yes"){
			cout << "Password: " << password << endl;
			validInput = false;
		}else if(seePassword == "no"){
			validInput = false;
		}else{
			cout << "Invalid input: Type yes or no" << endl;
		}
	}
}

/*
	Accepts and hides the password with '*' as user types.
*/
string Prompts::getPassword(){ 
	// Stores the password 
	char sp = '*';
	string passwd = ""; 
	char input; 

	// Until condition is true 
	while (true) { 
		// Retrieves characters from the keyboard like cin
		input = getch(); 

		// if input is ENTER, return 
		if (input == '\r') { 
			cout << endl; 
			return passwd; 
		} else if (input == IN::IN_BACK && passwd.length() != 0) { 
			passwd.pop_back(); 

			// Cout statement is very 
			// important as it will erase 
			// previously printed character 
			cout << "\b \b"; 
			continue; 
		} 

		// Without using this, program 
		// will crash as \b can't be 
		// print in beginning of line 
		else if (input == IN::IN_BACK && passwd.length() == 0) { 
			continue; 
		} 

		passwd.push_back(input); 
		cout << sp; 
	} 
} 

void Prompts::changeUsername(string &username){
	cout << endl << endl << "-----------------------------------------" << endl;
	cout << "|          Changing Username             |" << endl;
	cout << "-----------------------------------------" << endl;

	cin >> username;
}

/*
	Prompts user for -__ to use in the query of deleteCredential();

*/
void Prompts::deleteAccount(string &){
	cout << "Enter which account to delete: " << endl;
	

	cout << endl << endl << "-----------------------------------------" << endl;
	cout << "|          Deleting Account              |" << endl;
	cout << "-----------------------------------------" << endl;

}

int Prompts::menu(){
	cout << "Enter: ";
	int choice;
	cin >> choice;
	if(choice < 0 || choice > 6){
		cout << "Invalid choice. 1-6 only.";
	}
	return choice;
}

void Prompts::printMenu(){
	cout << endl << endl << "-----------------------------------------" << endl;
	cout << "|                Menu                   |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "| 1. New Accounts                       |" << endl;
	cout << "| 4. Delete Account                     |" << endl;
	cout << "| 3. Change Account                     |" << endl;
	cout << "| 4. Change Password                    |" << endl;
	cout << "| 5. Help                               |" << endl;
	cout << "| 6. Exit                               |" << endl;
	cout << "-----------------------------------------" << endl;
}

/*
	Calls ___

*/
void Prompts::printInformation(){
	// Prompt user which record to display
	cout << "Enter the record ID you want to display: ";
	
	cout << endl << endl << "-----------------------------------------" << endl;
	cout << "|          Account Information          |" << endl;
	cout << "-----------------------------------------" << endl;
	//  cout << "Service: " << service << endl;
	// cout << "Email: " << username << endl;
	cout << "Password: ********" << endl;
	cout << "---------------------------" << endl;
}


void Prompts::displayHelp(){
	cout << endl << endl << "-----------------------------------------" << endl;
	cout << "|                Menu                   |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "| 1. New Accounts                       |" << endl;
	cout << "|    - Select this option to create a   |" << endl;
    cout << "|      new account. You will be asked   |" << endl;
    cout << "|      to provide necessary details     |" << endl;
    cout << "|      such as username and password.   |" << endl;
	cout << "|                                       |" << endl;
    cout << "| 2. Delete Account                     |" << endl;
    cout << "|    - Select this option to delete an  |" << endl;
    cout << "|      existing account. You will need  |" << endl;
    cout << "|      to confirm your choice to ensure |" << endl;
    cout << "|      that you do not delete an account|" << endl;
    cout << "|      by mistake.                      |" << endl;
    cout << "|                                       |" << endl;
    cout << "| 3. Change Account                     |" << endl;
    cout << "|    - Select this option to change the |" << endl;
    cout << "|      username or email associated with|" << endl;
    cout << "|      the current account. You will be |" << endl;
    cout << "|      asked to provide the new         |" << endl;
    cout << "|      username/email and confirm the   |" << endl;
    cout << "|      change.                          |" << endl;
    cout << "|                                       |" << endl;
    cout << "| 4. Change Password                    |" << endl;
    cout << "|    - Select this option to change the |" << endl;
    cout << "|      password of the current account. |" << endl;
    cout << "|      You will be asked to provide     |" << endl;
    cout << "|      your current password and the new|" << endl;
    cout << "|      password.                        |" << endl;
    cout << "|                                       |" << endl;
    cout << "| 5. Help                               |" << endl;
    cout << "|    - Select this option to view this  |" << endl;
    cout << "|      help menu, which provides        |" << endl;
    cout << "|      information about the various    |" << endl;
    cout << "|      options available in the main    |" << endl;
    cout << "|      menu.                            |" << endl;
    cout << "|                                       |" << endl;
    cout << "| 6. Exit                               |" << endl;
    cout << "|    - Select this option to exit the   |" << endl;
    cout << "|      application.                     |" << endl;
    cout << "-----------------------------------------" << endl;
}
//**********************************************************************


//**********************************************************************


