#include<iostream>
using namespace std;
class Node{
public:
    Node*Next;
    int val;
    Node*head;
    Node(int val){
        this->val= val;
        this->Next= NULL;
        head= NULL;
    }
};
void display(Node*head){
    Node*temp= head;
    while(temp!= NULL){
        cout<<temp->val<<" ";
        temp= temp->Next;
    }
}
int main(){
    int n;
    cout<<"Enter the length of the linkedlis->";
    cin>>n;
    Node*head= NULL;
    for(int i=1; i<=n; i++){
        int x;
        cout<<"Enter the element of the linkedlist->";
        cin>>x;
        Node*temp= new Node(x);
        temp->Next= head;
        head= temp;
    }
    display(head);
}

