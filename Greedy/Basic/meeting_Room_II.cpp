#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution{
    public:

    int meetingRooms(vector< vector< int>> & interval){
        vector<int> start;
        vector<int> ending;
        for(auto x: interval){
            start.push_back(x[0]);
            ending.push_back(x[1]);
        }
        sort(start.begin(), start.end());
        sort(ending.begin(), ending.end());
        
        int i =0; 
        int j =0;
        int room = 0;
        int ans =0;

        while(i< start.size() && j<ending.size()){
            if(start[i]<ending[j]){
                // Means meeting is started 
                room++;
                ans = max(room, ans);
                i++;
            }
            else if(start[i]> ending[j]){
                // means meeting ended
                room--;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> p = {{1,10},{2,7},{3,19},{8,12},{10,20},{11,30}};

    Solution ans;
    int n = ans.meetingRooms(p);

    cout<<n;
}