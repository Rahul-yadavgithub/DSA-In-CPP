#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> dp;
int k;
vector<int> h;

int fbu(){
    int n = h.size();
    dp.resize(100005 , INT_MAX);
    dp[n-1] = 0; // if we are at the last index then 
    for(int i =n-2; i>= 0; i--){   // we started form the 2nd last index and start filling the value in our dp vector
        for(int j =1; j<= k; j++){
            if(i+j >= h.size())break;   // This is a case when our index become the last index
            dp[i] = min(dp[i], abs(h[i]- h[i+j])+ dp[i+j]);  // dp[i] ke har ek index par values store karte jaa rhe hai 
        }
    }
    return dp[0];
}
int main(){
int n;
cin>> n>>k;
h.resize(n);
for(int i =0; i<n; i++){
    cin>>h[i];
}
cout<<fbu() <<"\n";
return 0;
   
}

// 10 4
// 40 10 20 70 80 10 20 70 80 60