#include<bits/stdc++.h>

using namespace std;

vector<list<int>> graph;
int v;

// Function to add an edge to the graph
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

// Function to display the graph
void display() {
    for (int i = 1; i <= graph.size(); i++) { // Start from 1
        cout << i << " -> ";
        for (auto el : graph[i]) {
            cout << el << " ";
        }
        cout << "\n";
    }
}

// Function to check if a number is prime
bool prime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false; // Found a divisor
        }
    }
    return true; // No divisors found, it's a prime
}

// Function to find prime edges in the graph
void prim_circle() {
    vector<pair<int, int>> prime_edges;

    for (int i = 1; i <= graph.size(); i++) { // Start from 1
        for (auto el : graph[i]) {
            // Ensure each edge is only counted once and check if the sum is prime
            if (i < el && prime(i + el)) {
                prime_edges.push_back({i, el});
            }
        }
    }

    // Display the prime edges
    cout << "Prime edges with prime sums:\n";
    if (prime_edges.empty()) {
        cout << "No prime edges found.\n";
    } else {
        for (auto edge : prime_edges) {
            cout << "(" << edge.first << ", " << edge.second << ")\n";
        }
    }
}

int main() {
    cin >> v;
     graph.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int x, y;
        cin>>x>>y;
        add_edge(x,y);
    }
    display();

}
