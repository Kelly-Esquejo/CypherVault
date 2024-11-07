#ifndef CREDENTIAL_H  
#define CREDENTIAL_H

#include <iostream>
#include <string>
#include <sqlite3.h>
#include <vector>

using namespace std;

class Credential{
    private:
    
        sqlite3* DB;
	
	    char *errMessage;

        static int callback(void *data, int argc, char** argv, char** azColName);
    public:
        Credential();
        ~Credential();

        // Setter functions
        void setUsername(string service, string user, const string& newUsername);
        void setPassword(string service, string user, const string& newPassword);
        
        void createTable();
        void closeDatabase();

        void insertCredential(string service, string username, string password);
        void deleteCredential(string , string);
        
        void displayDatabase();
    
        bool findCredential(const string &, string &);
        void binding(int choice, string service, const string&);
};


#endif