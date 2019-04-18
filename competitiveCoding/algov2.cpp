#include<bits/stdc++.h>
using namespace std;

// ======================= Dijkstra ==================

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj(10e5);

void dijkstra(int s, vector<int> & d, vector<int> & p) {

  // d stores the distance of various vertex form the source vertex
  //  ********************input method*************************
    // adj[a-1].eb(make_pair(b-1,c));
    // adj[b-1].eb(make_pair(a-1,c));
    

    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {

              int v = -1;
              //  find the minimun vertex
              for (int j = 0; j < n; j++) {
                  if (!u[j] && (v == -1 || d[j] < d[v]))
                      v = j;
              }
               // initially for the source node
              if (d[v] == INF)
                  break;

              u[v] = true;

              //  actual updation of vertex
              
              for (auto edge : adj[v]) {
                  int to = edge.first;
                  int len = edge.second;

                  if (d[v] + len < d[to]) {
                      d[to] = d[v] + len;
                      p[to] = v;
                      
                  }
              }
    }        
  }




vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    if (p[t]==-1) return path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

// =============================================