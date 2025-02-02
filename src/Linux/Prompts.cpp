
#include "Prompts.h"
#include <termios.h> // Linux 
#include <unistd.h>

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

  // Hides user input for password
  termios oldt;
  tcgetattr(STDIN_FILENO, &oldt);
  termios newt = oldt;
  newt.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); 

  std::string s;
  cin >> password;

  std::cout << "\rYour password is: " << password << '\n';
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // return to display

  // User can check if the entered password is correct
  cout << "Show password? Type yes or no: ";
  string seePassword;
  bool validInput = true;
  while(validInput){
    cin >> seePassword;
    if(seePassword == "yes"){
      cout << "Password: " << password << endl;
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      validInput = false;
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
  
  termios oldt;
  tcgetattr(STDIN_FILENO, &oldt);
  termios newt = oldt;
  newt.c_lflag &= ~ECHO;
  // hides user input
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

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
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      validInput = false;
    }else if(seePassword == "no"){
      validInput = false;
    }else{
      cout << "Invalid input: Type yes or no" << endl;
    }
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


