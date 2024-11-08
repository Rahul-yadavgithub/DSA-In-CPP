#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cout<<("Enter the length of the array->");
    cin>>n;
    stack<int>st;
    for(int i= 1; i<=n; i++){
        int x;
        cout<<"Enter the value of element ->";
        cin>>x;
        st.push(x);
    }
    stack<int>temp;
    while(st.size()>0){
        int x = st.top();
        st.pop();
        temp.push(x);  
    }
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        int x= temp.top();
        temp.pop();
        st.push(x);
    }
}