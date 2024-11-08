#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* Next;
    Node(int val){
        this->val =val;
        this->Next=Next;
    }
    
};

int main(){
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    a.Next =&b;
    b.Next =&c;
    c.Next =&d;
    d.Next =NULL;

    


}