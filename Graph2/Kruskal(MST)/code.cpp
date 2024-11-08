#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int find(vector<int>& parent, int x){
    return parent[x] = (parent[x] == x)? x: find(parent, parent[x]);
}

void Union(vector<int>& parent, vector<int>& rank, int a, int b){
    a = find(parent, a);
    b = find(parent, b);

    if(a == b) return;

    if(rank[a]>= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] =b;
    }
}


class Edge{
    public:
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2){
    return e1.wt< e2.wt;
}

ll kruskals(vector<Edge> &input, int n, int e){
    // First of all sort the input on the basis of the weight

    sort(input.begin(), input.end(), cmp);
    vector<int> parent(n+1);
    vector<int> rank(n+1, 1);
    for(int i = 0; i<= n; i++){
        parent[i] = i;
    }

    int edgeCount = 0; // total edge for any connected uncycling graph = n-1 or we can say in any tree if their is n node then total no of edge is n-1
    int i = 0; // used to track that currently you are on which edge e
    
    // Now apply the loop which is while loop 
    ll ans = 0;

    while(edgeCount < n-1 && i< input.size()){
        Edge curr = input[i]; // hear we get min weight edge becase our input is sorted

        // Now calculate the source and destination node parent 

        int srcPar = find(parent, curr.src);
        int destPar = find(parent, curr.dest); 

        if(srcPar != destPar){
            Union(parent, rank, srcPar, destPar);
            ans += curr.wt;
            edgeCount++;
        }
        i++; // whether you picked the edge or not we still need to go to next edge
    }
    return ans;
}

int main(){

    int n ,e;
    cin>>n>>e;
    vector<Edge> v(e);
    for(int i =0; i< e; i++){
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskals(v, n,e)<<"\n";

}