#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Dijkstra {
private:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list (vertex, weight)
    vector<int> dist; // Stores minimum distances from the source node
    int INF = numeric_limits<int>::max();

public:
    int getMaxLimit(){
        return INF;
    }

    Dijkstra(int vertices) : V(vertices) {
        adj.resize(V);
        dist.resize(V, INF);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // For an undirected graph
    }

    void dijkstra(int start) {
        dist[start] = 0;
        vector<int> parent(V, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int getMinDistance(int source, int target) {
        return dist[target];
    }

    vector<vector<int>> getShortestPaths(int start, const vector<int>& parent) {
        vector<vector<int>> paths(V);

        for (int i = 0; i < V; ++i) {
            if (i == start)
                continue;

            vector<int> path;
            int current = i;

            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }

            reverse(path.begin(), path.end());
            paths[i] = path;
        }

        return paths;
    }

    void printPath(int start, int v, const vector<int>& parent) {
        if (v == start) {
            cout << v;
            return;
        }

        printPath(start, parent[v], parent);
        cout << " -> " << v;
    }
};

int main() {
    int V, E; // Number of vertices and edges
    // cout << "Enter the number of vertices: ";
    cin >> V>>E;
    // cout << "Enter the number of edges: ";
    // cin >> E;

    Dijkstra graph(V);

    // cout << "Enter edges (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // cout<<u<<v<<w<<"\n";
        graph.addEdge(u, v, w);
    }

    int startVertex;
    // cout << "Enter the starting vertex: ";
    cin >> startVertex;
    // cout<<"startVertex: "<<startVertex<<'\n';

    graph.dijkstra(startVertex);

    int targetVertex;
    cout << "Enter the target vertex to find minimum distance: ";
    cin >> targetVertex;
    // cout<<"target Vertex: "<<targetVertex<<'\n';

    int minDistance = graph.getMinDistance(startVertex, targetVertex);

    if (minDistance == graph.getMaxLimit()) {
        cout << "No path exists from " << startVertex << " to " << targetVertex << endl;
    } else {
        cout << "Minimum distance from " << startVertex << " to " << targetVertex << " is: " << minDistance << endl;
    }

    return 0;
}
