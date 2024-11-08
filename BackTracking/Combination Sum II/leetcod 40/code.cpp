#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> result; // globally 

    void f(vector<int>& cand, int t, int idx, vector<int>& subset){  /*  t-> represent target sum , can -> represent candidate vector, subest make for the inserting the value inside and after the recursion we can also pop that values */
        if(t == 0){
            // means target we achived
            result.push_back(subset);
            return ;
        }

        if(idx == cand.size()) return; // beacuse you reached out of the index

        if(cand[idx] <= t){
            subset.push_back(cand[idx]);
            f(cand , t-cand[idx], idx+1, subset);
            subset.pop_back();
        }

        // avoid call
        // we doing this because in case their is many number which are same in the candidate vector which do same thing as the skiped value do thats why we doing this hear
        int j = idx+1;
        while( j< cand.size() && cand[j] == cand[j-1]){
            j++;
            // Matlab unsab ko skip kar do jo jo element same same hai 
        }
        f(cand, t, j, subset);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        result.clear();
        f(candidates, target, 0, subset);
        return result;
        
    }
};
 int main(){

 }