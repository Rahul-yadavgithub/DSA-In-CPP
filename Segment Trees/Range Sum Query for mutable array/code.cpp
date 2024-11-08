#include<bits/stdc++.h>
using namespace std;


class NumArray {
public:

    vector<int> st; // making segment tree
    int n;
    void buildTree(vector<int>& nums , int idx, int low, int high){
        if(low == high){
            st[idx] = nums[low];
            return;
        }
        int mid = low+ (high-low)/2;
        buildTree(nums,2*idx+1, low, mid);
        buildTree(nums, 2*idx+2, mid+1, high);
        st[idx] = st[2*idx+1] +st[2*idx+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n);
        buildTree(nums,0, 0, n-1);    
    }




    void updateval(int idx ,int low, int high, int& index, int& val){
        if(low == high){
            st[idx] = val;
            return ;
        }
        int mid = low+ (high-low)/2;
        if(index<=mid) updateval(2*idx+1, low, mid, index, val);
        else updateval(2*idx+2, mid+1, high, index, val);

        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    
    void update(int index, int val) {
        updateval(0, 0, n-1, index, val);
        
    }



    int getSum(int idx, int low, int high, int& left, int& right){
        if(right<low || left>high) return 0;
        if(left <= low && right>= high) return st[idx];
        int mid = low+ (high-low)/2;

        int leftSum = getSum(2*idx+1, low, mid, left, right);
        int rightSum = getSum(2*idx+2, mid+1, high, left, right);
        return leftSum+ rightSum;
    }
    int sumRange(int left, int right) {
        return getSum(0, 0,n-1, left, right);    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
int main(){

}