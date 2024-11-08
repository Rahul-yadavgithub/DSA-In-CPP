#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#define ll long long int
using namespace std; 

ll dp[105][105]; // initialise the dp

ll g(vector<int>& colors, int i , int j){
    ll result = 0;
    for(int m = i; m<= j; m++){
        result = (result % 100 + colors[m] % 100) %100;
    }
    return result;
}

 ll f(vector<int>& colors, int i, int j){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll result = INT_MAX;
    for(int k = i; k<= j-1; k++){
        result = min(result, f(colors, i, k)+ f(colors, k+1, j)+ g(colors, i, k)* g(colors, k+1, j));
    }
    return dp[i][j] = result;
 }
int main(){
    int n;
    while(cin>>n){
        vector<int> colors;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            colors.push_back(x);
        }
        memset(dp, -1, sizeof dp);  // This is used to set the dp initial value -1 in each and every box of the array
        cout<<f(colors, 0, colors.size()-1)<<"\n";
        colors.clear();
    }

}