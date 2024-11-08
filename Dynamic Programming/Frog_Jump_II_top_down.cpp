#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> h; // Height of the stone 
vector<int> dp;

int k;
int f(int i){
    if(i>= h.size()){
        return INT_MAX;
    }
    if(i == h.size()-1){
        // means you are at the last stone 
        return 0;
    }
    if(dp[i] != -1) return dp[i]; // means ith tearm already computed 
    int ans = INT_MAX;
    for(int j =1; j<= k; j++){
        if(i+j >= h.size()) break;
        ans = min(ans, abs(h[i]-h[i+j])+ f(i+j));
    }
    return dp[i] = ans;  // If that is not computed then store in the dp vector;
} 

int main(){
    int n;
    dp.resize(n,-1);
    cin>>n>>k;
    h.resize(n);
    for(int i=0; i<n; i++){ 
        cin>>h[i];
    }
    cout<<f(0)<<"\n";
    return 0;
}


// 10 4
//40 10 20 70 80 10 20 70 80 60