#include<iostream>
#include<stack>
using namespace std;
void print(stack<int>st){
    stack<int>temp;
    while(st.size()>0){
        int x= st.top();
        st.pop();
        temp.push(x);
    }
    while(temp.size()>0){
        int x= temp.top();
        cout<<temp.top()<<" ";
        temp.pop();
        st.push(x);
    }
}
int main(){
stack<int>m;
stack<int>a;
stack<int>st;
    int n;
    cout<<"Enter the length of the stack->";
    cin>>n;
    for(int i=1; i<=n;i++){
        int x;
        cout<<"Enter the element of the stack->";
        cin>>x;
        st.push(x);
    }
    print(st);
    cout<<endl;
    while(st.size()>0){
        int x= st.top();
        st.pop();
        m.push(x);
    }
    while(m.size()>0){
        int x = m.top();
        m.pop();
        a.push(x);
    }
    while(a.size()>0){
        int x= a.top();
        a.pop();
        st.push(x);
    }
    print(st);
}