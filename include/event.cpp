#include<string>
using namespace std;
class Event 
{ 
    public: 
    string name; 
    string date;
    string content;
}; 
class Profile { 
    public: 
    string FirstName; 
    string LastName;
    string FullName;
    string KeyWords[25];

    Profile(string First,string Last){
        FirstName = First;
        LastName = Last;
        FullName = First + " " + Last;
        ifstream o("user_profiles/" + First + "-" + Last + ".txt");
        
        // Split function
        o.close();
    }
}; 