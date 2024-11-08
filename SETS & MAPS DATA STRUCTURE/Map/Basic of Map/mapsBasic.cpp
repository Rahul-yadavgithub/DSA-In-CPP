#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> m;
    pair<string, int> p1;
    p1.first = "Rahul";
    p1.second = 21;
    pair<string, int> p2;
    p2.first = "Rohit";
    p2.second = 42;
    pair<string, int> p3;
    p3.first = "Suraj";
    p3.second = 54;

    m.insert(p1);
    m.insert(p2);
    m.insert(p3);


    // This is one way to insert new element  we can insert this by another way also

    m["Raman"] = 15;   // And this line automatically inseted the value

    // For deletion 

    m.erase("Raman");

  // If we want to print this value and pair for that we need this loop

  for(pair<string, int> p : m){
    cout<<p.first<<" "<< p.second<< endl;   // we can replace pair<string,int> p with new word auto which work similar as this

  }  

}