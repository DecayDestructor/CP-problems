#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(s, n, inc) for (ll i = s; i < n; i += inc)
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
#define vvi vector<vi>
#define pi pair<int, int>
#define vch vector<char>
template <typename T1, typename T2>
#define int long long
using vpp = vector<pair<T1, T2>>;
map<int, int> dp;  // dp[i] = maximum projects that I can choose such that I am starting from day i
int n;
void solve() {
    cin >> n;
    vector<vi> arr(n, vi(3));
    for (auto &it : arr) {
        cin >> it[0] >> it[1] >> it[2];
    }
    sort(all(arr));
    for (int i = n - 1; i >= 0; i--) {
        int u = arr[i][0];
        int v = arr[i][1];
        int w = arr[i][2];
        auto it = dp.upper_bound(v);
        auto lb = dp.lower_bound(u);  // if we don't pick, we can pick any value from u
        if (lb != dp.end()) {
            int notTake = lb->second;
            dp[u] = notTake;
        }
        if (it == dp.end()) {
            dp[u] = max(dp[u], w);  // I can take this as last day
        } else {
            auto next = *it;
            int take = next.second + w;  // if we pick, we can only pick from atleast v+1
            dp[u] = max(dp[u], take);
        }
    }
    auto beg = *dp.begin();
    cout << beg.second << nl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}