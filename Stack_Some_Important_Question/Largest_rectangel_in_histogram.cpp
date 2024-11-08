#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int gretest_area(vector<int>&arr){
    stack<int>st;
    // For NSI -> Next smallest index 
     int n= arr.size();
     int nsi[n];
     nsi[n-1]= n;
     st.push(n-1);
     for(int i= n-2; i>=0; i--){
        while(st.size()>0 &&  arr[st.top()]>= arr[i]){
            st.pop();
        }
        if(st.size()==0) nsi[i]= n;
        else  nsi[i]= st.top();
        st.push(i);
     }

     // For PSI -> previouse smallest index
     stack<int>gt;
     int psi[n];
     psi[0]=-1;
     gt.push(0);
     for(int i=1;i<n; i++){
        while(gt.size()>0 && arr[gt.top()]>= arr[i]) gt.pop();
            if(gt.size()==0) psi[i]=-1;
            else psi[i]= gt.top();
            gt.push(i);            
     }

     // Maximum area we have to do this 
     int maxArea = 0;
     for(int i=0;i<n; i++){
        int height= arr[i];
        int breadth= nsi[i]-psi[i]-1;
        int area= height*breadth;
        maxArea= max(maxArea,area);
     }
     cout<< maxArea;
     return maxArea;
}
int main(){
  vector<int>arr;
  int n;
  cout<<"Enter the length of vector->";
  cin>>n;
  for(int i=0; i<n; i++){
    cout<<"Enter the element of the vector ->";
    int x;
    cin>>x;
    arr.push_back(x);
  }
  cout<<endl;
  for(int i= 0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  gretest_area(arr);
}