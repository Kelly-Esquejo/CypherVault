
#include "Prompts.h"


    //**********************************************************************
   

    void Prompts::newAccount (string &service, string &username, string &password){
      cout  << endl << endl << "----------------------------------------" << endl;
      cout << "|            Account Setup             |" << endl;
      cout << "----------------------------------------" << endl;
      cout << "Enter service: ";
      cin >> service;
      cout << "Enter email or username for " << service << ": ";
      cin >> username;
      cout << "Enter password for " << username << " on " << service << ": ";
      cin >> password;
     // newcredential.setCredential(service, username, password);
    }
    /*
    
    */
    void Prompts::changePassword(string &password){
      cout << endl << endl << "-----------------------------------------" << endl;
      cout << "|          Changing Password            |" << endl;
      cout << "-----------------------------------------" << endl;
      cin >> password;
    }

    void Prompts::changeUsername(string &username){
      cout  << endl << endl << "-----------------------------------------" << endl;
      cout << "|          Changing Username             |" << endl;
      cout << "-----------------------------------------" << endl;
      
      cin >> username;
    }

    void Prompts::deleteAccount(string &){
      cout << endl << endl << "-----------------------------------------" << endl;
      cout << "|          Deleting Account              |" << endl;
      cout << "-----------------------------------------" << endl;
      
    }

    int Prompts::menu(){
      cout << "Enter: ";
      int choice;
      cin >> choice;
      if(choice < 0 || choice > 5){
        cout << "Invalid choice. 1-5 only.";
      }
      return choice;
    }

  
    void Prompts::printMenu(){
      cout << endl << endl << "-----------------------------------------" << endl;
      cout << "|                Menu                   |" << endl;
      cout << "-----------------------------------------" << endl;
      cout << "| 1. New Accounts                       |" << endl;
      cout << "| 4. Delete Account                     |" << endl;
      cout << "| 3. Change Password                    |" << endl;
      cout << "| 4. Change Password                    |" << endl;
      cout << "| 5. Exit                               |" << endl;
      cout << "|                                       |" << endl;
      cout << "-----------------------------------------" << endl;
    }


    void Prompts::printInformation(){
      cout << endl << endl << "-----------------------------------------" << endl;
      cout << "|          Account Information          |" << endl;
      cout << "-----------------------------------------" << endl;
    //  cout << "Service: " << service << endl;
     // cout << "Email: " << username << endl;
      cout << "Password: ********" << endl;
      cout << "---------------------------" << endl;
    }


    //**********************************************************************

  
    //**********************************************************************

    
