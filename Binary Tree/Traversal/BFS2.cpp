#include<iostream>
using namespace std;

class Node{
    public:
    int val; 
    Node* right;
    Node* left;
    Node(int val){
        this->val = val;
        this->right = NULL;
        this->left = NULL;

    }
};

int levels(Node* root){
    if(root == NULL) return 0; // base case
    return 1+ max(levels(root->left), levels(root->right));
}

// Now for obtimizing our code we need to stop the call after reaching to the required level by adding some values

void nthLevels(Node* root , int curr, int level){   
    if(root == NULL) return; 
    if(curr == level){
        cout<< root->val <<" ";
        return;
    }
    nthLevels(root->left, curr+1, level);
    nthLevels(root->right, curr+1, level);
}

// If we want to print the thing from right to left what we can do is

void nthLevelsRev(Node* root , int curr, int level){
    if (root == NULL) return;
    if(curr == level){
        cout<< root->val <<" ";
        return;
    }
    nthLevelsRev(root->right, curr+1, level);
    nthLevelsRev(root->left , curr+1, level);
}

void levelOrder(Node* root){
    int n = levels(root);
    for(int i =1 ; i<=n; i++){
        nthLevelsRev(root, 1,i);
        cout<<endl;

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

    levelOrder(a);
}