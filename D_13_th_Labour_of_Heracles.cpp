#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(s, n) for (ll i = s; i < n; i++)
#define all(a) a.begin(), a.end()
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vch vector<char>
template <typename T1, typename T2>
#define int long long
using vpp = vector<pair<T1, T2>>;
void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for (auto &it : arr) cin >> it;
    int sum = accumulate(all(arr), 0ll);
    vi deg(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    priority_queue<pair<int, int>> pq;
    for (int it = 1; it <= n; it++) {
        if (deg[it] > 1) {
            pq.push({arr[it - 1], it});
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << sum << " ";
        if (!pq.size()) continue;
        sum += pq.top().first;
        deg[pq.top().second]--;
        if (deg[pq.top().second] <= 1) pq.pop();
    }
    cout << nl;
    return;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}