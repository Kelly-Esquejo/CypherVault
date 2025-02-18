
#include <iostream> 
#include <iomanip>

#include "databaseManager.h"
#include "prompts.h"

#include <sqlite3.h>

using namespace std;

int main(int argc, char const *argv[]) {
	cout << endl << endl << endl << endl << endl;

	/* Contains Raw String literals to ignore warnings of escape squences such as:
		main.cpp:13:11: warning: unknown escape sequence: '\040'
	13 |   cout << "  ___|                |                \ \     /              |  |  " << endl;
	*/
	cout << R"(  ___|                |                \ \     /              |  |  )" << endl;
	cout << R"( |      |   |  __ \   __ \    _ \   __| \ \   /  _` |  |   |  |  __|)" << endl;
	cout << R"( |      |   |  |   |  | | |   __/  |     \ \ /  (   |  |   |  |  |  )" << endl;
	cout << R"(\____| \__, |  .__/  _| |_| \___| _|      \_/  \__,_| \__,_| _| \__|)" << endl;
	cout << R"(       ____/  _|                                                    )" << endl;
	
	cout << endl << endl << endl;
	cout << "********************************************************************" << endl;
    cout << "|                      Welcome to Cypher Vault                     |" << endl;
	cout << "********************************************************************" << endl;
	cout << "|            Cypher Vault helps you create, store, and             |" << endl;
    cout << "|                 manage your passwords with ease.                 |" << endl;
	cout << "********************************************************************" << endl;
	
	Prompts prompt;
	string service, username, password;

	// Credential database;
	// database.createTable();
	// database.insertCredential("Netflix", "User1", "password1");
	// database.displayDatabase();

	bool quit = false;
	while(!quit){
		prompt.printMenu();
		int choice = prompt.menu();

		switch(choice){
			case 1:
				prompt.newAccount(service, username, password);
				break;
			case 2:
				prompt.deleteAccount();
				break;
			case 3:
				prompt.changeUsername(username);
				break;
			case 4:
				prompt.changePassword(password);
				break;
			case 5:
				prompt.displayHelp();
				break;
			case 6:
				prompt.printInformation();
				break;
			case 7: 
				quit = true;
				cout << "\n\n~~~~~Exiting CypherVault~~~~~\n\n" << endl;
				break;
		}
	}

	return 0;
}
