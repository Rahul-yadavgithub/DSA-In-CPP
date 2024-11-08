#include<bits/stdc++.h>
using namespace std;

class Bike{
    public:
    int tyerSize;
    int engineSize;
    Bike(int tS, int eS): tyerSize(tS), engineSize(eS){}  // in this way we can also initaialise our class
};

int main(){
    Bike royalEnfield(4, 20);
    Bike Bajaj(2,10);

    cout<<royalEnfield.tyerSize<<" "<<royalEnfield.engineSize<<endl;
    cout<<Bajaj.tyerSize<<" "<<Bajaj.engineSize<<endl;


}