#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* Next;
    Node(int val){
        this->val= val;
        this->Next= NULL;
  }
};
  void display(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp= temp->Next;
    }
     cout<<endl;

  }
  void insertAtEnd(Node*head ,int val){
    Node*c= new Node(val);
    Node*temp= head;
    while(temp->Next!=NULL){
        temp=temp->Next;
    }
    temp->Next=c;
  }
  int main(){
 Node* a= new Node(10);
 Node* b= new Node(20);
 Node*c= new Node(20);
 a->Next= b;
 display(a);
 insertAtEnd(a ,80);
 display(a);




  }
