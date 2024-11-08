#include<bits/stdc++.h>
using namespace std; 

vector<int> st; // This is our segment tree vector which store the values of the given node 


// code for Building the segment Tree

void buildTree(int arr[], int idx, int low, int high){   // hear our idx is the index of the segement tree not the array index
    
    // Base case 
    if(low == high){
        st[idx] = arr[high]; // hear hight and low both are equal so you can fill any of them
        return ;
    }
    int mid = low+ (high-low)/2;

    // Building tree for the left side 

    buildTree(arr, 2*idx+1, low, mid);

    // Building tree for the right side

    buildTree(arr, 2*idx+2, mid+1, high);

    // Now we need to fill the maximum value of the children node into the parent node

    st[idx] = max(st[2*idx+1], st[2*idx+2]);

}

// Code For building the Get Max value for any range 

int getMax(int idx, int low, int high, int& left, int& right){

    // Now check the cases 
    // 1-> If our Range if not come inside the => (low, high) range
    if(right<low || left>high)return INT_MIN;

    // 2-> If our (low, high) come inside the range then 

    if(low>= left &&  high<= right)  return st[idx];

    // Now the 2 case left in which we need to call the next node which run if upper case not run 
    
    int mid = low + (high- low)/2;
    int leftMax = getMax(2*idx+1, low, mid, left, right);
    int rightMax = getMax(2*idx+2, mid+1, high, left, right);

    return max(leftMax, rightMax);

}


int main(){
    int arr[] = {1,4,2,8,6,4,9,3};
    int n = sizeof(arr)/ sizeof(arr[0]);
    st.resize(4*n);
    buildTree(arr, 0,0, n-1);
    int l,r;
    cout<<"Enter the range : ";
    cin>>l>>r;
    cout<<getMax(0, 0,n-1, l, r)<<endl;
}