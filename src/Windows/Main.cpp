
#include <iostream> 
#include <iomanip>

#include "Credential.h"
#include "Prompts.h"
//#include "Manager.h"
#include <sqlite3.h>

using namespace std;

static int callback(void *data, int argc, char** argv, char** azColName){
	int i;
	cerr << static_cast<const char*> (data);
	for(int i = 0; i < argc; i++) {
    std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
  }

	cout << endl;
	return 0;
}


int main(int argc, char const *argv[]) {
	sqlite3* DB;
	
  
	char *errMessage;
	//cyphervault.db
	/* sqlite3_open:
    This routine opens a connection to an SQLite database file 
    and returns a database connection object.
  */
	int returnCode = sqlite3_open("cyphervault.db", &DB);

	// Check if database exist
	// if returnCode == 0, succeeds
	// if the database doesn't exist, it will be created in the same directory
	if(returnCode){
		cerr << "Error opening database: %s\n" << sqlite3_errmsg(DB);
		exit(-1);
	}else{
		cout << "Opened Database Successfully." << endl;
	}

	// Create the table
	string sql = "CREATE TABLE PERSON("
							"SERVICE     TEXT    NOT NULL, "
							"USER        TEXT    NOT NULL, "
							"PASSWORD    TEXT    NOT NULL);";

	int exit = 0; 

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMessage);
	
	if(exit != SQLITE_OK){
		cerr << "Error Create Table" << endl;
		sqlite3_free(errMessage);
	}else{
		cout << endl << endl << "Table created Successfully!" << endl << endl;
	}

	string query = "SELECT * FROM PERSON;";

	cout <<endl << endl << "STATE OF TABLE BEFORE INSERT" << endl << endl;

	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

	sql = ("INSERT INTO PERSON VALUES('Netflix', 'user1', 'password1');"
						 "INSERT INTO PERSON VALUES('Disney+', 'user2', 'temppass');");

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMessage);

	if(exit != 0){
		cerr << "Error Insert" << endl;
		sqlite3_free(errMessage);
	}else{
		cout << "Records created Successfully!" << endl;
	}

	cout << "STATE OF TABLE AFTER INSERT" << endl;

	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);


  Prompts prompt;

  string service, username, password;
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
  
  bool quit = false;
  while(!quit){
    prompt.printMenu();
    int choice = prompt.menu();

    switch(choice){
    case 1:
      prompt.newAccount(service, username, password);
      break;
    case 2:
      prompt.deleteAccount(service);
      break;
    case 3:
      prompt.changeUsername(username);
      break;
    case 4:
      prompt.changePassword(password);
      break;
    case 5: 
      quit = true;
      cout << "\n\n~~~~~Exiting CypherVault~~~~~\n\n" << endl;
      break;
    }
  }
  /* code */
	// Close the connection to the database
	// All prepared statement associated with the 
	// connection should be finalized before closing.
	sqlite3_close(DB);
  return 0;
}
