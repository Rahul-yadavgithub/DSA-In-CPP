#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define inf INT_MAX
using namespace std;

// This frist solution is recursive solution 
int f(int n){
    if(n == 1) return 0;
    if(n ==2 || n== 3) return 1;
    return 1+min({f(n-1), (n%2 == 0) ? f(n/2): inf, (n%3 ==0)? f(n/3): inf});
}

// Now using dp we need to write a solution top to down 

vector<int> dp;
int ftd(int n){
    if(n == 1) return 0;
    if(n == 2 || n == 3) return 1;
    if(dp[n] != -1) return dp[n];  // if dp[n] is already then simply return the value 

    return dp[n] = 1+ min({ftd(n-1), (n%2 == 0)? ftd(n/2): inf, (n%3 == 0)? ftd(n/3): inf});

}


// Now if we want to calculate by using bottom to top order

 int fbu(int n){
    dp.clear();
    dp.resize(n+1, -1);
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(int i=4; i<= n; i++){
        dp[i] = 1+ min({dp[i-1], (i%2 == 0)? f(i/2): inf, (i%3 == 0)? f(i/3): inf});
    }
    return dp[n];
 }
int main(){
    int n;
    dp.clear();
    dp.resize(10005,-1);
    cin>>n;
    cout<< fbu(n)<<"\n";
}