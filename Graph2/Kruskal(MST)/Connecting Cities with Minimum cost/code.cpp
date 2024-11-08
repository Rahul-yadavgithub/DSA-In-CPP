// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;

// class Solution {
//     public:

//     int find(vector<int>& parent, int x){
//         return parent[x] = (parent[x] == x)? x : find(parent, parent[x]);
//     }

//     void Union(vector<int>& parent, vector<int>& task, int a, int b){
//         a = find(parent, a);
//         b = find(parent, b);

//         if(a == b) return ;

//         if(task[a]>= task[b]){
//             task[a]++;
//             parent[b]= a;
//         }
//         else{
//             task[b]++;
//             parent[a] = b;
//         }
//     }

//     int connected_component(vector<int>&parent, int n){
//         int size = 0;
//         for(int i =0; i<n; i++){
//             if(parent[i] != parent[i+1]){
//                 size++;
//             } 
//         }
//         return size;
//     }
//     class Edge{
//         public:
//         int src;
//         int dest;
//         int wt;
//     };

//    bool cmp(Edge e1, Edge e2){
//     return e1.wt< e2.wt;
//    }

//     ll kruskals(vector<Edge>& input , int n, int e){

//         sort(input.begin(), input.end(), cmp);
//         vector<int> parent(n+1);
//         vector<int> task(n+1, 1);

//         for(int i = 0; i<= n; i++){
//             parent[i] = i;
//         }
//         ll countEdge = 0; 
//         int i = 0;
//         ll ans = 0;
//         while(countEdge< n-1 && i< input.size()){
//             Edge curr = input[i];
//             int  srcPar = find(parent, curr.src);
//             int destPar = find(parent, curr.dest);

//             if(srcPar != destPar){
//                 Union(parent, task, srcPar, destPar);
//                 countEdge++;
//                 ans += curr.wt;
//             } 
//             i++;
//         }
//         int cc = connected_component(parent, n);
//         if(cc !=1) return -1;
//         return ans;
//     }
//     int minimumCost(int n, vector<vector<int>>& connections){
//         int m = connections.size();
//         vector<Edge> input(m);
//         for(int i= 0; i<m; i++){
//             input[i].src = connections[i][0];
//             input[i].dest = connections[i][1];
//             input[i].wt = connections[i][2];
//         }
//         cout<<kruskals(input, n, m)<<"\n";
//     }
// };
// int main(){

//     int n;
//     cin>> n;
//     int e;
//     cin>>e;
//     vector<vector<int>> connection(e);
//     for(int i = 0; i<e; i++){
//         for(int j = 0; j<3; j++){
//             int x;
//             cin>>x;
//             connection[i][j] = x;
//         }
//     }

//     Solution res;
//     cout<<res.minimumCost(n, connection);
// }




#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
    public:
    
    int find(vector<int>& parent, int x) {
        return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
    }

    void Union(vector<int>& parent, vector<int>& task, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (a == b) return;

        if (task[a] >= task[b]) {
            task[a]++;
            parent[b] = a;
        } else {
            task[b]++;
            parent[a] = b;
        }
    }

    class Edge {
        public:
        int src;
        int dest;
        int wt;
    };

    // Kruskal's algorithm implementation
    ll kruskals(vector<Edge>& input, int n, int e) {
        // Use a lambda function for sorting
        sort(input.begin(), input.end(), [](Edge e1, Edge e2) {
            return e1.wt < e2.wt;
        });

        vector<int> parent(n+1);
        vector<int> task(n+1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        ll countEdge = 0;
        ll ans = 0;
        int i = 0;

        // Kruskal's algorithm loop
        while (countEdge < n - 1 && i < e) {
            Edge curr = input[i];
            int srcParent = find(parent, curr.src);
            int destParent = find(parent, curr.dest);

            if (srcParent != destParent) {
                ans += curr.wt;
                countEdge++;
                Union(parent, task, srcParent, destParent);
            }
            i++;
        }

        return (countEdge == n - 1) ? ans : -1; // Return -1 if no MST exists
    }
};

int main() {
    Solution sol;
    int n, e;
    cin >> n >> e;  // Number of vertices and edges

    vector<Solution::Edge> edges(e);
    for (int i = 0; i < e; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].wt;
    }

    cout << sol.kruskals(edges, n, e) << endl;

    return 0;
}
