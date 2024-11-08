#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*Next;
    Node(int val){
        this->val= val;
        this->Next= NULL;
    }
   
};

 class Linkedlist{
    public:
        Node*head;
        Node*tail;
        int size;
        Linkedlist(){
            tail= head= NULL;
            size= 0;
        }

        void insertAtHead(int val){
            Node*temp= new Node(val);
            if(index==0){
                head= tail= temp;
            }
            else if (index==size-1){
                tail->Next= temp->Next;
            }


        }
    };