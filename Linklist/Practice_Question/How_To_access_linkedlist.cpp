#include<iostream>
using namespace std;
class Node{
public:
    Node*Next;
    int val;
};
int main(){
    Node a;
    a.val=10;
    Node b;
    b.val= 20;
    Node c;
    c.val=30;
    a.Next= &b;
    b.Next=&c;
    c.Next= NULL;

    cout<<a.val<<" ";
}




