#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
const long long INF = 4e18;
 
struct Edge {
    int to;
    long long w;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<Edge>> g(n + 1);
 
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
 
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
 
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;
 
    dist[1] = 0;
    pq.push({0, 1});
 
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
 
        long long d = cur.first;
        int v = cur.second;
 
        if (d != dist[v])
            continue;
 
        for (auto e : g[v]) {
            if (dist[v] + e.w < dist[e.to]) {
                dist[e.to] = dist[v] + e.w;
                parent[e.to] = v;
                pq.push({dist[e.to], e.to});
            }
        }
    }
 
    if (dist[n] == INF) {
        cout << -1;
        return 0;
    }
 
    vector<int> path;
 
    for (int v = n; v != -1; v = parent[v])
        path.push_back(v);
 
    reverse(path.begin(), path.end());
 
    for (int v : path)
        cout << v << " ";
 
    return 0;
}
