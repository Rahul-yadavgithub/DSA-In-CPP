#include<iostream>
#include<vector>
#include<list>    // list is used for storing the doubley linkedlist
using namespace std;

vector<list<int> >graph;
int v; // no of vertices
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src); // means if the graph is undirectionl then this condition also hit
    }

}
void display(){
    for(int i =0; i< graph.size(); i++){
        cout<<i<<"->";
        for(auto el : graph[i]){
            cout<<el<<" , ";
        }
        cout<<"\n";

    }
}

int main(){
    cin>> v;
   graph.resize(v, list<int>());

   int e; // this is the no of edge 
   cin>>e;
   while(e--){
    int s, d;
    cin>>s>>d;
    add_edge(s, d);
   }

   display();

    return 0;

}