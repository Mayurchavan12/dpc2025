#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    unordered_map<int, vector<int>> adj;

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    bool hasCycleUtil(int node, int parent, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (hasCycleUtil(neighbor, node, visited))
                    return true;
            } else if (neighbor != parent) {
                return true;  
            }
        }

        return false;
    }

    bool hasCycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (hasCycleUtil(i, -1, visited))
                    return true;
            }
        }

        return false;
    }
};

bool containsCycle(int V, const vector<vector<int>>& edges) {
    Graph g(V);

    
    unordered_set<string> seenEdges;

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];

        string key = u < v ? to_string(u) + "," + to_string(v) : to_string(v) + "," + to_string(u);
        if (seenEdges.count(key)) {
            return true;  
        }
        seenEdges.insert(key);

        g.addEdge(u, v);
    }

    return g.hasCycle();
}


int main() {
    
    vector<vector<int>> edges;
    
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    int E;
    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v) one per line:\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    if (containsCycle(V, edges))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
