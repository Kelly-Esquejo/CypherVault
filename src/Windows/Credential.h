#ifndef CREDENTIAL_H  
#define CREDENTIAL_H

#include <iostream>
#include <string>
#include <sqlite3.h>
#include <vector>

using namespace std;

class Credential{
    private:
        
        string service;
        string username;
        string password;

        sqlite3* DB;
	
	    char *errMessage;

        static int callback(void *data, int argc, char** argv, char** azColName);
    public:
        Credential();
        Credential(string, string, string);
        ~Credential();

         // Getter functions
        string getService() const;
        string getUsername() const;
        string getPassword() const;

        // Setter functions
        void setCredential(string, string, string);
        void setService(const string& newService);
        void setUsername(int id, const string& newUsername);
        void setPassword(int id, const string& newPassword);
        
        void createTable();
        void insertCredential(string service, string username, string password);
        void deleteCredential();
        void closeDatabase();

        void displayDatabase();
        void displayRecord();
        bool findCredential(const string &, int &id);
        void binding(int choice, int id, const string&);
};


#endif