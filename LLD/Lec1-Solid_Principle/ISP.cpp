#include<iostream>
using namespace std;

// Before ISP - don't forcve to implement methods not needed by the class

class Worker{
    public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

// After ISP - separate interfaces for different types of workers

class Workable{
    public:
    virtual void work() = 0;
};

class Eatable{
    public:
    virtual void eat() = 0;
};

class Worker : public Workable, public Eatable{
    public:
    void work() override{
        cout << "Worker is working" << endl;
    }
    void eat() override{
        cout << "Worker is eating" << endl;
    }
};

// Workable and Eatable interfaces are now independent and can be implemented by different classes

// A class can implement only the methods it needs.
