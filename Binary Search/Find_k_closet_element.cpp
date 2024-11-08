#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class solution {
    public:
    vector<int>fingClosetElements(vector<int>&arr, int k, int x){
        // S.C== O(K)
        // T.C== O(logn +klogk)
        int n= arr.size();
        vector<int>ans(k);
        if(x<arr[0]){
            for(int i=0; i<k;i++){
                ans[i]= arr[i];
            }
            return ans;
        }
        if(x>arr[n-1]){
            int i= n-1;
            int j= k-1;
            while(j>=0){
                ans[j]= arr[i];
                j--;
                i--;
            }
            return ans;
        }
        int low= 0;
        int high= n-1;
        int mid= -1;
        int t= 0;  // representing index of the ans element
        bool flage= false;
        // binaray Search
        while(low<= high){
            mid= low+ (high-low)/2;
            if(arr[mid]==x){
                flage= true;
                ans[t]= arr[mid];
                t++;
                break;
            }
            else if(arr[mid]>x)high= mid-1;
            else low = mid+1;
        }
        int lb= high; // Last element smaller thant x
        int ub= low;  // First element greater than x
        if(flage==true){
            // means if we find the element which is exactly equal to the x element in the give array then we assign these thing
            lb= mid-1; // lb => lower Bound
            ub= mid+1;  // ub => upper Bound
        }
        while(t<k && lb>=0 && ub<=n-1){
            int d1= abs(x-arr[lb]);
            int d2= abs(x- arr[ub]);
            if(d1<=d2){
                ans[t]= arr[lb];
                lb--;
            }
            else{  // d2<d1
                ans[t]= arr[ub];
                ub++;            
            }
            t++;   // written outside because in both the cases t++ are same 
        }
        if(lb<0){
            while(t<k){
                ans[t]= arr[ub];
                t++;
                ub++;
            }
        }
        if(ub>n-1){
            while(t<k){
                ans[t]= arr[lb];
                lb--;
                t++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    solution sol;
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
     
     int k= 4;
     int x= -1;
     sol.fingClosetElements(v,k,x);
     for(int i=0;i<k; i++){
        cout<<v[i]<<" ";
     }
}