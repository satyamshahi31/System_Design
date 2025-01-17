#include<iostream>
using namespace std;

// LSP - Superclass obj can be replaced by subclass obj 
class Bird{
    public:
    virtual void fly() = 0;
};

class Ostrich : public Bird{
    //Overriding the fly method to show that Ostrich can't fly
    void fly() override{
        throw std::runtime_error("Ostrich can't fly");
    }
};

// This design voilates the LSP since substituting a Ostrich for a Bird can lead to unwxpected

// behavior. The Ostrich class should not inherit from Bird class since it can't fly.

// To fix this we can create a separate class/interface for Ostrich and Bird and make them independent.

// or better we can have separate interfaces for flying and non-flying birds.