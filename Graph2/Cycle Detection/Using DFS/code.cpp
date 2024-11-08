#include<bits/stdc++.h>
using namespace std;


vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

bool dfs(int src, int parent, unordered_set<int>& vis){
     vis.insert(src);
     for(auto neighbour: graph[src]){
        if(vis.count(neighbour) && neighbour != parent){
            // means cycle is detected 
            return true;
        }
        if(!vis.count(neighbour)){
            bool res = dfs(neighbour, src, vis);
            if(res == true) return true;
        }
     }
     // if cycle is not detected then return false
        return false;
}


bool has_cycle(){
    unordered_set<int> vis;
    bool result = false;
    for(int i = 0; i<v; i++){
        if(!vis.count(i)){
            result = dfs(i, -1, vis);
            if(result == true) return true;
        }
    }
    return false;
}

void display(){
    for(int i = 0; i<graph.size(); i++){
        cout<<i<<"->";
        for(auto el: graph[i]){
            cout<<el<<",";
        }
        cout<<"\n";
    }
}
int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, list<int>());
    while(e--){
        int x,y;
        cin>>x>>y;
        add_edge(x,y);
    }
    display();

    bool b = has_cycle();
    cout<<b<<"\n";
}