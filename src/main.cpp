#include <iomanip>
#include "Credential.h"
#include "Prompts.h"

int main(int argc, char const *argv[]) {
  Prompts prompt;

  string service, username, password;


  bool exit = false;

  while(!exit){
    prompt.printMenu();
    int choice = prompt.menu();

    switch(choice){
    case 1:
      prompt.newAccount(service, username, password);
      break;
    case 2:
      prompt.deleteAccount(service);
      break;
    case 3:
      prompt.changeUsername(username);
      break;
    case 4:
      prompt.changePassword(password);
      break;
    case 5: 
      exit = true;
      cout << "\n\n~~~~~Exiting CypherVault~~~~~\n\n" << endl;
      break;
    }
  }
  /* code */
  return 0;
}
