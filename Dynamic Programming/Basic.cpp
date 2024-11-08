#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dp; // Initalisation of vector globaly 

int f(int n){
    if(n == 0 || n == 1) return n;

    // put your dp check
    if(dp[n] != -1) return dp[n]; // means abhi tak vo value not computed

    return dp[n] = f(n-1)+f(n-2); // jo value compute hue usko dp me store karo 
}
int main(){
    int n;
    cin>>n;
    dp.clear(); // use to remove all the garbage value if they are present in the vector
    dp.resize(n+1, -1); // dp[i] == -1 -> that ith subproblem is not yet computed
    cout<<f(n)<<"\n";
    return 0;
}