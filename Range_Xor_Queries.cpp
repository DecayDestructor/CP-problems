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
    int n;  // actual array size            // tree storage
    vi t;

    // Constructor - initializes with array
    SegmentTree(vector<int>& a) {
        n = a.size();
        t.resize(2 * n);
        build(a);
    }

    // Constructor - initializes with size (all zeros)
    SegmentTree(int size) {
        n = size;
        t.assign(2 * n, 0);
    }

    // Build the segment tree from array
    void build(vector<int>& a) {
        // Assign leaves
        for (int i = 0; i < n; i++) t[i + n] = a[i];

        // Build internal nodes
        for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] ^ t[i << 1 | 1];
    }

    // Modify value at position p to 'value'
    void modify(int p, int value) {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = t[p] ^ t[p ^ 1];
    }

    // Query sum on interval [l, r]
    int query(int l, int r) {  // sum on [l, r]
        int res = 0;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res ^= t[l++];     // l is a right child
            if (!(r & 1)) res ^= t[r--];  // r is a left child
        }
        return res;
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for (auto& it : arr) cin >> it;
    SegmentTree ST(arr);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << ST.query(a - 1, b - 1) << nl;
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