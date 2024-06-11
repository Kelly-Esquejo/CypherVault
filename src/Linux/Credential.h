#ifndef CREDENTIAL_H  
#define CREDENTIAL_H

#include <iostream>
#include <string>

using namespace std;

class Credential{
    private:
    
        string service;
        string username;
        string password;

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
        void setUsername(const string& newUsername);
        void setPassword(const string& newPassword);

};


#endif