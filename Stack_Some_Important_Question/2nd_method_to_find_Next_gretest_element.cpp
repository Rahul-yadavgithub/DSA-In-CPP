//TC = O(n) and the SC= O(n)
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]= {3,1,2,5,4,6,2,3};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    stack<int>st;
    int nge[n];
    nge[n-1]= -1;
    st.push(arr[n-1]);
    // Three step are involve in this case 1- pop, 2- ans, 3- push
    for(int i=n-2; i>=0;i--){

    // pop the element which are less the the arr[i] element from the stack
    while(st.size()>0 && st.top()<=arr[i]){
        st.pop();
    }

    // add the ans for the give condition 
    if(st.size()==0)nge[i]=-1;
    else nge[i]= st.top();
     
     // push the element this is done in each and every cases of the operation 
    st.push(arr[i]);
    }
     //print the arr
    for(int i=0; i<n; i++){
        cout<<nge[i]<<" ";

    }
    cout<<endl;
}