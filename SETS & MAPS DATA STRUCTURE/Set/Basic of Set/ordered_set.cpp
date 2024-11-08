#include<iostream>
#include<set>
using namespace std;
int main(){
set<int> s;
s.insert(3);
s.insert(5);

for(int ele : s){
    cout<< ele<< " ";   // So hear the set are print in the sorted order
  }
}