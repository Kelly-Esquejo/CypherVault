#ifndef PROMPTS_H
#define PROMPTS_H

#include <iostream>
#include <string>

#include "credential.h"
using namespace std;

class Prompts {
    
    private:
        /* Prompts user */
        
        Credential newcredential;

    public:
    //**********************************************************************
    
        void newAccount (string &, string &, string &);
        void changePassword(string &);
        void changeUsername(string &);
        void deleteAccount(string &);
        int menu();
        void printMenu();
        void printInformation();
        void displayHelp();
        string getPassword();
        bool checkPasswordValidity(string &);
    //**********************************************************************

  
    //**********************************************************************

    

};

#endif