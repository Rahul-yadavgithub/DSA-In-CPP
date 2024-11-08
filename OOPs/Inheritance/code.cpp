#include<bits/stdc++.h>
using namespace std;

class Vehicle{// it is parent Class
    public:
    int tyerSize;
    int engineSize;
    int lights;
    string campanyName;

    void showCampanyName(){
        cout<<"this is Campany Name";
    }
    Vehicle(){
        cout<<"Vehical constructor called !!\n";
    }

};


class Bike : public Vehicle{ // it means car inherits Vehicle
    public:
    int handleSize;
};

class Car : public Vehicle{
    public:
    int steeringSize;
   // Now we check that car class constructor called or not
   Car(){
    cout<<"Car constructor called !!\n";
   }  
};

class A{
    private:
    int a_ka_private;
    
    protected:
    int a_ka_protected;

    public: 
    int a_ka_public;
};

class B: public A{
    public:
    int b_ka_public;

};
int main(){
    B b;
    b.b_ka_public = 10;

}