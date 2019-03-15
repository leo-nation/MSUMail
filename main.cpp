#include <iostream>
#include <fstream>
#include <string>
#include <event>
using namespace std;
void SetupKeywords(string First,string Last){
  string keyword;
  string introMsg = "PLEASE READ: \n vfgesvwebgqtgrsfdvcbgrefsv";
  ifstream o(First + "-" + Last + ".txt");
  cout << introMsg << endl;
  while (keyword != "exit"){

  }
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
  cout << "User Profile Created";
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
}

int main() {
  SignUp();

  return 0;
}