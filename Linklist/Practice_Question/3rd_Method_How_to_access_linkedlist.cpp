#include<iostream>
using namespace std;
class Node{
public:
    Node*Next;
    int val;
    Node*head;
    Node*tail;
    Node(int val){
        this->val= val;
        this->Next= NULL;
        head= tail= NULL;
    }
};
int main(){
    int n;
    cout<<"Enter the length of the linkedlist->";
    cin>>n;
    Node*head= NULL;
    for(int i=1; i<=n; i++){
        int x;
        cout<<"Enter the value of x->";
        cin>>x;
        Node*temp= new Node(x);
        temp->Next= head;
        head= temp;
    }
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->Next;

    }
    
}