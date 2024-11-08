#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph;
int v; // vertex;

void add_list(int src, int dist, bool bi_dir = true){
    graph[src].push_back(dist);
    if(bi_dir){
        graph[dist].push_back(src);
    }
}

void display(){
    for(int i =0; i<graph.size() ; i++){
        cout<<i<<"->";
        for(auto el: graph[i]){
            cout<<el<<",";
        }
        cout<<"\n";
    }
}
int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e; // taking the input of edge
    while(e--){
        int s,d;
        cin>>s>>d;
        add_list(s, d, false);
    }
    display();  

}