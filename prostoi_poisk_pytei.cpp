#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<vector<int>> g;
vector<int> parent;
vector<bool> used;
bool found = false;
int finish;
 
void dfs(int v) {
    used[v] = true;
 
    if (v == finish) {
        found = true;
        return;
    }
 
    for (int to : g[v]) {
        if (!used[to]) {
            parent[to] = v;
            dfs(to);
 
            if (found)
                return;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, start;
    cin >> n >> m >> start >> finish;
 
    g.resize(n + 1);
    parent.assign(n + 1, -1);
    used.assign(n + 1, false);
 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dfs(start);
 
    if (!used[finish]) {
        cout << -1;
        return 0;
    }
 
    vector<int> path;
 
    for (int v = finish; v != -1; v = parent[v])
        path.push_back(v);
 
    reverse(path.begin(), path.end());
 
    for (int v : path)
        cout << v << " ";
 
    return 0;
}
