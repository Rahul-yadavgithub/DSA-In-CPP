#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Aproch =>   first sort the intervals on the basis of the second element and then compair second element of the previour vector to the current first element of the vector if the condition pre[i][1]> curr[i][0] then increase the count value

bool cmp(vector<int>& a, vector<int>& b){
    return a[1]< b[1];
}
class Solution{
    public:
    int NonOverlappingInterval(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(), cmp);
        int count =0;
        int n = intervals.size();
        int lastEndTime = intervals[0][1]; // This represent the second element of the first interval
        for(int i=1; i<n; i++){
            if(lastEndTime> intervals[i][0]){
                count++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return count;
    }
};
int main(){
    vector<vector<int>> p = {{1,2},{2,3},{1,3},{3,4}};
    
    Solution ans ;
    int n = ans.NonOverlappingInterval(p);
    cout<<n;

}
