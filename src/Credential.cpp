#include "Credential.h"
using namespace std;

// Constructor definition
Credential::Credential(){
    service = "";
    username = "";
    password = "";
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

void Credential::setUsername(const string& newUsername) {
    username = newUsername;
}

void Credential::setPassword(const string& newPassword) {
    password = newPassword;
}