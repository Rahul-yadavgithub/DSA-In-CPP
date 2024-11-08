
   /*
   Step by step explanation
   Data Stucture which are used in this case 
   1-> visited Set,  priority queue, unordered_map

   step for what to do 
   -> insert the pair of < -1, src > in the priority queue
   -> one by one remove the root element of the priority queue
   -> if the root element is already visited ,then we will just continue
   -> if not visited already then mark root visited 
   -> we store the wt of the pair in the ans
   -> update the mapping on the basis of weight 
   -> go to every neighbour of the curr element and only add those which are non visited and have better a wight proposition 
   */

  #include<bits/stdc++.h>
  #define ll long long int
  #define pp pair<int, int>
  using namespace std;

  vector<list<pp>> graph;

  void addEdge(int src, int dest, int wt,bool bidir = true){
    graph[src].push_back({dest, wt});
    if(bidir){
        graph[dest].push_back({src, wt});
    }
  }

  ll prims(int src, int n){  
    priority_queue<pp, vector<pp>, greater<pp>> pq;  // in the priority queue first element is weight and the second element is the node
    unordered_set<int> vis;
    vector<int> par(n+1);
    unordered_map<int, int> mp; // map store the the weight and the neighbour node 

    for(int i = 1; i<=n; i++){
        mp[i] = INT_MAX;
    }
    pq.push({0, src});
    mp[src] = 0;
    int total_count = 0; // in any tree their is maximum n-1 edge
    int result = 0;
    while(total_count< n && !pq.empty()){ 
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        total_count++;
        result += curr.first;
        pq.pop();
        for(auto neighbour : graph[curr.second]){
            // go each and every node of the graph neighbour 
            if(!vis.count(neighbour.first) and mp[neighbour.first]> neighbour.second){
                /* 
                 Now hear neighbour defined on the context of graph
                 1-> neighbour.first mean => graph  ka pahla element jo ki node hai 
                 2-> neighbour.second mean => graph ka second element jo ki do node ke beech ka weight batata hai 
                 mp[neighbour.first] means neighbour.first is a key which is act like a node and and for that key assinged value is node weight 

                 mp[neighbour.first] ko isliye compair kar rhe hai kuiki current jis node par hai usse pahle ho sakta hai hamne us vali node ko visited kar liya ho jiski weigh abhi ki weight se jyada ho to usko update karne ke liye ye kiye hai
                 
                */
                pq.push({neighbour.second, neighbour.first});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return result;
  }
  int main(){
    int n, e; // n-> no of vertex and e no of edges in the graph
    cin>>n>>e;
    graph.resize(n+1, list<pp>());
    while(e--){
        int s, d, wt;
        cin>>s>>d>>wt;
        addEdge(s,d, wt);
    }

    int src;
    cin>>src;

    cout<<prims(src, n);

  }