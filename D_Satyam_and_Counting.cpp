#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(n) for (int i = 0; i < n; i++)
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<char> vch;
template <typename T1, typename T2>
using vpp = vector<pair<T1, T2>>;
// Template functions for input and output
template <typename T>
void inputArray(vector<T> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

template <typename T>
void outputArray(vector<T> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << nl;
    }
}
template <typename T>
vector<T> factorization(int n) {
    vector<T> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}
void solve() {
    ll n, answer = 0;
    cin >> n;

    map<pair<ll, ll>, ll> m;
    vector<ll> cnt(2);

    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        m[{x, y}]++;
        cnt[y]++;
    }

    for (auto it : m) {
        ll x = it.first.first;
        ll y = it.first.second;

        if (m.count({x, 1 - y})) {
            answer += cnt[y] - 1;
        }
        if (m.count({x + 1, 1 - y}) && m.count({x - 1, 1 - y}))
            answer++;
    }

    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}