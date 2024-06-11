
#include "Prompts.h"
#include <unistd.h>
#include <conio.h> 

//**********************************************************************
// Enumerator 
enum IN { 
    // 13 is ASCII for carriage 
    // return 
    IN_BACK = 8, 
    IN_RET = 13 
  
}; 

void Prompts::newAccount (string &service, string &username, string &password){
  cout  << endl << endl << "----------------------------------------" << endl;
  cout << "|            Account Setup             |" << endl;
  cout << "----------------------------------------" << endl;
  cout << "Enter service: ";
  cin >> service;
  cout << "Enter email or username for " << service << ": ";
  cin >> username;
  cout << "Enter password for " << username << " on " << service << ": ";

  password = getPassword();


  cout << "\rYour password is: " << password << '\n';

  cout << "Show password? Type yes or no: ";
  string seePassword;
  bool validInput = true;
  while(validInput){
    cin >> seePassword;
    if(seePassword == "yes"){
      cout << "Password: " << password << endl;
      
   
    }else if(seePassword == "no"){
      validInput = false;
    }else{
      cout << "Invalid input: Type yes or no" << endl;
    }
  }

  newcredential.setCredential(service, username, password);
}
/*

*/
void Prompts::changePassword(string &password){
  cout << endl << endl << "-----------------------------------------" << endl;
  cout << "|          Changing Password            |" << endl;
  cout << "-----------------------------------------" << endl;


  cout << "Changing password for " << endl;
  // TODO: get service 
  
 
  // get user input for password
  cin >> password;

  // see if user wants to see password
  string seePassword;
  cout << "Show password? Type yes or no: ";
  bool validInput = true;
  while(validInput){
    cin >> seePassword;
    if(seePassword == "yes"){
      cout << "Password: " << password << endl;
      validInput = false;
    }else if(seePassword == "no"){
      validInput = false;
    }else{
      cout << "Invalid input: Type yes or no" << endl;
    }
  }
}

// Function that accepts and hides the password with '*' as user types.
string Prompts::getPassword(){ 
  // Stores the password 
  char sp = '*';
  string passwd = ""; 
  char input; 

  // Until condition is true 
  while (true) { 
    // Retrieves characters from the keyboard like cin
    input = getch(); 

    // if input is ENTER, return 
    if (input == '\r') { 
      cout << endl; 
      return passwd; 
    } else if (input == IN::IN_BACK && passwd.length() != 0) { 
      passwd.pop_back(); 

      // Cout statement is very 
      // important as it will erase 
      // previously printed character 
      cout << "\b \b"; 
      continue; 
    } 

    // Without using this, program 
    // will crash as \b can't be 
    // print in beginning of line 
    else if (input == IN::IN_BACK && passwd.length() == 0) { 
      continue; 
    } 

    passwd.push_back(input); 
    cout << sp; 
  } 
} 

void Prompts::changeUsername(string &username){
  cout << endl << endl << "-----------------------------------------" << endl;
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
  cout << "| 3. Change Account                     |" << endl;
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


