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
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int arr[], int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i =1;
    int j=2;
    while(q.size()>0 && i<n ){
          Node*temp = q.front();
          q.pop();
          Node*l;
          Node*r;
          if(arr[i]!= INT_MIN){
            l = new Node(arr[i]);
          }
          else{
            l = NULL;
          }
          if(arr[j]!= INT_MIN && j< n){
            r = new Node(arr[j]);
          }
          else{
            r = NULL;
          }

          temp->left = l;
          temp->right = r;

          if(l!=NULL)q.push(temp->left);
          if(r!= NULL)q.push(temp->right);

          i+=2;
          j+=2;


    }
    return root;

}
void inorder(Node* root, vector<int>& ans){
    if(root == NULL) return ;
    inorder(root->right, ans);
    ans.push_back(root->val);
    inorder(root->left, ans);

}
void preorder(Node* root, vector<int>&ans ,int& i){
    if(root== NULL) return;
    root->val = ans[i++];
    preorder(root->left, ans , i);
    preorder(root->right,ans, i);
}
void levelOrderQueue(Node* root){
    queue<Node*>q;
    q.push(root);
    while(q.size()>0){
        Node*temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left !=NULL) q.push(temp->left);
        if(temp->right !=NULL) q.push(temp->right);
    }
    cout<<endl;
}
int main(){
    int arr[] = {10,5,16,1,8,12,20};
    int n = sizeof(arr)/ sizeof(arr[0]);
    Node* root= construct(arr, n);
    vector<int>ans;
    inorder(root, ans);
    levelOrderQueue(root);
    int i=0;
    preorder(root, ans,i);
    levelOrderQueue(root);
  


}
