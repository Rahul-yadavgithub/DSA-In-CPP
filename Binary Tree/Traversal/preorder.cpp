#include<iostream>
using namespace std;
 
class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
  
    }

};

 void display(Node* root){
        if(root == NULL) return ;
        cout<<root->val <<" ";  
        //                   If we print the value of root hear this is know as preorder 
        display(root->left);
        //                         if we print our value hear then then this is know as in ordered
        display(root->right);

        //                        if we print our value hear this is know as post order 
    }

int main(){
   Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);

    a->left = b;
    a->right= c;
    b->left = d;
    b->right= e;
    c->left = f;

    display(a);
}