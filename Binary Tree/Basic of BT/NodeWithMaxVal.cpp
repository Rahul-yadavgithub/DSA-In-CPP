#include<iostream>
#include<climits>
using namespace std;

class Node{
    public:
    int val;
    Node* right;
    Node* left;
    Node(int val){
        this->val= val;
        this->right= NULL;
        this->left= NULL;
    }
};


// Finding maximu value in a tree 

int maxVal(Node* root){
    if(root == NULL){
        return INT_MIN;
    }
    // int lmax = maxVal(root->left);
    // int rmax = maxVal(root->right);
    // return max(root->val, max(lmax, rmax));

    // Without using the max function 

    int lmax = maxVal(root->left);
    int rmax = maxVal(root->right);

    int maxval = root->val;

    if(lmax> maxval){
        maxval = lmax;
    }
    if(rmax > maxval){
        maxval = rmax;
    }
    return maxval;


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

    cout<< maxVal(a)<< endl;
}