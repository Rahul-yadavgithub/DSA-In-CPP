#include <iostream>
using namespace std;
     
     // This is the tree Node
    class Node {
        public:
        int val;
        Node*left;
        Node*right;
        Node(int val){
            this->val = val;
            this->left= NULL;
            this->right= NULL;
        }
     
    };

    // Now for displaying the values for that we need to make one function 

    void display(Node* root){
        if(root==NULL) return;
        cout<<root->val;
        display(root->left);
        display(root->right);

    }

    int main() {
        Node*a = new Node(1);  // a is working like a root in this case 
        Node*b =new Node(2);
        Node*c = new Node(3);
        Node*d = new Node(4);
        Node*e = new Node(5);
        Node*g = new Node(5);
        
        a->left= b;
        a->right =c;
        b->left =d;
        b->right =e;

        display(a);
    }