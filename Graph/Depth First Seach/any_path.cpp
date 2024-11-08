#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;  // hear the list used to store the address of the number
unordered_set<int> visited;
int v; 

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

bool dfs(int curr, int end){
    if(curr == end) return true; 
    visited.insert(curr); // mark visited 
    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){  // if visited count equal to 0 means not visited and if count is 1 then visited h
            bool result = dfs(neighbour, end);
            if(result) return true; // means if the explored neighbour also not visited then return true
        }
    }
    return false; // when we didn't get any path then we return false
}

bool anyPath(int src, int dest){
    return dfs(src, dest);
    
}

int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;
    visited.clear();
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }
    int x, y;  // this is the input for two node for which we are calculating the distance
    cin>>x>>y;
    cout<<anyPath(x,y)<<"\n";

}