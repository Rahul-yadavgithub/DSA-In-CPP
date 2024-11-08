#include<iostream>
using namespace std;
#include<stack>
int main(){
    stack<int>st;
    int n;
    cout<<"Enter the length of the stack->";
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cout<<"Enter the element of the stack->";
        cin>>x;
        st.push(x);
    }
    cout<<endl;
    stack<int>temp;
    while(st.size()>0){
        cout<<st.top()<<" ";
        int x= st.top();
        st.pop();
        temp.push(x);
    }
    while(temp.size()>0){
       
        int x= temp.top();
        temp.pop();
        st.push(x);
    }
}
