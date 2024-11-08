#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class Node{
    public:
    int val;
    Node*right;
    Node*left;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int arr[] , int n){
    queue<Node*> q;
    Node*root  = new Node(arr[0]);
    q.push(root);
    int i=1;
    int j= 2;
    while(q.size()>0 && i<n){
        Node* temp = q.front();
        q.pop();
        Node*l;
        Node*r;
        if(arr[i] == INT_MIN){
            l= new Node(arr[i]);
        }
        else{
            l = NULL;
        }
        if(arr[j] == INT_MIN && j!= n){
            r = new Node(arr[j]);
        }
        else{
            r = NULL;
        }

        temp->left = l;
        temp->right =r;

        if(l!= NULL) q.push(temp->left);
        if(r!= NULL) q.push(temp->right);

        i+= 2;
        j+= 2;
    }

}


    int main(){
        int arr[] ={1,2,3,4,5,INT_MIN,6,INT_MIN, 9,INT_MIN,INT_MIN,7,INT_MIN, INT_MIN, INT_MIN,8};

        int n = sizeof(arr)/sizeof(arr[0]);
        Node* root = construct(arr, n);


    }