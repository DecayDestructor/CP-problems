#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    // .first is other node, .second is weight
    vector<pair<int, int>> adj[n + 1];
    vector<ll> pref(n + 1);
    vector<bool> visited(n + 1);

    for (int i = 0; i < m; i++) {
        int l, r, s;
        cin >> l >> r >> s;
        // p[r] - p[l - 1] = s
        adj[l - 1].push_back({r, s});
        adj[r].push_back({l - 1, -s});
    }

    bool valid = true;
    function<void(int)> dfs = [&](int s) -> void {
        if (visited[s]) {
            return;
        }
        visited[s] = true;

        for (const pair<int, int>& u : adj[s]) {
            int v = u.first;
            ll val = pref[s] + u.second;

            if (!visited[v]) {
                pref[v] = val;
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (pref[v] != val) {
                valid = false;
                return;
            }
        }
    };

    for (int i = 0; i <= n; i++) {
        if (visited[i]) {
            continue;
        }
        pref[i] = 0;
        dfs(i);
        if (!valid) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << pref[i] - pref[i - 1] << ' ';
    }
}