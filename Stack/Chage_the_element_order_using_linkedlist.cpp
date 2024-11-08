#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    Node*Next;
    int val;
    Node*head;
    Node(int val){
        this->Next= NULL;
        this->val= val;
        head= NULL;
    }
    
};
void display(Node*head){
    Node*temp= head;
    while(temp!= NULL){
        cout<<temp->val<<" ";
        temp= temp->Next;
    }
}
void displayrev(Node*head){
    // Node*temp= head;
    if(head==NULL){
        return;
    }
    displayrev(head->Next);
    cout<<head->val<<" ";
}
void stack_display(stack<int>st){
    while(st.size()>0){
        cout<<st.top()<<" ";
        st.pop();

    }
}

int main(){
    int n;
    cout<<"Enter the length of the stack->";
    cin>>n;
    stack<int>st;
    for(int i =1; i<=n; i++){
        int x;
        cout<<"Enter the element of the stack->";
        cin>>x;
        st.push(x);
    }
    stack_display(st);
    cout<<endl;
    Node*head= NULL;
    for(int i=1; i<=n; i++){
        int x= st.top();
        Node*temp= new Node(x);
        st.pop();
        temp->Next= head;
        head= temp;
    }
    display(head);
    cout<<endl;
    displayrev(head);
    cout<<endl;
    for(int i= 1; i<=n; i++){
        Node*temp= head;
        int x= temp->val;
        temp= temp->Next;
        head= temp;
        st.push(x);
    }
    stack_display(st);

}