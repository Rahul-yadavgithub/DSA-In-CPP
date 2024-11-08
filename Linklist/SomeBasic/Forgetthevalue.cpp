#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* Next;
    Node(int val){
        this->val=val;
        this->Next=NULL;
    }
};
class Linkedlist{
    public:
    Node*head;
    Node*tail;
     int size;
    Linkedlist(){
        head= tail= NULL;
        size=0;
    }
    void insertAtHead(int val){
        Node*temp= new Node(val);
        if(size==0){
            tail= head= temp;
        }
        else{
            temp->Next = head;
            head= temp;
        }
        size++;
    }
    void insertAtTail(int val){
        Node*temp= new Node(val);
        if(size==0){
            tail= head= NULL;
        }
        else{
            tail->Next= temp;
            tail= temp;
        }
        size++;
    
    }
    void insertAtIndex( int idx ,int val){
        Node*temp= new Node(val);
        if(idx<0 || idx>size){
            cout<<"Invalid Index" <<endl;
        }
        else if(idx==0){
            insertAtHead(val);
        }
        else if(idx==size){
            insertAtTail(val);
        }
        else{
            Node*t= new Node(val);
            Node*temp= head;
            for(int i=0; i<idx-1 ; i++){
                temp= temp->Next;
            }
            t->Next= temp->Next;
            temp->Next= t;
            size++;
        }
    }
    int getAtIndex(int idx){
        if(idx<0 || idx>size){
            cout<<"Invalid Index";
            return -1;
        }
        else if(idx==0){
            return head->val;
        }
        else if(idx==size-1){
            return tail->val;
        }
        else{
            Node*temp= head;
            for(int i=0; i<idx; i++){
                temp= temp->Next;
            }
            return temp->val;
        }
        
    }
    void display(){
        Node*temp= head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp= temp->Next;
        }
        cout<<endl;
    }
};

int main(){
    Linkedlist ll;
    ll.insertAtHead(10);
    ll.insertAtHead(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);
    ll.display();
    cout<<ll.getAtIndex(3)<<endl;

}
