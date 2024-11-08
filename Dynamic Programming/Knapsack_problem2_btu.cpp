#include<iostream>
#include<vector>
#include<climits>
#define ll long long int
using namespace std;

vector<vector<ll>> dp;

// Knapsack problem 2 solution 

// row denote the -> item koun sa hai 
// colum denotes the->  target value kya hai

ll fbu(vector<int>& wts, vector<int>& val, int tv, int W){
    dp.resize(105,vector<ll> (100005, INT_MAX));   // This line mean 105 row and 100005 column in the 2D vector
    int n = wts.size();   // we can say that n is our total possible input for the weight that is if we campair with main function so int n, W written so hear n and their n are equal

    // we make the for loop for that if any target value = 0 then our dp store the 0
    for(int i =0; i< dp.size(); i++){  // dp.size -> denotes that how many rows present
        dp[i][0] = 0;
    }

    for(int idx = n-1; idx>=0; idx--){
        for(int j = 0; j <= tv; j++){
            ll ans = INT_MAX;
            // not pick case
            ans = min(ans , dp[idx+1][j]);
            // pick case
            if(val[idx]<= j){
                ans =min(ans, wts[idx]+ dp[idx+1][j-val[idx]]);
            }
            dp[idx][j] = ans;
        }
    }
    int result = -1;
    for(int i =0; i<= n*1000; i++){
        if(dp[0][i] <= W){
            result = i;
        }
    }
    return result;
}
int main(){
    int n, W;  
    cin>>n>>W;
    vector<int> wts, val;
    for(int i=0; i<n; i++){
        int w, v;
        cin>>w>> v;
        wts.push_back(w);
        val.push_back(v);
    }
    cout<< fbu(wts, val, n*1000, W);

}