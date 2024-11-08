#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector< vector<int>> dp;
int main(){
int n;
cin>> n;
vector<int> v(n);
dp.clear();
dp.resize(1005, vector<int> (1000, 0));

for(int i =0; i<n; i++){
    cin>>v[i];
}
for(int len = 3; len <= n; len++){
    for(int i=0; i+len-1 <n; i++){
        int j = i+ len-1;
        dp[i][j] = INT_MAX;
        for(int k = i+1; k< j; k++){
            dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j] + v[i]*v[k]*v[j]);
        }
    }
}
cout<< dp[0][n-1]; 

}