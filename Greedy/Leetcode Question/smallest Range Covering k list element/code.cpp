#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    typedef pair<int, pair <int,int>> pip;
    vector<int> ans(vector<vector<int>>& arr){
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        int n= arr.size();
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            mx = max(mx, arr[i][0]);
            pq.push({arr[i][0], {i,0}});
        }
        int mn = pq.top().first;
        int start = mn;
        int end = mx;
        while(true){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(col == arr[row].size()-1) break; /* means if you reached at the last index so after that no element left but we need atleast one element come from each vector*/
            pq.push({arr[row][col+1], {row, col+1}});
            mx = max(mx, arr[row][col+1]);
            int mn = pq.top().first;
            if(mx-mn <end-start){
                end = mx;
                start = mn;
            }
        }
        return {start, end};
    }


};
int main(){
    Solution ar;
    vector<vector<int>> arr = {{2,4,8,12,50},{50,60,70},{80,90,100}};
    vector<int> ans = ar.ans(arr);
    for(int i=0; i<2; i++){
        cout<<ans[i]<<" ";
    }

}