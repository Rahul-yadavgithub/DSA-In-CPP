#include<bits/stdc++.h>
using namespace std;

class Vehicle{// it is parent Class
    public:
    int tyerSize;
    int engineSize;
    virtual void show(){
        cout<<"This is vehicle show function\n";
     }

};
class Bike : public Vehicle{ // it means car inherits Vehicle
    public:
    int handleSize;

     void show(){
        cout<<"This is the Bike show function\n";
    }
};

class C : public Bike{
    public:
    void show(){
        cout<<"This is C Function Show\n";
    }
};
int main(){
    Vehicle a;
    Bike b;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(b)<<endl;
}