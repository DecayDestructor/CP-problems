#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, ll>> edges;
    vector<vector<int>> adj(n + 1), rev(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        w *= -1;  // Negate weights to find longest path using shortest path logic
        edges.push_back({u, v, w});
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    // Step 1: Mark reachable nodes from 1 and to n (reverse graph)
    vector<bool> from1(n + 1, false), toN(n + 1, false);

    function<void(int, vector<vector<int>> &, vector<bool> &)> dfs = [&](int u, vector<vector<int>> &graph, vector<bool> &vis) {
        vis[u] = true;
        for (int v : graph[u])
            if (!vis[v]) dfs(v, graph, vis);
    };

    dfs(1, adj, from1);
    dfs(n, rev, toN);

    // Step 2: Bellman-Ford
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n; ++i) {
        for (auto edge : edges) {
            int u, v;
            ll w;
            tie(u, v, w) = edge;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                // Step 3: If updated on the n-th iteration and on path from 1 to n → infinite score
                if (i == n && from1[u] && toN[v]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << -dist[n] << endl;  // Negate back to get the original longest path
    return 0;
}
