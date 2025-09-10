#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
      vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src){
        vector<int> adj[N];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int dist[N];
        for(int i=0; i<N; i++) dist[i] = 1e9;
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        vector<int> ans(N, -1);
        for(int i=0; i<N; i++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }
        return ans;
      }
};

int main(){
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges;
    cout << "Enter edges (u v) format:" << endl;
    for(int i=0; i<E; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int start, end;
    cout << "Enter start and end nodes: ";
    cin >> start >> end;
    Graph g;
    vector<int> result = g.shortestPath(edges, V, E, start);
    cout << "Shortest path length from " << start << " to " << end << " " << " is: " << result[end] << endl;
    
    
    return 0;
}
