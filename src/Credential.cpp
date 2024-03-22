#include <iostream>
#include <string>

using namespace std;

class Credential{
    private:
    
        string service;
        string username;
        string password;

    public:
        Credential(/* args */);
        ~Credential();

        // Getter functions
        string getService() const {
            return service;
        }

        string getUsername() const {
            return username; 
        }
            
        string getPassword() const {
            return password;
        }

        // Setter functions
        void setService(const string& newService){
           service = newService; 
        }
        void setUsername(const string& newUsername){ 
            username = newUsername; 
        }
        void setPassword(const string& newPassword){ 
            password = newPassword; 
        }

};
