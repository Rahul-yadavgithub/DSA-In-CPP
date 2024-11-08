#include<iostream>
#include<vector>
#include<unordered_set>
#include<list>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

bool dfs(int curr, int end) {
    if (curr == end) {
        cout << curr << " "; // Print destination when reached
        return true;
    }
    visited.insert(curr); // Mark the current node as visited

    for (auto neighbour : graph[curr]) {
        if (not visited.count(neighbour)) {
            if (dfs(neighbour, end)) { // Recursively search
                cout << curr << " "; // Print current node when returning from recursion
                return true; // Return true to propagate the path found
            }
        }
    }
    return false; // No path found from this node
}

int main(){
    cin>>v;
    graph.resize(v, list<int>());
    visited.clear();
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s,d);
    }
    int x,y;
    cin>>x>>y;
    dfs(x,y);

}