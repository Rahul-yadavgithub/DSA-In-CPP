#include<bits/stdc++.h>
using namespace std;

class Bike{
    public:
    int tyreSize;
    int engineSize;

    Bike(int tyreSize, int engineSize){
        this->tyreSize = tyreSize;
        this->engineSize = engineSize;
    }

    ~Bike(){
        cout<<"Destructor Call Hua"<<endl;
    }
};


int main(){
    Bike tvs(4, 300);  // so in this case as soon as we write this line our constructor called 
    Bike honda(6, 939);
    Bike royalEnfield(2,943);
    bool flag = true;
    if(flag == true){
        Bike Bmw(40, 10000);
        cout<<Bmw.tyreSize<<" "<<Bmw.engineSize<<endl;
    }
    cout<<tvs.tyreSize<<" "<<tvs.engineSize<<endl;
    cout<<honda.tyreSize<<" "<<honda.engineSize<<endl;
    cout<<royalEnfield.tyreSize<<" "<<royalEnfield.engineSize<<endl;

}