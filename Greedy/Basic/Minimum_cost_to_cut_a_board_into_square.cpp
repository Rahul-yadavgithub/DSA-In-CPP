#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

bool cmp(int x, int y){
    return x>y;
}

ll minCostToBreakGrid(int n, int m, vector<ll>& vertical , vector<ll>& horizontal){
    sort(vertical.begin(), vertical.end(), cmp);
    sort(horizontal.begin(), horizontal.end(), cmp);
    int hz =1;
    int vr =1;
    ll totalcost =0;
    int h =0;
    int v=0;

    while(h<horizontal.size() && v< vertical.size()){
        if(vertical[v]> horizontal[h]){
            totalcost = totalcost+ vertical[v]*vr;
            hz++;
            v++;
        }
        else{
            totalcost = totalcost+ horizontal[h]*hz;
            vr++;
            h++;
        }
    } 
    while(h<horizontal.size()){
        totalcost = totalcost+ horizontal[h]*hz;
        vr++;
        h++;
    }
    while(v< vertical.size()){
        totalcost = totalcost + vertical[v]*vr;
        hz++;
        v++;
    }
    return totalcost;

}
int main(){
    // int arr1[] ={2,1,3,1,4};
    // int arr2[] ={4,1,2};
    int n, m;
    cin>>m>>n;
    vector<ll> horizontal, vertical;
    for(int i=0; i<m-1; i++){
        int x;
        cin>>x;
        vertical.push_back(x);
    }
    
    for(int i=0; i<n-1; i++){
        int x ;
        cin>>x;
        horizontal.push_back(x);
    }
    
    cout<<minCostToBreakGrid(n,m, vertical, horizontal);

}