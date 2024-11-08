#include<iostream>
#include<set>
#include<map>
using namespace std;

int main() {
    map<int, int> m;

    m[2] = 30;
    m[3] = 20;
    m[1] = 10;

    for (auto x : m) {
        cout << x.first << " "; // hear the order is in the increasing order
    }
    cout<<endl;

    // Now if we want to print the x.second what is order going to   

    for(auto x : m){
        cout<< x.second<< " ";
    }
}
 