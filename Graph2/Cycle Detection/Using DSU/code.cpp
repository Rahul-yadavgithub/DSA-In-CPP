#include<bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int x){
    
    return parent[x] = (parent[x] == x)? x : find(parent, parent[x]);
}

bool DSU(vector<int>& parent, vector<int>& rank, int a, int b){
    a = find(parent, a);
    b = find(parent, b);

    if(a == b) return true; // means cycle is detected

    if(rank[a]>= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        parent[a] = a;
        rank[a] =b;
    }
    return false;
}
int main(){
    int n, m;
    cin>>n>>m;
    // hear n -> is denoting the number of vertices and m-> denoting the number of edge present in the graph
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    while(m--){
        int x,y; // hear x and y are the node of the graph
        cin>>x>>y;
        bool b = DSU(parent, rank , x,y);
        if(b == true){
            cout<<"Cycle detected \n";
        }
    }
    
}
