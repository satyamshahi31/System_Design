#include<iostream>
#include<string>
using namespace std;

// SRP - A class should have only one reason to change
// Before applying SRP (Single Responsibility Principle)
class User{
    public:
    string getName(){
        return name;
    }
    void setName(const string& n){
        name = n;
    }
    //other properties and methods related to user ...

    //save user to database
    void saveToDatabase(){
        // database saving logic 
    }
    private :
    string name;
};

// After applying SRP
class User{
    public:
    string getName(){
        return name;
    }
    void setName(const string& n){
        name = n;
    }
    //other properties and methods related to user ...
    private :
    string name;
};

class UserDatabase{
    public:
    //save user to database
    void saveToDatabase(User user){
        // database saving logic 
    }
};

// by splitting the database logic from User class, each class adheres to SRP