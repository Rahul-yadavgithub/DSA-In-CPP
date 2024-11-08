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

void display(Node*head){
    Node*temp= head;
    while(temp!= NULL){
        cout<<temp->val<<" ";
        temp= temp->Next; 
    }
    cout<<endl;
}


 Node* deleteNode(Node* head , Node*target){
    if(head==target){
        head=head->Next;
        return head;
    }
    Node* temp= head;
    while(temp->Next!=target){
        temp= temp->Next;
    }
    temp->Next= temp->Next->Next;
    return head;
}

int main(){
   Node*a= new Node(10);
   Node*b= new Node(20);
   Node*c= new Node(30); 
   Node*d= new Node(40);
   Node*e= new Node(50);
   a->Next= b;
   b->Next = c;
   c->Next= d;
   d->Next= e;
   Node* head = a;
   display(head); 
    head= deleteNode(head,a);
   display(head);
   
}