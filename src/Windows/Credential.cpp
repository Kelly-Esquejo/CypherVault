#include "credential.h"
using namespace std;

int Credential::callback(void *data, int argc, char** argv, char** azColName){
	int i;
	cerr << static_cast<const char*> (data);
	for(int i = 0; i < argc; i++) {
    	std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
  	}

	cout << endl;
	return 0;
}


void Credential::createTable(){
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
    string query = "CREATE TABLE CREDENTIALS("
                    "ID         INTEGER  PRIMARY KEY, "
                    "SERVICE     TEXT    NOT NULL, "
                    "USER        TEXT    NOT NULL, "
                    "PASSWORD    TEXT    NOT NULL);";
                    
    int exit = 0; 

    exit = sqlite3_exec(DB, query.c_str(), NULL, 0, &errMessage);
    
    if(exit != SQLITE_OK){
        cerr << "Error Create Table" << endl;
        sqlite3_free(errMessage);
    }else{
        cout << endl << endl << "Table created Successfully!" << endl << endl;
    }
}

// Close the connection to the database
// All prepared statement associated with the 
// connection should be finalized before closing.
void Credential::closeDatabase(){
    sqlite3_close(DB);
}

/*
The life-cycle of a prepared statement object usually goes like this:

Create the prepared statement object using sqlite3_prepare_v2().
Bind values to parameters using the sqlite3_bind_*() interfaces.
Run the SQL by calling sqlite3_step() one or more times.
Reset the prepared statement using sqlite3_reset() then go back to step 2. Do this zero or more times.
Destroy the object using sqlite3_finalize().
*/
void Credential::insertCredential(string service, string username, string password){
    sqlite3_stmt* stmt;
    // TESTING
    cout << "Inserting credentials: " << service << " " << username << " " << password << endl;
    string query = "INSERT INTO CREDENTIALS (SERVICE, USER, PASSWORD) VALUES (?, ?, ?);";
    // Prepare the statement
    int exit = sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, 0);
    if (exit != SQLITE_OK) {
        std::cerr << "Error preparing statement for INSERT: " << sqlite3_errmsg(DB) << std::endl;
        return;
    }

    // Bind the parameters to the SQL statement
    sqlite3_bind_text(stmt, 1, service.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, username.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, password.c_str(), -1, SQLITE_TRANSIENT);

    // Execute the statement
    exit = sqlite3_step(stmt);
    if (exit != SQLITE_DONE) {
        std::cerr << "Error executing statement: " << sqlite3_errmsg(DB) << std::endl;
    } else {
        std::cout << "Record created successfully!" << std::endl;
    }

    // Destruct - Finalize the statement to release resources
    sqlite3_finalize(stmt);
  
	// int exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMessage);
    
    // if(exit != 0){
	// 	cerr << "Error Insert" << endl;
	// 	sqlite3_free(errMessage);
	// }else{
	// 	cout << "Records created Successfully!" << endl;
	// }
}

void Credential::deleteCredential(){
    string query = "DELETE FROM CREDENTIALS WHERE ID = 2;" ;
	int exit = sqlite3_exec(DB, query.c_str(), NULL, 0, &errMessage);

	if(exit != SQLITE_OK){
		cerr << "Error DELETE" << endl;
		sqlite3_free(errMessage);
	}else{
		cout << "\n Record deleted Successfully!" << endl;
	}
}

/*
    Displays all credentials to the console
*/
void Credential::displayDatabase(){
    string query = "SELECT * FROM CREDENTIALS;";
    cout << "-----------------------------------------" << endl;
    cout << "|            STATE OF TABLE             |" << endl;
	cout << "-----------------------------------------" << endl;

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
}

void Credential::displayRecord(){

}


Credential::Credential(){
   createTable();
}

Credential::Credential(string x, string y, string z) {
    
    service = x;
    username = y;
    password = z;
}

// Destructor definition
Credential::~Credential() {}

// Getter function definitions
string Credential::getService() const {
    return service;
}

string Credential::getUsername() const {
    return username;
}

string Credential::getPassword() const {
    return password;
}

// Setter function definitions

void Credential::setCredential(string x, string y, string z){
    service = x;
    username = y;
    password = z;
}

void Credential::setService(const string& newService) {
    service = newService;
}

void Credential::binding(int choice, int id, const string& updateCell){
    sqlite3_stmt* stmt;
    string query;
    if(choice == 1){
        query = "UPDATE CREDENTIALS SET USER = ? WHERE ID = ?";
    }else{
        query = "UPDATE CREDENTIALS SET PASSWORD = ? WHERE ID = ?";
    }

    // Prepare statement
    if(sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK){
        std::cerr << "\nError preparing statement: " << sqlite3_errmsg(DB) << std::endl;
        return;
    }

    // Bind the new user/password to the first placeholder
    if(sqlite3_bind_text(stmt, 1, updateCell.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK){
        cerr << "Error binding: " << sqlite3_errmsg(DB) << endl;
        sqlite3_finalize(stmt);
        return;
    }

     // Bind the ID to the second placeholder
    if(sqlite3_bind_int(stmt, 2, id) != SQLITE_OK){
        cerr << "Error binding ID: " << sqlite3_errmsg(DB) << endl;
        sqlite3_finalize(stmt);
        return;
    }

    // Execute the statement
    int exit = sqlite3_step(stmt);
    if(exit != SQLITE_DONE){
        std::cerr << "Error executing statement: " << sqlite3_errmsg(DB) << std::endl;
    }else {
        std::cout << "Record updated successfully!" << std::endl;
    }
   
    // Finalize the statement
    sqlite3_finalize(stmt);
}
void Credential::setUsername(int id, const string& newUsername) {
    binding(1, id, newUsername);
}

void Credential::setPassword(int id, const string& newPassword) {
    binding(2, id, newPassword);
}

bool Credential::findCredential(const string& str, int &id) {
    sqlite3_stmt* stmt;
    string query = "SELECT * FROM CREDENTIALS WHERE SERVICE LIKE ?";  // Use a placeholder
    // // Choice '1' or '2' for changing query 
    // if(choice == 1){
    //     // change username
    //     string query = "SELECT * FROM CREDENTIALS WHERE SERVICE LIKE ?";  // Use a placeholder
    // }else{
    //     // change password
    // }
    
    // Prepare the SQL statement
    int exit = sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, 0);
    if (exit != SQLITE_OK) {
        return false;  // Return false on error
    }

    // To avoid SQL injections
    // Bind the `str` parameter to the placeholder with wildcards for partial matching
    string param = "%" + str + "%";  // Add the wildcards to `str` for partial matching

    exit = sqlite3_bind_text(stmt, 1, param.c_str(), -1, SQLITE_TRANSIENT);  // Bind to the first placeholder
    if (exit != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return false;  // Return false on error
    }

    // Execute the statement and check for results
    vector<int> ids;
    bool found = false;
    int count = 0;
    while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
        found = true;  // At least one record was found

        // Print record 
        // NOTE: sqlite3_column_text is declared as const unsigned char*
        id = sqlite3_column_int(stmt, 0); 
        const unsigned char* service = sqlite3_column_text(stmt, 1);
        const unsigned char* user = sqlite3_column_text(stmt, 2);
        const unsigned char* password = sqlite3_column_text(stmt, 3);

        // Store id to the vector and increment count
        ids.push_back(id);
        count++;

        // Process or print the found record as needed
        std::cout << "ID: " << id 
                  << ", Service: " << service 
                  << ", User: " << user 
                  << ", Password: " << password 
                  << std::endl;
    }

    // If multiple records are found, user will be prompted to enter a valid ID
    if(count > 1){
        cout << "Multiple credentials found under '" << str << "'\n";
        int selectedID;
        bool valid = false;
        while(!valid){
            cout << "\nChoose an ID: ";
            
            cin >> selectedID;

            // Check if selected ID is valid
            for(int id : ids){
                if(id == selectedID){
                    valid = true;
                    break;
                }
            }

            if(!valid){
                cout << "Invalid ID. Choose a valid ID from the list: \n";
                for(int id : ids) {
                    cout << id << "  ";
                } 
            }

        }
        id = selectedID;
    }
    // Finalize the statement
    sqlite3_finalize(stmt);
    
    return found;  // Return true if found, otherwise false
}