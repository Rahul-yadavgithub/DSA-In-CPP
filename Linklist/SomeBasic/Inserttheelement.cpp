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

class Linklist{
    public:
    Node*head;
    Node*tail;
    int size;
    Linklist(){
        head= tail=NULL;
        size=0;
    }
    void insertAtEnd(int val){
        Node*temp= new Node(val);
        if(size==0){
            head= tail= temp;
        }
        else{
            tail->Next = temp;
            tail= temp;
        }
        size++;
    }
    void display(){
        Node*temp= head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->Next;
        
        }
        cout<<endl;
    }
};
int main(){
    Linklist ll;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.display();

}