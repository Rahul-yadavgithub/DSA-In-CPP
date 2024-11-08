#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node*right ; 
    Node*left;
    Node(int val){
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }

};

int level(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftlevel = level(root->left);   // Correctly initialize and assign
    int rightlevel = level(root->right); // Correctly initialize and assign

    // Determine the maximum level between left and right
    if (leftlevel < rightlevel) {
        return rightlevel + 1;
    } else {
        return leftlevel + 1;
    }
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

    cout<< level(a)<< endl;

}