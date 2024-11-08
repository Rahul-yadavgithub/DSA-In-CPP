#include<iostream>
using namespace std;
class Node{
    public:
    int val;
   Node*Next;
    Node(int val){
        this->val= val;
        this->Next=NULL;
    }
};
   class Linkedlist{
    public:
    Node* head;
    Node* tail;
    int size;
    Linkedlist(){
        head = tail= NULL;
        size=0;
    }
    void insertAtHead(int val){
        Node*temp= new Node(val);
        if(size==0){
            head= tail= temp;
        }
        else{
        temp->Next = head;
        head=temp;
        }
        size++;
    }
    void display(){
        Node*temp= head;
        while(temp!= NULL){
            cout<<temp->val<<" ";
            temp= temp->Next;

        }
        cout<<endl;
    }
   };
    int main(){
        Linkedlist ll;
        ll.insertAtHead(20);
        ll.display();
        ll.insertAtHead(30);
        ll.display();    
        }