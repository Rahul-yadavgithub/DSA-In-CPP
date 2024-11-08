#include<iostream>
using namespace std;

 class Node{
    public:
    int val;
    Node*right;
    Node*left;

    Node(int val){
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
 };

 void display(Node* root){
    if(root == NULL){
        return;
    }
    cout<< root->val <<" ";
    display(root->left);
    display(root->right);
 }

 int size(Node* root){
    if(root == NULL){
        return 0;
    }
    int count = 0;

    if(root->left != NULL && root->right != NULL){
        count+2;
    }

    count = 1+ size(root->left)+ size(root->right);

    return count;
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

    cout<<endl;

    cout<<size(a);

 }



