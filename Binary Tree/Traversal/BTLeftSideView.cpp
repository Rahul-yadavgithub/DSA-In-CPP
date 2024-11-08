#include<iostream>
#include<climits>
#include<queue>
#include<vector>
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
 
 // Making the tree 

 Node* construct(int arr[], int n){
   queue<Node*> q;
   Node*root = new Node(arr[0]);
   q.push(root);
   int i =1;
   int j= 2;
   while(q.size()>0 && i<n){
    Node*temp = q.front();
    q.pop();
    Node*l;
    Node*r;
    if(arr[i] != INT_MIN){
        l = new Node(arr[i]);
    }
    else{
        l = NULL;
    }
    if(arr[j] != INT_MIN && j!= n){
        r = new Node(arr[j]);
    }
    else{
        r = NULL;
    }
    
    temp->left = l;
    temp->right = r;

    if(l != NULL) q.push(temp->left);
    if(r != NULL) q.push(temp->right);

    i+=2;
    j+=2;

   }
   return root;
 }



// left side view of binary tree 

int levels(Node* root){
    if(root == NULL) return 0;
    return 1+ max(levels(root->left), levels(root->right));
}

void preorder(Node* root, int level , vector<int>& ans){
    if(root == NULL) return;

    ans[level] = root->val;
    preorder(root->right, level+1, ans);
    preorder(root->left, level+1,ans);
}

int main(){
    int arr[] = {1,2,3,4,5, INT_MIN, 6,7, INT_MIN,8, INT_MIN,9,10,INT_MIN,11,INT_MIN,12, INT_MIN, 13, INT_MIN, 14,15,16,INT_MIN, 17,INT_MIN, INT_MIN, 18,INT_MIN, 19,INT_MIN, INT_MIN,INT_MIN,20,21,22,23,INT_MIN, 24,25,26,27,INT_MIN, INT_MIN,28,INT_MIN,INT_MIN,};

    int n = sizeof(arr)/ sizeof(arr[0]);
    Node* root = construct(arr, n);
    vector<int>ans(levels(root),0);
    int m = levels(root);
   

    preorder(root, 0, ans);

    for(int i=0; i< m; i++){
        cout<<ans[i]<<" ";
    }
}