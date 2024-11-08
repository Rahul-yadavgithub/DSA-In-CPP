#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v; // vertex

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

// write a code to make a topological sorting

void TopoBFS(){

    // using Kahn's algorithm
    
    vector<int> indegree(v, 0);
    for(int i= 0; i<v; i++){
        // go every vertex and see that they are connected to any one or not 
        for(auto neighbour: graph[i]){
            // we connect neighbour to the previous one means making dependency between them
            indegree[neighbour]++;
        }  
    }
    queue<int>q;
    unordered_set<int> visited;
    for(int i = 0; i<v; i++){
        // visited every element of the indegree vector 
        if(indegree[i] == 0){
            // means their is no incomming node present in this case
            // so push it in the queue because that node has no indepencency in this case
            q.push(i);
            visited.insert(i); // marks that node a visited 
        }
    }

    // now we go to each and every element of the queue and process them 

    while(!q.empty()){
        auto node = q.front();
        cout<<node<<" ";
        q.pop();
        // go to the neighbour of the node and decrease their dependency by 1

        for(auto neighbour: graph[node]){
            // check that neighbour frist that does they are visited or not if not then proceed for further 
            if(not visited.count(neighbour)){
                indegree[neighbour]--;

                if(indegree[neighbour] == 0){
                    // if indegree of that node is 0 means we can push them in the queue because dependency not exist
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}

int main(){
    cin>>v;
    int e;
    cin>>e; 
    graph.resize(v, list<int>());
    while(e--){
        int s;
        int d;
        cin>>s>>d;
        add_edge(s,d, false);// we pass the false in the add function because we need to make directed graph
    }

    TopoBFS(); 

}


