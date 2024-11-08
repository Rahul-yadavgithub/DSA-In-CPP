#include<iostream>
#include<vector>
#include<string>
#define ll long long int
using namespace std;

vector<ll> dp;

ll fbu(string & str){
    dp.resize(5005, 0);
    
    dp[0] = (str[0] != '0');  // This condition means if str[0] != '0' then condition true and dp[0] assigned 1  value else assigned 0 value
    if(str.size() > 1){
        if(str[1] != '0'){     // Two cases come in this case one when we take seperately and another when we take simultenously
            dp[1] += dp[0];
        }
        if( str[1-1] -'0' >0 && (str[0] -'0')*10 + (str[1]-'0') <= 26) dp[1]++;
    }

    for(int i=2; i< str.size(); i++){
        ll ans = 0;
        if(str[i] -'0' >0){
            ans += dp[i-1];
        }
        if(str[i-1]-'0'> 0 && (str[i-1]-'0')*10 + (str[i]-'0') <= 26){
            ans += dp[i-2];
        }
        dp[i] = ans;
    }
    return dp[str.size()-1];
}
int main(){
    string n;
    cin>> n;
    while(n[0] != '0'){
       dp.clear();
       cout<<fbu(n)<<"\n";
       cin>>n; 
    }

}