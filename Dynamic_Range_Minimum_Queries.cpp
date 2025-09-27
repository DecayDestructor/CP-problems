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
#define int long long

struct SegmentTree {
    int n;
    vi tree;
    SegmentTree(vi &a) {
        n = a.size();
        tree.resize(2 * n);
        for (int i = 0; i < n; i++) {
            tree[i + n] = a[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
        }
    }
    int query(int l, int r) {  //[l,r]
        l = l + n;
        r = r + n;
        int res = LLONG_MAX;
        while (l <= r) {
            if (l % 2) {
                res = min(res, tree[l++]);
            }
            if (r % 2 == 0) {
                res = min(res, tree[r--]);
            }
            l = l / 2;
            r = r / 2;
        }
        return res;
    }
    void modify(int p, int val) {
        p = p + n;
        tree[p] = val;
        p /= 2;
        while (p >= 1) {
            tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
            p = p / 2;
        }
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for (auto &it : arr) cin >> it;
    SegmentTree ST(arr);
    while (q--) {
        int q1, u, v;
        cin >> q1 >> u >> v;
        if (q1 == 1) {
            ST.modify(u - 1, v);
        } else {
            cout << ST.query(u - 1, v - 1) << nl;
        }
    }
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