#ifndef PROMPTS_H
#define PROMPTS_H

#include <iostream>
#include <string>

#include "Credential.h"
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
    //**********************************************************************

  
    //**********************************************************************

    

};

#endif