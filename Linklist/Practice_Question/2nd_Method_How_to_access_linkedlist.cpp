#include<iostream>
using namespace std;
class Node{
public:
    Node*Next;
    int val;
    Node(int val){
        this->Next= NULL;
        this->val= val;
    }
};
int main(){
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(50);
    Node e(60);
    a.Next= &b;
    b.Next=&c;
    c.Next=&d;
    d.Next=&e;
   cout<<b.val<<" ";
}