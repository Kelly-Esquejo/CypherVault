
#include "prompts.h"
#include <unistd.h>
#include <conio.h> 

using namespace std;
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
	cout << "Enter password for " << username << " for " << service << ": ";

	password = getPassword();

	// Checks validity of password
	bool isValid = true;
	while(!checkPasswordValidity(password)){
		cout << "Invalid password. Please try again.\n";
		cout << "Enter password for " << username << " for " << service << ": ";
		cout << "or 'exit' to quit: " ;
		password = getPassword();
		if(password == "exit"){
			return;
		}
	}
	showPassword(password);
	newCredential.insertCredential(service, username, password);
}

void Prompts::showPassword(string &password){
	bool validInput = true;
	cout << "Show password? Type 'yes' or 'no': ";
	string seePassword;

	while(validInput){
		cin >> seePassword;

		if(seePassword == "yes"){
			cout << "Password: " << password << endl;
			validInput = false;
		}else if(seePassword == "no"){
			validInput = false;
		}else{
			cout << "Invalid input: Type 'yes' or 'no': " << endl;
		}
	}
}

// Checks the validity of a password
bool Prompts::checkPasswordValidity(string &password){
	if(password.length() < 12){
		cout << "Password length needs to be at least 12 characters.\n\n" ;

		return false;
	}

	bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

	// check complexity
	// Does it include at least one special character, uppercase, lowercase, and number
	for (char ch : password){
		if (isupper(ch)) hasUpper = true;
		else if (islower(ch)) hasLower = true;
		else if (isdigit(ch)) hasDigit = true;
		else if (ispunct(ch)) hasSpecial = true;
	}

	if(!hasUpper){
		cout << "Password is missing an uppercase letter. \n\n";
	}
	if(!hasLower){
		cout << "Password is missing a lowercase letter. \n\n";
	}
	if(!hasDigit){
		cout << "Password is missing a number. \n\n";
	}
	if(!hasSpecial){
		cout << "Password is missing a special character. \n\n";
	}

	// check if common password

	// check history
	return hasUpper && hasLower && hasDigit && hasSpecial;
	
}
/*
	Changes password while hiding user input as user types

*/
void Prompts::changePassword(string &password){
	cout << endl << endl << "-----------------------------------------" << endl;
	cout << "|          Changing Password            |" << endl;
	cout << "-----------------------------------------" << endl;
	
	string service;

	// Search for the service in the database
	// Prompt user for a valid service, with an option to exit
    while (true) {
        cout << "Enter service to change password for (or 'exit' to cancel): ";
        cin >> service;

        if (service == "exit") {
            cout << "Changing password canceled.\n";
            return;
        }

        // Check if the service exists
        if (newCredential.findCredential(service)) {
            break;  // Exit loop if service is found
        } else {
            cout << "Service not found. Please try again.\n";
        }
    }

	// newCredential.setPassword(password);
	// get user input for password
	cout << "New password: ";
	cin >> password;
	// Checks validity of password
	// Checks validity of password
	bool isValid = true;
	while(!checkPasswordValidity(password)){
		cout << "Invalid password. Please try again.\n";
		cout << "Enter password for " << service << ": ";
		cout << "or 'exit' to quit: " ;
		password = getPassword();
		if(password == "exit"){
			return;
		}
	}
	showPassword(password);

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
	cout << "-----------------------------------------" << endl << endl;

	// TODO: get service 
	string service;
	cout << "Changing username for: " << endl;
	cin >> service;

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
	cout << "| 6. Display credentials                |" << endl;
	cout << "| 7. Exit                               |" << endl;
	cout << "-----------------------------------------" << endl;
}

/*
	Calls ___

*/
void Prompts::printInformation(){
	newCredential.displayDatabase();
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
    cout << "| 6. Display Credentials                |" << endl;
    cout << "| 7. Exit                               |" << endl;
    cout << "|    - Select this option to exit the   |" << endl;
    cout << "|      application.                     |" << endl;
    cout << "-----------------------------------------" << endl;
}
//**********************************************************************


//**********************************************************************


