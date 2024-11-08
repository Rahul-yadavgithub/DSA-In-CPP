#include<bits/stdc++.h>
using namespace std;

class Vehicle{// it is parent Class
    public:
    int tyerSize;
    int engineSize;
    virtual void calculateMileage() = 0;
    virtual void refuel() = 0;

};
class Bike : public Vehicle{ // it means car inherits Vehicle
    public:
    int handleSize;

     void calculateMileage(){
        cout<<"This is the Bike show function\n";
    }
    
    void refuel(){
        cout<<"This is Refuel function !!\n";
    }
};

int main(){

    Bike b;
    b.calculateMileage();
    b.refuel();
}