#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int arr[], int n){
    queue<Node*>q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i =1; 
    int j = 2;
    while(q.size()>0 && i<n){
        Node* temp = q.front();
        q.pop();
        Node*l;
        Node*r;
        if(arr[i] != INT_MIN){
            l = new Node(arr[i]);
        }
        else{
            l = NULL;
        }
        if(arr[j] != INT_MIN && j<n){
            r= new Node(arr[j]);
        }
        else{
            r = NULL;
        }

        temp->left = l;
        temp->right = r;

        if(l!= NULL)q.push(temp->left);
        if(r!= NULL)q.push(temp->right);

        i+=2;
        j+=2;
    }
    return root;
}

int sizeofTree(Node* root){
    if(root== NULL) return 0;
    return 1+ max(sizeofTree(root->left), sizeofTree(root->right));
}

 bool isCBT(Node* root){
       int size = sizeofTree(root);
       int count = 0;
        queue<Node* > q;
        q.push(root);
        while(count<size){
            Node* temp = q.front();
            q.pop();
            count++;
           if(temp!= NULL){
            q.push(temp->left);
            q.push(temp->right);
           }
        }
        if(q.size()>0){
            Node*temp  = q.front();
            if(temp!= NULL) return false;
            q.pop();
        }
        return true;
        
    }


bool isMax(Node* root){
    if(root == NULL) return true;
    if(root->left != NULL && root->val<root->left->val) return false;
    if(root->right != NULL && root->val< root->right->val) return false;
    return isMax(root->left) && isMax(root->right);
}
int main(){
    int arr[] = {20, 15,10,8,11,INT_MIN,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node*root = construct(arr, n);
    if(isCBT(root) &&isMax(root)) cout<<"Tree is MaxHeap";
    else cout<<"Tree is not a MaxHeap";

}