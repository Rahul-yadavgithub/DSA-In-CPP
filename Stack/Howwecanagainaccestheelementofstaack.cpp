#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // we are intrested in print the element of stack
   // and again try to access same stack without any change
   stack<int>temp;
   while(st.size()>0){
    cout<<st.top()<<" ";
    int x = st.top();
    st.pop();
    temp.push(x);
   }
   // putting element back into the stack 
   while(temp.size()>0){
    int x = temp.top();
    temp.pop();
    st.push(x);
   }
   cout<<st.size();

}
