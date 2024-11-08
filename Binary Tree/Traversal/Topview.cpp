#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

Node* construct (int arr[] , int n){
 
 queue<Node*> q;
 Node* root = new Node(arr[0]);
 q.push(root);
 int i = 1;
 int j = 2;
 
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
    if(arr[j] != INT_MIN && j != n){
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

void nthLevel(Node*root, int curr, int level){
    if(root == NULL) return;

    if(curr == level){
        cout<< root->val <<" ";
    }
    nthLevel(root->left, curr+1 , level);
    nthLevel(root->right , curr+1, level);
}

int levels(Node* root){
    if(root == NULL) return 0;
    return 1+ max(levels(root->left), levels(root->right));
}

void levelOrder(Node* root){
    int n = levels(root);
    for(int i= 1;i<=n; i++){
        nthLevel(root,1,i);
        cout<<endl;
    }
}

void minHorLevel(Node* root, int& minLevel, int& maxLevel, int level){
    if(root == NULL) return ;
    minLevel = min(minLevel, level);
    maxLevel = max(maxLevel,level );
    minHorLevel(root->left, minLevel,maxLevel, level-1);
    minHorLevel(root->right, minLevel,maxLevel, level+1);
}

void topview(vector<int>& top, Node* root , int level){
    if(root == NULL) return;
    if(top[level] == INT_MIN){
        top[level] = root->val;
    }
    topview(top, root->left, level-1);
    topview(top, root->right, level+1);

}

int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN, 9,INT_MIN,INT_MIN,7,INT_MIN, INT_MIN, INT_MIN,8};
    int n = sizeof(arr)/ sizeof(arr[0]);

    Node* root = construct(arr, n); 

    int minLevel =0 ;
    int maxLevel =0;
    minHorLevel(root, minLevel,  maxLevel, 0);
    int m = maxLevel-minLevel+1;
    vector<int>top(m,INT_MIN);
    topview(top, root, -minLevel);
    for(int i=0; i<top.size(); i++){
        cout<<top[i]<<" ";
    }
}