#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
unordered_set<int> vis;
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

bool bfs(int src){
    vector<int> parent(v, -1);
    queue<int> q;
    q.push(src);
    vis.insert(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour: graph[curr]){
            if(vis.count(neighbour) && parent[curr] != neighbour){  
            // parent[curr] != neighbour mean neighbour ka parnet curr val element nhi hai 
               return true;
            }
            if(!vis.count(neighbour)){
                q.push(neighbour);
                vis.insert(neighbour);
                parent[neighbour] = curr;  // matlab neighbour ka  parent ab curr and 
            }
        }
    }
    return false;
}

bool has_cycle(){
    for(int i = 0; i<v; i++){
        if(!vis.count(i)){
           bool res = bfs(i);
           if(res == true) return true;
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
        int x, y;
        cin>>x>>y;
        add_edge(x,y, false);
    }

    display();
    bool b = has_cycle();
    cout<<b<<"\n";


}