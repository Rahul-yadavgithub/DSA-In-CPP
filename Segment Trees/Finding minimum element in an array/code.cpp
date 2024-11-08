#include<bits/stdc++.h>
using namespace std;

vector<int> st;

void buildTree(int arr[], int idx, int low, int high){
    // base case 
    if(low == high){
        st[idx] = arr[low];
        return ;
    }

    int mid = low + (high-low)/2;
    buildTree(arr, 2*idx+1, low, mid);
    buildTree(arr, 2*idx+2, mid+1, high);

    st[idx] = min(st[2*idx+1], st[2*idx+2]);
}

int GetMin(int idx, int low, int high, int& left, int& right){
      if(right<low || left>high)return INT_MAX;
      if(low>= left && high<= right) return st[idx];

      int mid = low + (high-low)/2;
      int leftMin = GetMin(2*idx+1, low, mid, left, right);
      int rightMin = GetMin(2*idx+2, mid+1, high, left, right);

      return min(leftMin, rightMin);
}
int main(){
    int arr[] = {1,4,2,8,6,4,9,3};
    int n = sizeof(arr)/ sizeof(arr[0]);
    st.resize(4*n);
    buildTree(arr, 0, 0, n-1);

    int l, r;
    int q;
    cin>>q;
    while(q--){
    cout<<"Enter the Range: ";
    cin>>l>>r;
    cout<<GetMin(0, 0, n-1, l,r);
    cout<<"\n";
    }


}


