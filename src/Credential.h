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
        ~Credential();

         // Getter functions
        string getService() const;
        string getUsername() const;
        string getPassword() const;

        // Setter functions
        void setService(const string& newService) { service = newService; }
        void setUsername(const string& newUsername) { username = newUsername; }
        void setPassword(const string& newPassword) { password = newPassword; }

};


#endif