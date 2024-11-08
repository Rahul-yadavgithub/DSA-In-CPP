#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    int search(vector<int>& nums,int target){
        int n= nums.size();
        int low=0;
        int high= n-1;
        if(n==2){
            if(target==nums[0])return 0;
            else if(target==nums[1])return 1;
            else return -1;
        }
        //Finding pivot element/ index 
        int pivot= -1; // pivot means == smallest element 
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(mid==0)low= mid+1;
            else if(mid==n-1) high= mid-1;
            else if(nums[mid]<nums[mid+1] && nums[mid]< nums[mid-1]){
                pivot= mid;
                break;
            }
            else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                pivot = mid+1;
                break;
            }
            else if(nums[mid]>nums[high])low= mid+1;
            else high= mid-1;
        }
        // This code is for that when our vector is already sorted 
        if(pivot==-1){       //No rotation present
            low= 0;
            high= n-1;
            while(low<=high){
                int mid= low+ (high-low)/2;
                if(nums[mid]== target) return mid;
                else if(nums[mid]>target)high= mid-1;
                else low= mid+1;

            }
            return -1;
        }
        if(target>=nums[0] && target<= nums[pivot-1]){
            low=0;
            high=pivot-1;
            while(low<=high){
                int mid= low+ (high-low)/2;
                if(nums[mid]==target)return mid;
                else if(nums[mid]>target) high= mid-1;
                else low= mid+1;               
         }
        }
        else{
            low= pivot;
            high= n-1;
            while(low<=high){
                int mid= low+ (high-low)/2;
                if(nums[mid]==target)return mid;
                else if(nums[mid]>target) high= mid-1;
                else low= mid+1;
            }
        }
        return -1;

    }
};
int main(){
    vector<int>v;
    solution sol;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    int x= sol.search(v ,7);
    cout<<x;
   
}