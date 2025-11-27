#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int n;

pair<int, int> bfs(int start) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int node = start;
    for (int i = 1; i <= n; i++)
        if (dist[i] > dist[node])
            node = i;

    return {node, dist[node]};  // (farthest node, distance)
}

vector<int> bfs_dist(int start) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    cin >> n;
    g.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 1. Find A
    auto A = bfs(1).first;

    // 2. From A, get distA and B
    vector<int> distA = bfs_dist(A);
    int B = 1;
    for (int i = 1; i <= n; i++)
        if (distA[i] > distA[B]) B = i;

    // 3. From B, get distB
    vector<int> distB = bfs_dist(B);

    // 4. Answer for each node = max(distA, distB)
    for (int i = 1; i <= n; i++)
        cout << max(distA[i], distB[i]) << " ";
}
