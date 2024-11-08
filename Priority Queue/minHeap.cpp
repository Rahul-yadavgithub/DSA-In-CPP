#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int> > pq;  // This is for minHeap
    pq.push(20);
    pq.push(30);
    pq.push(9);
    pq.push(10);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
}


// If we want to make float priority_queue for the min heap then change int -> to the float;
