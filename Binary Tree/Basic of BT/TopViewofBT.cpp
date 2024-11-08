#include<iostream>
#include<queue>
#include<climits>
#include<unordered_map>
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

Node* construct(int arr[] , int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i =1;
    int j= 2;
    while(q.size()> 0 && i<n){
        Node*temp = q.front();
        q.pop();
        Node*l;
        Node*r;
        if(arr[i] != INT_MIN ){
            l =  new Node(arr[i]);
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

        temp->right = r;
        temp->left = l;

        if(l!= NULL) q.push(temp->left);
        if(r!= NULL) q.push(temp->right);

        i+= 2;
        j+= 2;
    }

    return root;
}
int levels(Node* root){
    if(root == NULL) return 0;

    return 1+ max(levels(root->left), levels(root->right));
}

void topview(Node* root){
    unordered_map<int, int> m;   // This map store the  <level value , root->val>
    queue< pair<Node* , int> > q;  // This queue store the < Node, level>
    pair<Node*, int> r;
    r.first = root;
    r.second = 0;
    q.push(r);
    while(q.size()>0){
        Node* temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if(m.find(level) == m.end()){
            m[level] = temp->val;
        }
        if(temp->left != NULL){
            pair<Node* , int>p;
            p.first = temp->left;
            p.second = level-1;
            q.push(p);
        }
        if(temp->right != NULL){
            pair<Node*, int> p;
            p.first = temp->right;
            p.second = level+1;
            q.push(p);
        }
    }

    int minLevel = INT_MAX;
    int maxLevel = INT_MIN;

    for(auto x: m){
        int level = x.first;
        minLevel = min(minLevel,level);
        maxLevel = max(maxLevel, level);
    }

    for(int i =minLevel; i<=maxLevel; i++){
        cout<<m[i]<<" ";
    }
    cout<< endl;  
    
}



int main(){
    int arr[] = {1,2,3,4,5, INT_MIN, 6, INT_MIN,INT_MIN, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = construct(arr, n);
    topview(root);
    
}
