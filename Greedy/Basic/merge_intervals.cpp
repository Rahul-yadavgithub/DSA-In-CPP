#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[1]< b[1];
}
// one more thing if we sort the element a[0], b[0] in this case uou need to itrate from start to end like i =0 ;i<n-1 and vice versa in case of opposite 

class solution {
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(), cmp); // we sort the arry in increasing order on the basis of the second element
        vector<vector<int>> result;
        int n = intervals.size();
        result.push_back(intervals[n-1]);   // we simply push the last element of the vector 
        for(int i=n-2; i>=0; i--){             // and then apply a loop which travel all the vector element and check the condtition if condtion satisfy then push other wise not
            vector<int>curr = intervals[i];
            if(curr[1]>= result[result.size()-1][0]){
                result[result.size()-1][0] = min(curr[0], result[result.size()-1][0]);
                result[result.size()-1][1] = max(curr[1], result[result.size()-1][1]);
            }
            else result.push_back(intervals[i]);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    vector<vector<int>> p  = {{1,3},{2,6},{8,10}, {15,18}};
    solution ans;
    vector<vector<int>> result = ans.merge(p);

    for(int i =0; i< result.size(); i++){
        for(int j =0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";

        }
    }

    cout<<endl;

}