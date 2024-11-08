#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class Node{
    public:
    int val ;
    Node*right;
    Node*left;
    Node(int val){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

Node* construct(int arr[], int n){
queue<Node* > q;
Node* root = new Node(arr[0]);
q.push(root);
int i=1;
int j= 2;
Node*r;
Node*l;
while(q.size()>0 && i<n){
    Node*temp = q.front();
    q.pop();
    if(arr[i] == INT_MIN ){
        l = new Node(arr[i]);
    }
    else{
        l= NULL;
    }
    if(arr[j]== INT_MIN && j!= n){
        r = new Node(arr[j]);
    }
    else{
        r = NULL;
    }

    temp->left = l;
    temp->right = r;

    if(l != NULL) q.push(temp->left);
    if(r != NULL)q.push(temp->right);

    i+=2;
    j+=2;
}
return root;
}

 Node* inorderpredecessor(Node*root ,int target){
    if(root->left == NULL) return NULL;
    Node*pred = root->left;
    while(pred->right != NULL){
        pred = pred->right;
    }
    return pred;

 }

int main(){
    int arr[] ={10,5,20,2,8,15,25,INT_MIN,4,INT_MIN, INT_MIN, 12,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,13};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = construct(arr, n);

    inorderpredecessor(root,10);


}