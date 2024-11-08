#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#define ll long long int
using namespace std;

ll dp[105][105];

// Function to calculate the sum mod 100 of the subarray
ll g(vector<int>& colors, int i , int j){
    ll result = 0;
    for(int m = i; m<= j; m++){
        result = (result % 100 + colors[m] % 100) %100;
    }
    return result;
}

// Bottom-up dynamic programming solution
ll fbu(vector<int>& colors){
    memset(dp, 0, sizeof dp);
    int n = colors.size();

    for(int len = 2; len <= n; len++){ // length of the subarray
        for(int i = 0; i <= n-len; i++){ // starting index
            int j = i + len - 1; // ending index
            dp[i][j] = LLONG_MAX; // Initialize dp[i][j] to a large value
            for(int k = i; k <= j-1; k++){ // partition point
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + g(colors, i, k) * g(colors, k+1, j));
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    while(cin >> n){
        vector<int> colors;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            colors.push_back(x);
        }
        cout << fbu(colors) << "\n";
        colors.clear();
    }
}
