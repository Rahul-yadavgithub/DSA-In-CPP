#include<bits/stdc++.h>
using namespace std;

class Bike{
    public:
    static int noOfBikes;
    int tyerSize;
    int engineSize;
    Bike(int tyerSize, int engineSize){
        this->tyerSize = tyerSize;
        this->engineSize = engineSize;
    }

    static void increaseNoOfBikes(){
        noOfBikes++;
    }
};
int Bike:: noOfBikes = 10;
int main(){
    Bike royalEnfield(4, 20);
    Bike Bajaj(2,10);

    cout<<royalEnfield.noOfBikes<<endl;
    
    royalEnfield.increaseNoOfBikes();
    cout<<royalEnfield.noOfBikes<<endl;
    
    Bajaj.increaseNoOfBikes();
    cout<<Bajaj.noOfBikes<<endl;

}