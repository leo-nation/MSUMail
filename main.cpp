#include <iostream>
#include <fstream>
#include <string>
#include "include/event.cpp"
void ShowHomeScreen();
using namespace std;
void ClearScreen(){cout << string( 100, '\n' );}
bool IsIn(string keyword, string line){return (line.find (keyword) != string::npos);}

void SetupKeywords(string First,string Last){
  string keyword;
  string introMsg = "PLEASE READ: \n vfgesvwebgqtgrsfdvcbgrefsv";
  ofstream o("user_profiles/" + First + "-" + Last + ".txt", ios::app);
  cout << introMsg << endl;
  o << "Keywords:";
  while (keyword != "exit"){
      cin >> keyword;
      o << " " + keyword;
  }
  ClearScreen();
  ShowHomeScreen();
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
  cout << "User Profile Created \n Press Enter to Return to Home";
  o.close();
  cin.ignore();
  ClearScreen();
  SetupKeywords(First, Last);
}

void Login(){
  string First; 
  string Last; 
  cout << "Enter your first name:\n";
  cin >> First;
  cout << "Enter your last name:\n";
  cin >> Last;
  ifstream o("user_profiles/" + First + "-" + Last + ".txt");
  // extract users actual password 
  string password; 
  bool LoggedIn = false;
  while (not LoggedIn){
  cout << "Enter your password\n";
  cin >> password;
  }
  o.close();
  Profile User(First,Last);
}

void ShowHomeScreen(){
    int option;
    cout << "(1) Sign Up\n(2) Login\nSelect a number to continue\n";
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

Event* FindReleventEvents(Profile User){
    Event Events[50];
    int curr_index = 0;
    ifstream o("email_samples/1.txt");
    std::string line;
    while (getline(o, line)){
        Event temp;
        bool relevant = false;
        for (int i = 0; i > (sizeof(User.KeyWords)/sizeof(User.KeyWords[0])); i++){
            if (IsIn(User.KeyWords[0],line)){
                relevant = true;
            } 
        }
        if (relevant){
            Events[curr_index] = temp;
            curr_index += 1;
        }
    }
}

void ShowEventsPage(Profile User){
    Event* EventList = FindReleventEvents(User);

    for(int i = 0;i < (sizeof(EventList)/sizeof(EventList);i++){
        cout << EventList[i].name << endl;
        cout << "Is happening on" << EventList[i].date;
    }
}

int main() { 
    ShowHomeScreen();
    return 0;
}

/*
#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char str[] = "Geeks-for-Geeks"; 
  
    // Returns first token  
    char *token = strtok(str, "-"); 
  
    // Keep printing tokens while one of the 
    // delimiters present in str[]. 
    while (token != NULL) 
    { 
        printf("%s\n", token); 
        token = strtok(NULL, "-"); 
    } 
  
    return 0; 
} 
*/
