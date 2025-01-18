#include<iostream>
using namespace std;

// DIP - High level modules should not depend on low level modules .
// Both should depend on abstractions. (Dependency Inversion Principle)

// Abstractions should not depend on details. Details should depend on abstractions.

// Before DIP

class LightBulb{
    public:
    void turnOn(){
        cout << "LightBulb: Bulb turned on" << endl;
    }
    void turnOff(){
        cout << "LightBulb: Bulb turned off" << endl;
    }
};

class Switch{
    LightBulb bulb;

    public:
    void operate(){
        if(isOn){
            bulb.turnOff();
            isOn = false;
        }else{
            bulb.turnOn();
            isOn = true;
        }
    }
    private:
    bool isOn;
};

// In this code the Switch class is dependent on the LightBulb class. 

// After DIP

class SwitchableDevice{
    public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};
class LightBulb : public SwitchableDevice{
    public:
    void turnOn() override{
        cout << "LightBulb: Bulb turned on" << endl;
    }
    void turnOff() override{
        cout << "LightBulb: Bulb turned off" << endl;
    }
};

class Switch{
    SwitchableDevice& device;

    public:
    Switch(SwitchableDevice& s) : device(s){}
    void operate(){
        if(isOn){
            device.turnOff();
            isOn = false;
        }else{
            device.turnOn();
            isOn = true;
        }
    }
    private:
    bool isOn;
};

// In this code the Switch class is dependent on the abstraction 
// (SwitchableDevice interface) and not on the LightBulb class.

