#include<iostream>
#include<vector>
using namespace std;

// OCP - Add new functionality without modifying existing code
//Base Shape Class
class Shape{
    public:
    virtual double area() = 0;
};

class Circle : public Shape{
    public:
    Circle(double r) : radius(r){}
    double area() override{
        return 3.14 * radius * radius;
    }
    private:
    double radius;
};

class Square : public Shape{
    public:
    Square(double s) : side(s){}
    double area() override{
        return side * side;
    }
    private:
    double side;
};

// Calculate total area of all shapes without modifying the existing code

double calculateTotalArea(vector<Shape*> shapes ){
    double totalArea = 0;
    for(auto& shape : shapes){
        totalArea += shape->area();
    }
    return totalArea;
}

// In this code we can add more shapes without altering the existiing Shape , Circle , Square 
// or Calculate Total Area code. This is an example of Open Closed Principle.