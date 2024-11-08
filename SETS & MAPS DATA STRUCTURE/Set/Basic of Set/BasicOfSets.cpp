#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(9);
    s.insert(1);  // Set always store unique value 


    // if we want to errse any particular element form our set then 
    s.erase(4); // we need to enter that value inside the s.erase()function that can errase the data

    // if we want to find elemet and want to print for that 

    int target = 3;
    if(s.find(target)!= s.end()){ // this means our target exist
    cout<<"Exists"<<endl;
    }
    else{
        cout<< "does Not exits"<<endl;
    }
    cout<<s.size()<<endl;

    for(int ele : s){
        cout<< ele<<" ";
    }

}
