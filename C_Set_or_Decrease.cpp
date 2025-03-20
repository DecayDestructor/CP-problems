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

const ll INF = 1e18;

ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }

bool RSORT(ll a, ll b) { return a > b; }

ll accurateFloor(ll a, ll b) {
    ll val = a / b;
    while (val * b > a) val--;
    return val;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vi a(n);
    loop(0, n) cin >> a[i];

    sort(all(a));
    vll pSum(n + 1, 0);
    loop(0, n) pSum[i + 1] = pSum[i] + a[i];

    ll ans = INF;
    loop(0, n) {
        ll x = a[0] - accurateFloor(k - pSum[n - i] + a[0], i + 1);
        ans = min(ans, i + max(0LL, x));
    }
    print(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
