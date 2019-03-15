#include <iostream>
#include <fstream>
#include <string>
//include <event>
using namespace std;
void ClearScreen(){cout << string( 100, '\n' );}

void SetupKeywords(string First,string Last){
  string keyword;
  string introMsg = "PLEASE READ: \n vfgesvwebgqtgrsfdvcbgrefsv";
  ofstream o("user_profiles/" + First + "-" + Last + ".txt", ios_base::app);
  cout << introMsg << endl;
  o << "Keywords: ";
  while (keyword != "exit"){
      cin >> keyword;
      o << " " + keyword;
  }11
}

void SignUp(){
  string First; 
  string Last; 
  cout << "Enter your first name:\n";
  cin >> First;
  cout << "Enter your last name:\n";
  cin >> Last;
  ofstream o("user_profiles/" + First + "-" + Last + ".txt");
  o << "First Name: " << First << "\n";
  o << "Last Name: " << Last << "\n";

  string password = " "; 
  string temp;
  while (temp!=password){
  cout << "Enter your password\n";
  cin >> password;
  cout << "Confirm your password\n";
  cin >> temp;
  }
  o << "Password: " << password << "\n";
  cout << "User Profile Created \n Press Enter to Continue";
  cin.ignore();
  ClearScreen();
  SetupKeywords(First, Last);
}

bool Login(){
  string First; 
  string Last; 
  cout << "Enter your first name:\n";
  cin >> First;
  cout << "Enter your last name:\n";
  cin >> Last;
  ifstream o("user_profiles/" + First + "-" + Last + ".txt");

  string password = " "; 
  string temp;
  while (temp!=password){
  cout << "Enter your password\n";
  cin >> password;
  cout << "Confirm your password\n";
  cin >> temp;
  }
  return true;
}
void ShowHomeScreen(){
    int option;
    cout << "(1) Sign Up\n(2)Login\nSelect a number to continue\n";
    cin >> option;
    switch (option){
        case 1: ClearScreen(); SignUp(); break;
        case 2: ClearScreen(); Login(); break;
        default:
        cout << "Invalid Entry";
        ShowHomeScreen();
        break;
    }
}
int main() { 
    ShowHomeScreen();
    return 0;
}