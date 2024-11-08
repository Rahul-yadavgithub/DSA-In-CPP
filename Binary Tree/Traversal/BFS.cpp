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

// BFS Travesal 


void nthLevel(Node* root, int curr, int level){
    if(root == NULL) return;
    if(curr == level) cout<<root->val <<" ";
    nthLevel(root->left, curr+1, level);
    nthLevel(root->right,curr+1, level);

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

    nthLevel(a, 1, 1);
}
