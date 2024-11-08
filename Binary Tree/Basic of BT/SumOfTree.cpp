 #include<iostream>
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

 void display(Node* root){
    if(root == NULL){
        return;
    }
    cout<< root->val <<" ";
    display(root->left);
    display(root->right);
 }

int sum(Node* root){
    if(root == NULL) return 0;
    // int leftSum = sum(root->left);
    // int rightSum = sum(root->right);
    // int ans = root->val + leftSum + rightSum;

    // In the place of these three line we can also write one line code 

    int ans = root->val + sum(root->left) + sum(root->right);
    return ans;
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

    display(a);
    cout<<endl;
    cout<<sum(a);

}
