#include<iostream>
#include<vector>
#include<cstring> 

using namespace std;

typedef long long ll;

vector<ll> cap(10005, 0);  // Vector to store captain salaries
vector<ll> as(10005, 0);   // Vector to store assistant salaries
ll dp[10005][5005];        // DP table

int n;

ll calc(int i, int x) {
    if(dp[i][x] != -1) return dp[i][x];  // Use memoized result if available
    
    if(i == n) {  // Base case: No more pilots to assign
        return 0;
    }

    // Case 1: If x = 0, we have to assign this pilot as an assistant
    if(x == 0) {
        return dp[i][x] = calc(i+1, x+1) + as[i];
    }
    // Case 2: If x = n - i, we have to assign this pilot as a captain
    else if(x == n - i) {
        return dp[i][x] = calc(i+1, x-1) + cap[i];
    }
    // Case 3: We have a choice to make this pilot either an assistant or a captain
    else {
        return dp[i][x] = min(calc(i+1, x+1) + as[i], calc(i+1, x-1) + cap[i]);
    }
}

int main() {
    cin >> n;
    
    // Reading captain and assistant salaries
    for(int i = 0; i < n; i++) {
        cin >> cap[i] >> as[i];
    }

    // Initialize dp table with -1
    memset(dp, -1, sizeof(dp));

    // Start the calculation from the first pilot with 0 more assistants than captains
    cout << calc(0, 0) << endl;

    return 0;
}
