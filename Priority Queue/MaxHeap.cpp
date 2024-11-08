#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(12);
    pq.push(9);
    
    // If we want to print something then 
    cout<<pq.top()<<endl;  // Greatest number print from all the numbers
    pq.pop(); // Greatest Number will removed from the top
    cout<<pq.top()<<endl;
}