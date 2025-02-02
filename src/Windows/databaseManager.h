#ifndef DATABASEMANAGER_H  
#define DATABASEMANAGER_H

#include <iostream>
#include <string>
#include <sqlite3.h>
#include <vector>

using namespace std;

class DatabaseManager{
    // Cannot be accessed (or viewed) from outsie the class
    private:
        sqlite3* DB;
	    char *errMessage;
        static int callback(void *data, int argc, char** argv, char** azColName);

    public:
        DatabaseManager();
        ~DatabaseManager();

        // Setter functions
        void setUsername(string service, string user, const string&);
        void setPassword(string service, string user, const string&);
        
        void createTable();
        void closeDatabase();

        void insertCredential(string service, string username, string password);
        void deleteCredential(string , string);
        
        void displayDatabase();
    
        bool findCredential(string &, string &);
        void binding(int choice, string, string, const string&);
};


#endif